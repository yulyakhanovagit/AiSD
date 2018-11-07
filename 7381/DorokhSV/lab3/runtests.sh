#!/bin/bash
echo -n > postfix.txt
echo "Examples of incorrect input: "
echo "Test 1: a+b*(c--d)"
echo "Test 1: a+b*(c--d)" >> postfix.txt
./lab3 < Tests/infix1.txt >> postfix.txt
echo "Test 2: m-n*i/kk"
echo "Test 2: m-n*i/kk" >> postfix.txt
./lab3 < Tests/infix2.txt >> postfix.txt
echo "Test 3: a%c"
echo "Test 3: a%c" >> postfix.txt
./lab3 < Tests/infix3.txt >> postfix.txt
echo "Test 4: (((((d+9)+e)-8)/3)"
echo "Test 4: (((((d+9)+e)-8)/3)" >> postfix.txt
./lab3 < Tests/infix4.txt >> postfix.txt
echo "Test 5: )d+x)"
echo "Test 5: )d+x)" >> postfix.txt
./lab3 < Tests/infix5.txt >> postfix.txt
echo "Test 6: "
echo "Test 6: " >> postfix.txt
./lab3 < Tests/infix6.txt >> postfix.txt
echo "Test 7: a+b+c/"
echo "Test 7: a+b+c/" >> postfix.txt
./lab3 < Tests/infix7.txt >> postfix.txt
echo "Examples of correct input: "
echo "Test 8: q/w*e-r+t/r*e-3+4*5+3-2"
echo "Test 8: q/w*e-r+t/r*e-3+4*5+3-2" >> postfix.txt
./lab3 < Tests/infix8.txt >> postfix.txt
echo "Test 9: (q*(w/(e-(r+(2)))))"
echo "Test 9: (q*(w/(e-(r+(2)))))" >> postfix.txt
./lab3 < Tests/infix9.txt >> postfix.txt
echo "Test 10: ((a*2)/(f-5))/((a/2)+(f*5))"
echo "Test 10: ((a*2)/(f-5))/((a/2)+(f*5))" >> postfix.txt
./lab3 < Tests/infix10.txt >> postfix.txt
echo "Results of infix saved in postfix.txt"