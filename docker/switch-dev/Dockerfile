FROM SOURCE_IMAGE as source

FROM BASE_IMAGE
RUN apt -qq update && apt -qq install -y git g++

RUN useradd -ms /bin/bash swift
WORKDIR /home/swift
USER swift

COPY --from=source /src/include /home/swift/pytorch/include
COPY --from=source /src/lib     /home/swift/pytorch/lib
