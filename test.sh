#!/bin/bash
for dir in ./a*/; do
    g++ -pedantic-errors -std=c++11 ${dir}/test.cpp -o ${dir}/test && (echo 0 | a1/test)
done
