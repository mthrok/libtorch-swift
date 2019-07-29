FROM BASE_IMAGE as builder

RUN apt -qq update && apt -qq install -y git cmake g++ python3 python3-distutils python3-pip

RUN git clone --recursive https://github.com/pytorch/pytorch /src
WORKDIR /src
ARG MAX_JOBS=4
RUN pip3 install pyyaml && python3 tools/build_libtorch.py

FROM scratch
COPY --from=builder /src/torch/include /src/include
COPY --from=builder /src/torch/lib /src/lib
