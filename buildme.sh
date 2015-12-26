#!/bin/bash
rm -rf build/arm-none-eabi
rm -rf build/config*
rm -rf build/etc
rm -rf build/lib
rm -rf build/Makefile
mkdir -p build
cd build
make distclean
mkdir -p lib

CFLAGS_FOR_TARGET="-g -Os -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -fPIC -mlong-calls -fno-common -msingle-pic-base -mno-pic-data-is-text-relative"
export CFLAGS_FOR_TARGET

../configure --prefix=`pwd`/lib --target=arm-none-eabi --disable-multilib --enable-newlib-nano-formatted-io --with-mode=thumb --with-cpu=cortex=m3
if [ $? -ne 0 ]; then
    echo Failed to configure newlib
    exit 1
fi

make
if [ $? -ne 0 ];
then
    echo Failed to build newlib
    exit 1
fi

make install
if [ $? -ne 0 ];
then
    echo Failed to install newlib
    exit 1
fi
