#######################################
# Merlin
#######################################
export MERLIN_COMPILER_HOME=/opt/merlin/sources/merlin-compiler/trunk

export MERLIN_PATH=$MERLIN_COMPILER_HOME/source-opt/lib/
export llvm_path=$MERLIN_PATH/llvm6.0.0
export deps_path=$MERLIN_PATH/
export clang_path=$llvm_path/
export rose_path=$MERLIN_PATH/rose
export rjson_path=$MERLIN_PATH/rapidjson
export gcc_path=$MERLIN_PATH/gcc4.9.4
export boost_path=$MERLIN_PATH/boost1.67.0

export MERLIN_DEPS=$deps_path
export LLVM_ROOT_DIR=$llvm_path
export CLANG_ROOT_DIR=$clang_path
export ROSE_ROOT_DIR=$rose_path
export RAPIDJSON_ROOT_DIR=$rjson_path
export GCC_ROOT_DIR=$MERLIN_PATH/gcc4.9.4
export BOOST_ROOT=$boost_path

export LLVM_ROOT_DIR=/opt/merlin/llvm6-install
export CLANG_ROOT_DIR=/opt/merlin/llvm6-install
export ROSE_ROOT_DIR=/opt/rose/default/install
## For polyopt install.
export ROSE_ROOT="$ROSE_ROOT_DIR";
export GCC_ROOT_DIR=/usr
export BOOST_ROOT=$ROSE_ROOT_DIR
export PATH=$gcc_path/bin/:$PATH
export PATH=$llvm_path/bin/:$PATH

#lib32 if lib64 is not available
export LD_LIBRARY_PATH=$gcc_path/lib64:$BOOST_ROOT/lib:$LD_LIBRARY_PATH

export PATH=$MERLIN_COMPILER_HOME/build/bin:$PATH


