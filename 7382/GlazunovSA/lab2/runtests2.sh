#!/bin/bash
./compile.sh
point=1
number=2
./lab$number < ./tests/file$point.txt
file="./output_of_lab2.txt"
read  d < $file 
if [ $d == 0 ]
then echo TEST#$point success output:$d  [correct]
else echo TEST#$point wrong output:$d   [correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 2 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 4 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d -eq 2 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == error ]
then echo TEST#$point success output:$d [NOT correct]
else echo TEST#$point wrong output:$d [NOT correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 3 ]
then echo TEST#$point success output:$d  [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 3 ]
then echo TEST#$point success output:$d [correct]
else echo TEST#$point wrong output:$d [correct]
fi
let point=$point+1
########################################
rm output_of_lab2.txt
