#!/bin/bash

clear

make > /dev/null

./tests

make clean > /dev/null
