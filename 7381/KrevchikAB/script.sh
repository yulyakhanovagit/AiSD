#!/bin/bash
gcc ./Source/main.c -o lr1

echo 'Test 1:'
cat ./Tests/T1.txt
echo -e '\n'
./lr1 < ./Tests/T1.txt

echo 'Test 2:'
cat ./Tests/T2.txt
echo -e '\n'
./lr1 < ./Tests/T2.txt

echo 'Test 3:'
cat ./Tests/T3.txt
echo -e '\n'
./lr1 < ./Tests/T3.txt

echo 'Test 4:'
cat ./Tests/T4.txt
echo -e '\n'
./lr1 < ./Tests/T4.txt

echo 'Test 5:'
cat ./Tests/T5.txt
echo -e '\n'
./lr1 < ./Tests/T5.txt

echo 'Test 6:'
cat ./Tests/T6.txt
echo -e '\n'
./lr1 < ./Tests/T6.txt
