#!/bin/bash

make > /dev/null

./tests

make clean > /dev/null
