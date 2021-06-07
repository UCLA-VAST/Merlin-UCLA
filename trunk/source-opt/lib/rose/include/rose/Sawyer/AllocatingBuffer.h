// WARNING: Changes to this file must be contributed back to Sawyer or else they will
//          be clobbered by the next update from Sawyer.  The Sawyer repository is at
//          https://github.com/matzke1/sawyer.




#ifndef Sawyer_AllocatingBuffer_H
#define Sawyer_AllocatingBuffer_H

#include <Sawyer/Buffer.h>
#include <Sawyer/Sawyer.h>

#include <boost/lexical_cast.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <cstring>                                      // memcpy
#include <string>

namespace Sawyer {
namespace Container {

/** Allocates memory as needed.
 *
 *  Allocates as many elements as requested and manages the storage.  There is no requirement that the elements be contiguous
 *  in memory, although this implementation does it that way. */
template<class A, class T>
class AllocatingBuffer: public Buffer<A, T> {
public:
    typedef A Address;                                  /**< Type of addresses used to index the stored data. */
    typedef T Value;                                    /**< Type of data that is stored. */
    typedef Buffer<A, T> Super;                         /**< Type of base class. */

private:
    Address size_;
    std::vector<Value> values_;

private:
    friend class boost::serialization::access;

    // Users: You'll need to register the subclass once you know its type, such as
    // BOOST_CLASS_REGISTER(Sawyer::Container::AllocatingBuffer<size_t,uint8_t>);
    template<class S>
    void serialize(S &s, const unsigned /*version*/) {
        s & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Super);
        s & BOOST_SERIALIZATION_NVP(size_);
        s & BOOST_SERIALIZATION_NVP(values_);
    }

protected:
    explicit AllocatingBuffer(Address size = 0): Super(".AllocatingBuffer"), size_(size), values_(size) {}

public:
    /** Allocating constructor.
     *
     *  Allocates a new buffer of the specified size.  The values in the buffer are default-constructed, and deleted when this
     *  buffer is deleted. */
    static typename Buffer<A, T>::Ptr instance(Address size) {
        return typename Buffer<A, T>::Ptr(new AllocatingBuffer(size));
    }

    /** Allocating constructor.
     *
     *  Allocates a new buffer that points to a copy of the specified string. */
    static typename Buffer<A, T>::Ptr instance(const std::string &s) {
        typename Buffer<A, T>::Ptr retval(new AllocatingBuffer(s.size()));
        retval->write(s.c_str(), 0, s.size());
        return retval;
    }
    
    typename Buffer<A, T>::Ptr copy() const /*override*/ {
        typename Buffer<A, T>::Ptr newBuffer = instance(this->size());
        Address nWritten = newBuffer->write(&values_[0], 0, this->size());
        if (nWritten != this->size()) {
            throw std::runtime_error("AllocatingBuffer::copy() failed after copying " +
                                     boost::lexical_cast<std::string>(nWritten) + " of " +
                                     boost::lexical_cast<std::string>(this->size()) +
                                     (1==this->size()?" value":" values"));
        }
        return newBuffer;
    }
    
    Address available(Address start) const /*override*/ {
        return start < size_ ? size_-start : 0;
    }

    void resize(Address newSize) /*override*/ {
        values_.resize(newSize);
    }

    Address read(Value *buf, Address address, Address n) const /*override*/ {
        n = std::min(n, available(address));
        if (buf && n>0)
            memcpy(buf, &values_[address], n*sizeof(values_[0]));
        return n;
    }

    Address write(const Value *buf, Address address, Address n) /*override*/ {
        n = std::min(n, available(address));
        if (buf && n>0)
            memcpy(&values_[address], buf, n*sizeof(values_[0]));
        return n;
    }

    const Value* data() const /*override*/ {
        return size_ > 0 ? &values_[0] : NULL;
    }
};

} // namespace
} // namespace

#endif
