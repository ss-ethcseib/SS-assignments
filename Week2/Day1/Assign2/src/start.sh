#!/bin/bash

make > /dev/null

./program

make clean > /dev/null

echo 
echo
echo "Error was expected. This demonstrates what happens when we try to do what was asked of us in the assignment."
