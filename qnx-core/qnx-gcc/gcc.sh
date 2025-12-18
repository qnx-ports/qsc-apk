# /etc/profile.d/gcc.sh
export QNX_HOST="/"
export QNX_TARGET="/"
export CFLAGS="$CFLAGS -I/usr/include -D_QNX_SOURCE --sysroot=/"
export CXXFLAGS="$CXXFLAGS -D_QNX_SOURCE"
export LDFLAGS="$LDFLAGS -L/usr/lib -shared-libgcc"
