FROM alpine:3.14

ARG TOOLS_PATH=/tools
RUN mkdir ${TOOLS_PATH}
WORKDIR ${TOOLS_PATH}

RUN apk --no-cache add ca-certificates wget make cmake avrdude avr-libc gcc-avr

WORKDIR /build
