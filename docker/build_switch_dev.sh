#!/usr/bin/env bash

set -euo pipefail

if [ $# -ne 3 ]; then
    printf "<Usage> %s <BASE_IMAGE> <LIBTORCH_IMAGE> <BUILD_IMAGE>\n" "$0"
    exit 1
fi

base_image="$1"
libtorch_image="$2"
image="$3"

this_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
dockerfile="${this_dir}/switch-dev/Dockerfile"
docker build --squash -t "${image}" - \
       < <(sed \
	       -e "s/SOURCE_IMAGE/${libtorch_image}/g" \
	       -e "s/BASE_IMAGE/${base_image}/g" \
	       "${dockerfile}")
