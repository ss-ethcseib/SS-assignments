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

COPY src/* src/
#CMD["source", "/.bashrc"]
WORKDIR src/

#Set up a standard ".profile" or ".bashrc" that is included with your Dockerfile, so you have a standardized environment. Upon starting the docker container, your profile should be automatically sourced.
