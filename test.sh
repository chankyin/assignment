#!/bin/bash
for dir in ./a*/; do
    mkdir ${dir}yourOutput 2>/dev/null
    g++ -pedantic-errors -std=c++11 ${dir}test.cpp -o ${dir}test \
        || exit 1
    cd ${dir}
    echo 0 | ./test | tee /dev/tty \
        | grep FAILED \
        && exit 2
done
