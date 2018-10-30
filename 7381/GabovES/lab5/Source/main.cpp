#include <iostream>
#include <fstream>
#include "avl_tree.h"

typedef int Type;
#define FROM_FILE

int main(int argc, char* argv[])
{
    Head_AVL_Tree<Type> head;

    #ifdef FROM_FILE
    std::ifstream fin;
    if(argc == 2)
	fin.open(argv[1], std::ios::in);
    else{
	std::string file_name;    
	std::cout << "input filename" << std::endl;
    	std::cin >> file_name;    
  	fin.open(file_name, std::ios::in);
    }	
    if(!fin){
        std::cout << "ошибка открытия файла" << std::endl;
        return 0;
    }
    #endif

    std::string main_str;
    #ifdef FROM_FILE
    	getline(fin, main_str);
	std::cout << std::endl << "create AVL_Tree from file " << std::endl;
    #else	
      	getline(std::cin, main_str);
    #endif

    int count_num = 0;
    for(size_t i = 0; i < main_str.size(); i++){
        int temp = 0;
        bool is_num = false;
        for(size_t j = i; isdigit(main_str[j]); j++, i++){
            temp = temp*10 + main_str[j]-'0';
            is_num = true;
        }
        if(is_num){
	    count_num++;	
	    std::cout << "add to the tree: " << temp << std::endl;		
            head.insert(temp);
	    std::cout << "tree after added " << temp << std::endl;
	    head.print_tree();
	    std::cout << std::endl;
	}
    }

    if(!count_num){
    	std::cout << "no one element to tree. Program will end" << std::endl;
    	exit(0);
    }

    int is_continue = 1;
    for(;is_continue;){
	if(argc != 2)    
            std::cout << "input 0 to end or input 1 to contunue " << std::endl;
        std::cin >> is_continue;
        if(std::cin.fail()){
            std::cout << "input error. May be it`s not a number or it`s very big number" << std::endl;
            break;
        }
	if(!is_continue)
            break;
        int insert_tree_element;
	if(argc != 2)
            std::cout << "input element to add " << std::endl;
        std::cin >> insert_tree_element;
	if(argc == 2)
	    std::cout << "add to tree new element: " << insert_tree_element  << std::endl;		
        if(std::cin.fail()){
            std::cout << "input error. May be it`s not a number or it`s very big number" << std::endl;
            break;
        }
        if(!head.is_contain(insert_tree_element)){
            head.insert(insert_tree_element);
            std::cout << "tree after add new element:" << std::endl;
            head.print_tree();
        }
        else
            std::cout << "element already in tree" << std::endl;
    }
    #ifdef FROM_FILE
        fin.close();
    #endif	
    return 0;
}
