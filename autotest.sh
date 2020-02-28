#!/bin/bash

for f in ./testfiles/*
do
    echo "Testing file: $f"
    cat $f
    echo " "
    echo "Compiler Output:"
    ./compiler $f
    echo "================================="

done