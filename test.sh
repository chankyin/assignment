#!/bin/bash
for dir in ./a*/; do
    mkdir ${dir}yourOutput 2>/dev/null
    g++ -pedantic-errors -std=c++11 ${dir}test.cpp -o ${dir}test \
        || exit 1
    cd ${dir}
    RESULT=$(echo 0 | ./test | tee /dev/tty)
    echo "$RESULT" | grep FAILED --color=always && exit 2
done

exit 0
