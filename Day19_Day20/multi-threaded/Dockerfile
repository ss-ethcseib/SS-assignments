FROM centos:8

MAINTAINER Ethan Seiber

RUN yum update -y
RUN yum install -y cmake
RUN yum install -y emacs
RUN yum groupinstall -y "Development Tools"
RUN yum install -y git-all
RUN yum install -y zip
RUN yum install -y zip
RUN yum install -y curl
RUN yum install -y epel-release
RUN yum install -y iftop
RUN yum install -y iotop
RUN yum install -y cscope
RUN yum install -y tree
RUN yum install -y clang
RUN yum install -y htop
RUN yum install -y valgrind 
RUN yum --enablerepo=powertools install -y gtest
RUN dnf --enablerepo=powertools install -y gtest-devel
RUN dnf -y install jsoncpp
RUN dnf -y install jsoncpp-devel

COPY src/Day21/* src/Day21/
COPY src/Day22/* src/Day22/

WORKDIR src/