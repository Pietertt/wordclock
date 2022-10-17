FROM alpine:3.16.2

ARG TOOLS_PATH=/tools
RUN mkdir ${TOOLS_PATH}
WORKDIR ${TOOLS_PATH}

RUN apk --no-cache add wget make cmake avrdude avr-libc gcc-avr

WORKDIR /app
