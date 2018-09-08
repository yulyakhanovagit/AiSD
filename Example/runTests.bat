@echo off
chcp 1251
cls
echo ****** TESTS FOR LAB 42 *******
echo.
echo Test #1 (correct data)
echo Input data:
cd Tests
TYPE test1
echo.
echo.
echo Output data:
cd ..
Lab42.exe < Tests/test1

echo.
echo.
echo Test #2 (correct data)
echo Input data:
cd Tests
TYPE test2
echo.
echo.
echo Output data:
cd ..
Lab42.exe < Tests/test2

echo.
echo.
echo Test #3 (incorrect data)
echo Input data:
cd Tests
TYPE test3
echo.
echo.
echo Output data:
cd ..
Lab42.exe < Tests/test3

echo.
echo.
echo Test #4 (incorrect data)
echo Input data:
cd Tests
TYPE test4
echo.
echo.
echo Output data:
cd ..
Lab42.exe < Tests/test4