#!/bin/bash
echo -n > results.txt

echo "Examples of correct input: "

echo "Test 1: (a*(c+d))"
echo "Test 1: " >> results.txt
./lab1 < Tests/test1.txt >> results.txt

echo "Test 2: ((a+b)*(m-k))"
echo "Test 2: " >> results.txt
./lab1 < Tests/test2.txt >> results.txt

echo "Test 3: a"
echo "Test 3: " >> results.txt
./lab1 < Tests/test3.txt >> results.txt

echo "Examples of incorrect input: "

echo "Test 4: ((((((a+b)))"
echo "Test 4: " >> results.txt
./lab1 < Tests/test4.txt >> results.txt

echo "Test 5: ((m-k)/d)"
echo "Test 5: " >> results.txt
./lab1 < Tests/test5.txt >> results.txt

echo "Test 6: a+"
echo "Test 6: " >> results.txt
./lab1 < Tests/test6.txt >> results.txt

echo "Results of test saved in results.txt"
