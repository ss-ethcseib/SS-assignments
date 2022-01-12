#!/bin/bash

clear

make > /dev/null

./tests

echo
echo
echo
echo "Beginning interactive-ish program"
echo
echo

./interactive

make clean > /dev/null
