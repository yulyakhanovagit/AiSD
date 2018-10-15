#!/bin/bash
g++ ./Source/main.cpp -o Lab1.exe
echo -e '\nTest 1:'
cat ./Tests/Test1.txt
echo -e '\nTesting1:'
./Lab1.exe < ./Tests/Test1.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 2:'
cat ./Tests/Test2.txt
echo -e '\nTesting2:'
./Lab1.exe < ./Tests/Test2.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 3:'
cat ./Tests/Test3.txt
echo -e '\nTesting3:'
./Lab1.exe < ./Tests/Test3.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 4:'
cat ./Tests/Test4.txt
echo -e '\nTesting4:'
./Lab1.exe < ./Tests/Test4.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 5:'
cat ./Tests/Test5.txt
echo -e '\nTesting5:'
./Lab1.exe < ./Tests/Test5.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 6:'
cat ./Tests/Test6.txt
echo -e '\nTesting6:'
./Lab1.exe < ./Tests/Test6.txt
echo -e ''
echo -e ''
echo -e ''
echo -e '\nTest 7:'
cat ./Tests/Test7.txt
echo -e '\nTesting7:'
./Lab1.exe < ./Tests/Test7.txt

