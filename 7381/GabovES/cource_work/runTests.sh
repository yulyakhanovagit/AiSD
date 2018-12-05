echo "result of tests"
echo "test 1"
echo "input string: "
cat Tests/file1.txt
echo "some action: "
cat Tests/test1.txt
./run Tests/file1.txt < Tests/test1.txt
echo "test 2"
echo "input string: "
cat Tests/file2.txt
echo "some action: "
cat Tests/test2.txt
./run Tests/file2.txt < Tests/test2.txt
echo "test 3"
echo "input string: "
cat Tests/file3.txt
echo "some action: "
cat Tests/test3.txt
./run Tests/file3.txt < Tests/test3.txt
echo "test 4"
echo "input string: "
cat Tests/file4.txt
echo "some action: "
cat Tests/test4.txt
./run Tests/file4.txt < Tests/test4.txt
echo "test 5"
echo "input string: "
cat Tests/file5.txt
echo "some action: "
cat Tests/test5.txt
./run Tests/file5.txt < Tests/test5.txt


