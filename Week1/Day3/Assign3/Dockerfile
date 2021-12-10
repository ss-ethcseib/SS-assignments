FROM ubuntu

MAINTAINER Ethan Seiber

RUN apt-get update
RUN apt-get install -y emacs
RUN apt-get install -y build-essential
RUN apt-get install -y libc6-dbg gdb valgrind
RUN apt-get install -y git-all
RUN apt-get install -y zip
RUN apt-get install -y zip
RUN apt-get install -y curl
RUN apt-get install -y htop
RUN apt-get install -y iftop
RUN apt-get install -y iotop
RUN apt-get install -y cscope
RUN apt-get install -y tree
RUN apt-get install -y clang

COPY src/* src/

WORKDIR src/