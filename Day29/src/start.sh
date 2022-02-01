#!/bin/bash
clear

clang++ main.cpp -pthread -std=c++2a > /dev/null

rm -r a.out > /dev/null
