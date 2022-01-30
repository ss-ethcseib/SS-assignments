#!/bin/bash

clear

$g_11 -fcoroutines -std=c++2a -g -gdwarf-2 -pthread -Wall main.cpp 

./a.out

make clean > /dev/null
