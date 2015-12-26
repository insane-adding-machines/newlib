#!/bin/bash
rm -f build
rm -f arm-none-eabi
rm -f arm-frosted
mkdir -p build
cd build
mkdir -p lib

CFLAGS_FOR_TARGET="-g -Os -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -fPIC -mlong-calls -fno-common -msingle-pic-base -mno-pic-data-is-text-relative"
export CFLAGS_FOR_TARGET

CT_TARGET_ALIAS="arm-eabi"
export CT_TARGET_ALIAS

../configure --prefix=`pwd`/lib --target=arm-frosted --enable-newlib-nano-formatted-io --with-mode=thumb --with-cpu=cortex=m3 --disable-multilib --disable-newlib-supplied-syscalls
if [ $? -ne 0 ]; then
    echo Failed to configure newlib
    exit 1
fi

make
if [ $? -ne 0 ]; then
    echo Failed to build newlib
    exit 1
fi

make install
if [ $? -ne 0 ]; then
    echo Failed to install newlib
    exit 1
fi
