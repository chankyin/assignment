#!/bin/bash
for dir in ./a*/; do
    g++ -pedantic-errors -std=c++11 ${dir}/test.cpp -o ${dir}/test && (cd ${dir} ; echo 0 | ${dir}/test)
done
