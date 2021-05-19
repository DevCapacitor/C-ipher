#!/bin/bash
echo "+++++++++++++++++++++++++++++++"
echo "++ Build Crypted for Release ++"
echo "++ Script will check cmake   ++"
echo "++ if cmake not found        ++"
echo "++ it will install cmake     ++"
echo "++ with apt on debian        ++"
echo "+++++++++++++++++++++++++++++++"
RELEASE_DIR="./Build/Release"
if [ ! -d "$RELEASE_DIR" ]; then
    mkdir ${RELEASE_DIR}
fi
cd ${RELEASE_DIR}
if [ ! -x "$(command -v cmake)" ]; then
    echo "cmake not found, installing.."
    if [ -x "$(command -v apt)"  ]; then
        if [ -x "$(command -v sudo)"  ]; then
            sudo apt install cmake
        else
            apt install cmake
        fi
    else
        echo "apt command not found"
    fi
else
    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../..
    make
fi

