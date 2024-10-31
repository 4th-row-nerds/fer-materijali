FROM golang:bullseye

RUN apt update && apt install -y git
RUN mkdir /