#!/bin/bash

clear

make > /dev/null

./exec

echo
echo
make clean > /dev/null
