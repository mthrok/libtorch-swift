#!/usr/bin/env bash

set -euox pipefail

max_jobs="1"
if [ $# -eq 1 ]; then
    max_jobs="${1}"
fi

base_image="swift:5.0.1"
libtorch_image="libtorch-build"
dev_image="switch-dev"

this_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "${this_dir}"

./build_libtorch_image.sh "${base_image}" "${libtorch_image}" "${max_jobs}"
./build_switch_dev.sh "${base_image}" "${libtorch_image}" "${dev_image}"
