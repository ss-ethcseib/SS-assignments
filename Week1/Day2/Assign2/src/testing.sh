#!/bin/bash

make > /dev/null

echo "Test case: User asks for short size" > log.txt
./WorkingWithTypes <<< "short" >> log.txt

echo >> log.txt
echo >> log.txt

echo "Test case: User enters a non-primitive string" >> log.txt
./WorkingWithTypes <<< "Hello" >> log.txt

make clean > /dev/null
