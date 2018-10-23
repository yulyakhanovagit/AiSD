#!/bin/bash
echo -n > results.txt
echo "Examples of correct input: "
echo "Test 1: (a(bc(de)fg))"
echo "Test 1: (a(bc(de)fg))" >> results.txt
./lab2 < Tests/test1.txt >> results.txt
echo "Test 2: (qwer(ty))"
echo "Test 2: (qwer(ty))" >> results.txt
./lab2 < Tests/test2.txt >> results.txt
echo "Test 3: (esrever)"
echo "Test 3: (esrever)" >> results.txt
./lab2 < Tests/test3.txt >> results.txt
echo "Examples of incorrect input: "
echo "Test 4: (abc(de(f)))"
echo "Test 4: (abc(de(f)))" >> results.txt
./lab2 < Tests/test4.txt >> results.txt
echo "Test 5: )kjndkjfn)"
echo "Test 5: )kjndkjfn)" >> results.txt
./lab2 < Tests/test5.txt >> results.txt
echo "Test 6: (khbkhb(shd(bd))"
echo "Test 6: (khbkhb(shd(bd))" >> results.txt
./lab2 < Tests/test6.txt >> results.txt
echo "Results of test saved in results.txt"