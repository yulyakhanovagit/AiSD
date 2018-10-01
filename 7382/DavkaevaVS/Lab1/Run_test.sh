#!/bin/bash
gcc ./Source/lr1.c -o Lab1
echo -e '_______\nTest 1:'
cat ./Tests/1test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/1test.txt
echo -e ''
echo -e '_______\nTest 2:'
cat ./Tests/2test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/2test.txt
echo -e ''
echo -e '_______\nTest 3:'
cat ./Tests/3test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/3test.txt
echo -e ''
echo -e '_______\nTest 4:'
cat ./Tests/4test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/4test.txt
echo -e ''
echo -e '_______\nTest 5:'
cat ./Tests/5test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/5test.txt
echo -e ''
echo -e '_______\nTest 6:'
cat ./Tests/6test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/6test.txt
echo -e ''
echo -e '_______\nTest 7:'
cat ./Tests/7test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/7test.txt
echo -e '_______\nTest 8:'
cat ./Tests/8test.txt
echo -e '_______\nTesting:\n'
./Lab1 < ./Tests/8test.txt

