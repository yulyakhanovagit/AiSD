#include <iostream>
#include "stack.hpp"
#include <vector>
#include <string>
#include <fstream>

typedef char Type;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    class Stack<Type> stack;
    std::string file_name;
    if(argc == 2 || argc == 3)
	file_name = argv[1];
    else{    
        std::cout << "введите название файла" << std::endl;
        std::cin >> file_name;
    }	
    std::ifstream fin;
    std::ofstream fout;
    std::string read_str;
    fin.open(file_name, std::ios::in);
    if(!fin){
	    std::cout << "ошибка открытия файла";    
        return 0;
    }
    std::cout << "ОБРАБОТКА ФАЙЛА " << file_name << std::endl;    
    if(argc == 3)
	fout.open(argv[2], std::ios::app);	    
    else	    
        fout.open("result.txt", std::ios::app);
    while(getline(fin, read_str)){
        std::cout << "исходная строка: " << read_str << std::endl;
        for(size_t i = 0; i < read_str.size(); i++)
            stack.push(read_str[i]);
	std::cout << "Cостояние стека после считывания строки: " << std::endl;
	stack.print_stack();
	std::cout << "Перевернутая строка" << std::endl;
        for(;!stack.is_empty();){
	    Type temp = stack.pop();
	    std::cout << temp;	
            fout << temp;
	}
    	std::cout << std::endl << std::endl;	
        fout << std::endl << std::endl;
    }
    fin.close();
    fout.close();
    return 0;
}
