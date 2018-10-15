echo "результат сохранен в файлe result.txt"
echo "РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ ТЕСТОВ" > result.txt
echo "тест №1 : входные данные: q" >> result.txt
./run < Tests/test1.txt >> result.txt
echo "тест №2 : входные данные: (a(bc))" >> result.txt
./run < Tests/test2.txt >> result.txt
echo "тест №3 : входные данные: (a(bc))aaaa" >> result.txt
./run < Tests/test3.txt >> result.txt
echo "тест №4 : входные данные: (a(b(d(hk)e)c(f(lm)g)" >> result.txt
./run < Tests/test4.txt >> result.txt
echo "тест №5 : входные данные: (a(d(e(wq)f)b(c))" >> result.txt
./run < Tests/test5.txt >> result.txt
echo "тест №6 : входные данные: aaaaaaa" >> result.txt
./run < Tests/test6.txt >> result.txt
echo "тест №7 : входные данные: (a(b(d(h))))" >> result.txt
./run < Tests/test7.txt >> result.txt
echo "тест №8 : входные данные: " >> result.txt
./run < Tests/test8.txt >> result.txt







