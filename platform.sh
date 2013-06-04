platform=`uname`

export HERE=`pwd`
if [ -z "`find $HERE/nacl-* -name "libnacl.a"`" ]; then
    echo '"redo nacl" first!' 1>&2;
    exit 1;
fi

export NACL_LIB=$(dirname `find $HERE/nacl-* -name "libnacl.a"`)
export NACL_INC=$(dirname `find $HERE/nacl-* -name crypto_box.h`)

EXTRA_LDFLAGS=""

if [ -z "$CC" ]; then
    export CC="gcc";
fi
if test $platform == "Darwin"; then 
    echo " ---> Configured for Darwin">&2;
    EXTRA_LDFLAGS="-framework CoreServices -framework CoreFoundation $EXTRA_LDFLAGS"
elif test $platform == "Linux"; then
    echo " ---> Configured for Linux">&2;
    EXTRA_LDFLAGS="$NACL_LIB/libnacl.a $NACL_LIB/randombytes.o $NACL_LIB/cpucycles.o"
fi
export EXTRA_LDFLAGS

echo "-I$HERE/src -I$NACL_INC" > NITRO_CFLAGS
echo "-L$HERE -lnitro -lev -lpthread $EXTRA_LDFLAGS" > NITRO_LDFLAGS

if [ -a "/proc/cpuinfo" ]; then
    CORES=`grep '^processor' /proc/cpuinfo | wc -l`
    echo " ...  Building with $CORES cores..." 1>&2
    REDO_CMD="redo -j $CORES"
else
    REDO_CMD="redo"
fi
