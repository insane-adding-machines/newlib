#!/bin/bash
rm -f build
mkdir -p build
cd build
mkdir -p lib
../configure --prefix=`pwd`/lib --target=arm-none-eabi --disable-multilib --disable-newlib-supplied-syscalls CFLAGS_FOR_TARGET="-g -O2 -fPIC -mword-relocations -mlong-calls -fno-common -msingle-pic-base -mpic-register=r9 -mno-pic-data-is-text-relative"
make CFLAGS_FOR_TARGET="-g -O2 -fPIC -mword-relocations -mlong-calls -fno-common -msingle-pic-base -mpic-register=r9 -mno-pic-data-is-text-relative"
make install
