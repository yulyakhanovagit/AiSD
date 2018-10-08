@echo off
chcp 1251
cls
echo.
echo Test #1 (correct data)
echo Input data:
cd Tests
TYPE test1.txt
echo.
echo.
echo Output data:
cd ..
Lab3.exe < Tests/test1.txt

echo.
echo.
echo Test #2 (correct data)
echo Input data:
cd Tests
TYPE test2.txt
echo.
echo.
echo Output data:
cd ..
Lab3.exe < Tests/test2.txt

echo.
echo.
echo Test #3 (incorrect data)
echo Input data:
cd Tests
TYPE test3.txt
echo.
echo.
echo Output data:
cd ..
Lab3.exe < Tests/test3.txt

echo.
echo.
echo Test #4 (incorrect data)
echo Input data:
cd Tests
TYPE test4.txt
echo.
echo.
echo Output data:
cd ..
Lab3.exe < Tests/test4.txt

echo.
echo.
echo Test #5 (incorrect data)
echo Input data:
cd Tests
TYPE test5.txt
echo.
echo.
echo Output data:
cd ..
Lab3.exe < Tests/test5.txt