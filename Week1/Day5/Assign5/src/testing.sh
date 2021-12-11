#!/bin/bash

make > /dev/null
rm -r log.txt > /dev/null

echo "Test case: User provides all 0's for matrix dimensions" >> ./log.txt
./MatrixMultiplication 0 0 0 0 &>> log.txt

echo >> log.txt
echo >> log.txt
echo "Test case: User provides negative numbers as matrix dimensions" >> log.txt
./MatrixMultiplication -1 -2 4 0 &>> log.txt

echo >> log.txt
echo >> log.txt
echo "Test case: User only provides partial dimensions" >> log.txt
./MatrixMultiplication 1 2 &>> log.txt

echo >> log.txt
echo >> log.txt
echo "This is apart of the log.txt file. User provided command line dimensions failed the dimensionality checks."
echo "Test case: User provides command line dimensions that fail dimensionality checks" >> log.txt
./MatrixMultiplication 1 2 3 4 &>> log.txt

echo >> log.txt
echo >> log.txt
echo "Test case: User provides too many dimensions" >> log.txt
./MatrixMultiplication 2 3 3 2 4 &>> log.txt
echo "Test case: No command line arguments provided by user" >> log.txt
./MatrixMultiplication &>> log.txt

echo >> log.txt
echo >> log.txt
echo "Test case: User provides text rather than strings" >> log.txt
./MatrixMultiplication Hello world I\'m Bobbie! &>> log.txt

make clean > /dev/null
