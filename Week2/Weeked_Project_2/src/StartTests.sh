#!/bin/bash

make test > /dev/null

./tests

make clean > /dev/null
