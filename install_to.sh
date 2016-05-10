#!/bin/bash

if [ "x$1" = "x" ]; then
    TOOLCHAIN="/opt/toolchains/arm-frosted-eabi"
else
    TOOLCHAIN=$1
fi

cp -av build/lib/arm-frosted-eabi/include/* $TOOLCHAIN/arm-frosted-eabi/include/
cp build/lib/arm-frosted-eabi/lib/* $TOOLCHAIN/arm-frosted-eabi/lib/

