#!/usr/bin/env bash

set -euo pipefail

dev_image="switch-dev"
if [ $# -eq 1 ]; then
    dev_image="${1}"
fi

dir="$(git rev-parse --show-toplevel)"
name="switch-dev"
docker run -d --name="${name}" -v "${dir}:${dir}" -w="${dir}" "${dev_image}" sleep infinity
docker exec -it "${name}" bash
