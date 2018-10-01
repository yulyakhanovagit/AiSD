#!/bin/bash
g++ ./Source/main.cpp -o lab1
echo  'Test 1:'
./lab1 < ./Tests/test1.txt
echo '___________________________'
echo  'Test 2:'
./lab1 < ./Tests/test2.txt
echo '___________________________'
echo  'Test 3:'
./lab1 < ./Tests/test3.txt
echo '___________________________'
echo  'Test 4:'
./lab1 < ./Tests/test4.txt
echo '___________________________'
echo  'Test 5:'
./lab1 < ./Tests/test5.txt
echo '___________________________'
echo  'Test 6:'
./lab1 < ./Tests/test6.txt
echo '___________________________'