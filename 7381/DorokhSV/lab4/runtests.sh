#!/bin/bash
echo -n > result.txt
echo "Examples of correct input: "
echo "Test 1: (a(b(d(g##)(e##))(e(d##)(p##)))(c#(g(e##)#)))"
echo "Test 1: (a(b(d(g##)(e##))(e(d##)(p##)))(c#(g(e##)#)))" >> result.txt
./lab4 < Tests/test1.txt >> result.txt
echo "Test 2: (a(b##)#)"
echo "\nTest 2: (a(b##)#)" >> result.txt
./lab4 < Tests/test2.txt >> result.txt
echo "Test 3: (a (b#    #)(c#            (k##)))"
echo "\nTest 3: (a (b#    #)(c#            (k##)))" >> result.txt
./lab4 < Tests/test3.txt >> result.txt
echo "Examples of incorrect input: "
echo "Test 4: ()"
echo "\nTest 4: ()" >> result.txt
./lab4 < Tests/test4.txt >> result.txt
echo "Test 5: (abc)"
echo "\nTest : (abc)" >> result.txt
./lab4 < Tests/test5.txt >> result.txt
echo "Test 6: (a(((b##))))"
echo "\nTest 6: (a(((b##))))" >> result.txt
./lab4 < Tests/test6.txt >> result.txt
echo "Test 7: "
echo "\nTest 7: " >> result.txt
./lab4 < Tests/test7.txt >> result.txt
echo "Results of tests saved in result.txt"