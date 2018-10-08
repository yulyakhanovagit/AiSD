#!/bin/bash
./compile.sh
point=1
number=3
./lab$number < ./tests/file$point.txt
file="./output_of_lab3.txt"
read  d < $file 
if [ $d == 'sretsetolleh' ]
then echo TEST#$point success output:$d  
else echo TEST#$point wrong output:$d   
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 'skcusredrodnassemaekam' ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 'sdfdfgkdfjkgsjfgfvrjgdlkgjkdjfgkjfgkjhgjfdhjgfdgjfdjghfsdjg' ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == yegresmai ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == yltsomlatcejbusetiruovafymsidsia ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 987654321 ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == alloha ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 347'!!!'oooobmabgib ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d  
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == machupikcha ]
then echo TEST#$point success output:$d  
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
rm output_of_lab3.txt
########################################
./lab$number < ./tests/file$point.txt
read  d < $file 
if [ $d == 7dfg88fd8gdfgfdsgfdgfdsgfdgfdg ]
then echo TEST#$point success output:$d 
else echo TEST#$point wrong output:$d 
fi
let point=$point+1
########################################
rm output_of_lab3.txt
