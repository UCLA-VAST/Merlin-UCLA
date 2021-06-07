// WARNING: Changes to this file must be contributed back to Sawyer or else they will
//          be clobbered by the next update from Sawyer.  The Sawyer repository is at
//          https://github.com/matzke1/sawyer.




#ifndef Sawyer_Exception_H
#define Sawyer_Exception_H

#include <Sawyer/Sawyer.h>

namespace Sawyer {
namespace Exception {

/** Base class for %Sawyer runtime errors. */
class SAWYER_EXPORT RuntimeError: public std::runtime_error {
public:
    ~RuntimeError() throw() {}

    /** Constructor taking a description of the error. */
    explicit RuntimeError(const std::string &mesg)
        : std::runtime_error(mesg) {}
};

/** Base class for %Sawyer domain errors. */
class SAWYER_EXPORT DomainError: public RuntimeError {
public:
    ~DomainError() throw() {}

    /** Constructor taking a description of the error. */
    explicit DomainError(const std::string &mesg)
        : RuntimeError(mesg) {}
};

/** Error for non-existing values.
 *
 *  This error is thrown when querying a container and no value is stored for the specified key. */
class SAWYER_EXPORT NotFound: public DomainError {
public:
    ~NotFound() throw () {}

    /** Constructor taking a description of the error. */
    explicit NotFound(const std::string &mesg)
        : DomainError(mesg) {}
};

/** Error for existing values.
 *
 *  This error is thrown when attempting to modify a container by inserting a value that already exists. */
class SAWYER_EXPORT AlreadyExists: public DomainError {
public:
    ~AlreadyExists() throw () {}

    /** Constructor taking a description of the error. */
    AlreadyExists(const std::string &mesg)
        : DomainError(mesg) {}
};

/** Error when a cycle is detected.
 *
 *  This error is thrown by algorithms that operate only on acyclic data structures if the data structure on which they're
 *  invoked contains a cycle. */
class SAWYER_EXPORT ContainsCycle: public DomainError {
public:
    ~ContainsCycle() throw () {}

    /** Constructor taking a description of the error. */
    ContainsCycle(const std::string &mesg)
        : DomainError(mesg) {}
};

/** Error related to the file system.
 *
 *  These errors are thrown for things like file-not-found, etc. */
class SAWYER_EXPORT FilesystemError: public RuntimeError {
public:
    ~FilesystemError() throw () {}

    /** Constructor taking a description of the error. */
    FilesystemError(const std::string &mesg)
        : RuntimeError(mesg) {}
};

/** Error in parsing something. */
class SAWYER_EXPORT SyntaxError: public RuntimeError {
public:
    ~SyntaxError() throw () {
    }

    /** Constructor taking a description of the error. */
    SyntaxError(const std::string &mesg)
        : RuntimeError(mesg) {}
};


} // namespace
} // namespace

#endif
