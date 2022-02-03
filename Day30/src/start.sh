#!/bin/bash

clear

clang++ -std=c++2a -pthread main.cpp

./a.out 
rm -r a.out
