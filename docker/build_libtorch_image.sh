#!/usr/bin/env bash

set -euox pipefail

if [ $# -lt 2 ]; then
    printf "<Usage> %s <BASE_UBUNTU_IMAGE> <BUILD_IMAGE>" "$0"
    exit 1
fi

base_image="$1"
image="$2"
max_jobs="${3:-4}"

this_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
dockerfile="${this_dir}/libtorch/Dockerfile"
docker build \
       --build-arg MAX_JOBS="${max_jobs}" \
       --squash -t "${image}" \
       -  < <(sed "s/BASE_IMAGE/${base_image}/g" "${dockerfile}")
