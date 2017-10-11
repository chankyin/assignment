#!/bin/bash
for dir in ./a*/; do
    g++ -pedantic-errors -std=c++11 ${dir}test.cpp -o ${dir}test \
        || exit 1
    cd ${dir}
    echo 0 | ./test | tee /dev/tty \
        | grep FAILED \
        && exit 2
done
