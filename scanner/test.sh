#! /usr/bin/bash

# make scanner

# ./scanner tester.txt
FILES=./testfiles/*
for f in $FILES
do
    echo $f
    ./scanner $f
    echo " "
done