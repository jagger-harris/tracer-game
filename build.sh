#!/bin/bash

# Custom CMake build script for Bash
# Jagger Harris

# Commands: ./build.sh build, ./build.sh build run

if [[ $1 ]]
then
  if [[ "$1" == "build" ]]
  then
    rm -rf build
    mkdir build
    cd build
    cmake -D CMAKE_C_COMPILER=clang ..
    make
    if [[ "$2" == "run" ]]
    then
      cd build
      ./compiled_program
    fi
    exit 0
  else
    echo "Commands: build, build run"
    exit 1
  fi
else
  echo "Usage: ./build.sh command1 command2"
  exit 1
fi
