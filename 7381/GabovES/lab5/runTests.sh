echo " test 1 "
echo " element of file: 12 23 45 1 2 3"
echo " element to add : 5"
echo ""
./run Tests/file1.txt < Tests/test1.txt
echo ""
echo ""
echo " test 2 "
echo " element of file: ert 3 fgh 4 df 7 esf 3 gdt 89 das 124"
echo " element to add : 1234"
echo ""
./run Tests/file2.txt < Tests/test2.txt

echo ""
echo ""
echo " test 3 "
echo " element of file: 1 2 3 tggtdgr 4 gdr 5     6 7 8 egrgrger 9 feefs"
echo " element to add : 56"
echo ""
./run Tests/file3.txt < Tests/test3.txt

echo ""
echo ""
echo " test 4"
echo " element of file: jkfsekbesfkjbfeskjbfeskjbfeskjb"
echo " element to add : 895"
echo ""
./run Tests/file4.txt < Tests/test4.txt

echo ""
echo ""
echo " test 5"
echo " element of file: 1 2 3 4 jkk 5 jk 6 7 seffsefe       8"
echo " element to add : w"
echo ""
./run Tests/file5.txt < Tests/test5.txt
