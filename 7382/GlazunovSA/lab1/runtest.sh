#!/bin/bash
#g++ ./source/main.c -o lab1
./compile.sh
point=1
./lab1 < ./tests/file$point.txt
file="./output_of_lab1.txt"
read  d < $file 
if [ $d -eq 25 ]
then echo TEST#$point success output:$d  [correct]
else echo TEST#$point wrong output:$d   [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -326 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -1 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 4888330 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 16 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq -100000000 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 480 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 0 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
./lab1 < ./tests/file$point.txt
read  d < $file 
if [ $d == 45 ]
then echo TEST#$point success output:$d [ correct]
else echo TEST#$point wrong output:$d [ correct]
fi
let point=$point+1
rm output_of_lab1.txt
#rm ./source/file.txt
