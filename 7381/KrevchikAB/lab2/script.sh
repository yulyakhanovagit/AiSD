#!/bin/bash
g++ ./Source/main.cpp ./Source/L_func.cpp -o lr2

echo 'Test 1:'
cat ./Tests/T1.txt
echo -e '\n'
./lr2 < ./Tests/T1.txt

echo 'Test 2:'
cat ./Tests/T2.txt
echo -e '\n'
./lr2 < ./Tests/T2.txt

echo 'Test 3:'
cat ./Tests/T3.txt
echo -e '\n'
./lr2 < ./Tests/T3.txt

echo 'Test 4:'
cat ./Tests/T4.txt
echo -e '\n'
./lr2 < ./Tests/T4.txt


