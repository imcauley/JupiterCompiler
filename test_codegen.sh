#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

ANS_DIR='./testfiles/codegen_answers/'

for f in ./testfiles/codegen/*
do
    echo ${f:20:256}
    ANSWER=${ANS_DIR}${f:20:256}

    cat ${ANSWER}

    # ./compiler $f > /dev/null
    # if [ $? -eq 0 ]
    # then
    #     echo -e "${GREEN}PASS${NC}"
    # else
    #     echo -e "${RED}FAIL${NC}"
    # fi

done