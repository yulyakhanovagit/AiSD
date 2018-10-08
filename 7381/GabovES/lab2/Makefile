CC = g++
PAPKA = Source/
OBJ = main.o hierarchical_list.o
FLAG = -c -g
EXE = run

all: $(EXE)

run: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)
main.o: $(PAPKA)main.cpp
	$(CC) $(FLAG) $(PAPKA)main.cpp
hierarchical_list.o: Source/hierarchical_list.cpp
	$(CC) $(FLAG) $(PAPKA)hierarchical_list.cpp
clean:	
	rm $(OBJ) $(EXE)	
