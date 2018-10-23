.PHONY: all clean

all : hello

hello : main.o l_intrfc.o
	g++ main.o l_intrfc.o

main.o : ./Source/main.cpp
	g++ -c ./Source/main.cpp

l_intrfc.o: ./Source/l_intrfc.cpp ./Source/l_intrfc.h
	g++ -c ./Source/l_intrfc.cpp


clean :
	rm -rf *.o a.out
