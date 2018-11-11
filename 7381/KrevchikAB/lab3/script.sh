#!/bin/bash
g++ ./Source/main.cpp ./Source/stack.cpp -o lr3

echo -e '\n'
echo 'Test 1:'
cat ./Tests/T1.txt
echo -e '\n'
./lr3 < ./Tests/T1.txt

echo -e '\n'
echo 'Test 2:'
cat ./Tests/T2.txt
echo -e '\n'
./lr3 < ./Tests/T2.txt

echo -e '\n'
echo 'Test 3:'
cat ./Tests/T3.txt
echo -e '\n'
./lr3 < ./Tests/T3.txt

echo -e '\n'
echo 'Test 4:'
cat ./Tests/T4.txt
echo -e '\n'
./lr3 < ./Tests/T4.txt

echo -e '\n'
echo 'Test 5:'
cat ./Tests/T5.txt
echo -e '\n'
./lr3 < ./Tests/T5.txt

echo -e '\n'
echo 'Test 6:'
cat ./Tests/T6.txt
echo -e '\n'
./lr3 < ./Tests/T6.txt
