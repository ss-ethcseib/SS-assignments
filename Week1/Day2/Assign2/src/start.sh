#!/bin/bash

make > /dev/null

echo "Working with types program start"                                                                                  
./WorkingWithTypes     

echo
echo
echo
echo

echo "Floating point precision program start"                                                                            
echo
./FloatPrecision

make clean > /dev/null
