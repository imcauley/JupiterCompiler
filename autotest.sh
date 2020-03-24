#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

for f in ./testfiles/*
do
    echo ${f:12:256}
    PF=${f:12:1}
    PASS=p
    FAIL=f

    if [ $PF = $PASS ]
    then
        ./compiler $f > /dev/null
        if [ $? -eq 255 ]
        then
            echo -e "${GREEN}PASS PASS${NC}"
        else
            echo -e "${RED}PASS FAIL${NC}"
        fi
    fi

    if [ $PF = $FAIL ]
    then
        ./compiler $f > /dev/null
        if [ $? -eq 255 ]
        then
            echo -e "${GREEN}FAIL PASS${NC}"
        else
            echo -e "${RED}FAIL FAIL${NC}"
        fi
    fi
done