#!/bin/bash
#g++ ./source/lab1.cpp -o lab1
./compile.sh
point=1
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
./lab1 < ./tests/test$point.txt
let point = $point + 1
####################################
