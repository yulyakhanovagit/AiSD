#!/bin/bash
echo -n > result.txt
echo "Examples of correct input: "
echo "Test 1: 1 123 684 456\n\t19"
echo "Test 1: 1 123 684 456\n\t19" >> result.txt
./lab5 < Tests/test1.txt >> result.txt
echo "Test 2: 3 7 2 1 10 9\n\t0"
echo "Test 2: 3 7 2 1 10 9\n\t0" >> result.txt
./lab5 < Tests/test2.txt >> result.txt
echo "Test 3: \n\t777"
echo "Test 3: \n\t777" >> result.txt
./lab5 < Tests/test3.txt >> result.txt
echo "Test 4: 0 2 4 6 8 10 12 14 16 18 20 -2 -4 -6 -8 -10 -12 -14 -16 -18 -20\n\t-7"
echo "Test 4: 0 2 4 6 8 10 12 14 16 18 20 -2 -4 -6 -8 -10 -12 -14 -16 -18 -20\n\t-7" >> result.txt
./lab5 < Tests/test4.txt >> result.txt
echo "Examples of incorrect input: "
echo "Test 5: 7 1 8 1 3 12 47\n\tqwe"
echo "Test 5: 7 1 8 1 3 12 47\n\tqwe" >> result.txt
./lab5 < Tests/test5.txt >> result.txt
echo "Test 6: 8 8 1 4  oops 12 47\n\t10"
echo "Test 6: 8 8 1 4  oops 12 47\n\t10" >> result.txt
./lab5 < Tests/test6.txt >> result.txt
echo "Results of tests saved in result.txt"