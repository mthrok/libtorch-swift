#!/usr/bin/env bash

set -euo pipefail

# rm -rf .build

LIBTORCH="/home/swift/pytorch"
# C++ include path, either env var or -Xcxx "-I..."
export CPLUS_INCLUDE_PATH="${LIBTORCH}/include:${LIBTORCH}/include/torch/csrc/api/include/"
# For runtime
export LD_LIBRARY_PATH="${LIBTORCH}/lib"

swift test -v -v -v \
      -Xcxx -std=c++11 \
      -Xlinker "-L${LIBTORCH}/lib" \
      -Xlinker -lc10 \
      -Xlinker -ltorch
