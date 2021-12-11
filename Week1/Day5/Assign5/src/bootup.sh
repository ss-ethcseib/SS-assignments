#!/bin/bash

make > /dev/null

./MatrixMultiplication $1 $2 $1 $2

make clean > /dev/null
