#!/bin/bash
gcc ./Source/lab1.c -o lab1.exe
echo -e 'Test1:'
cat ./Tests/test1.txt
echo -e 'Result:'
./lab1.exe < ./Tests/test1.txt
echo -e '\nTest2:'
cat ./Tests/test2.txt
echo -e 'Result:'
./lab1.exe < ./Tests/test2.txt
echo -e '\nTest3:'
cat ./Tests/test3.txt
echo -e 'Result:'
./lab1.exe < ./Tests/test3.txt
echo -e '\nTest4:'
cat ./Tests/test4.txt
echo -e 'Result:'
./lab1.exe < ./Tests/test4.txt
echo -e '\nTest5:'
cat ./Tests/test5.txt
echo -e '\nResult:'
./lab1.exe < ./Tests/test5.txt
echo -e '\nTest6:'
cat ./Tests/test6.txt
echo -e '\nResult:'
./lab1.exe < ./Tests/test6.txt

