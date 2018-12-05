#include "BST.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

int main() {
    std::string list;
    std::cout << "Enter leafs for tree:" << std::endl;
    getline(std::cin, list);
    std::stringstream ss;
    for(size_t i = 0; i < list.size(); i++)     //Проверка элемента на принадлежность к целому типу
        if(isalpha(list[i]))
            std::cout << "Error! " << list[i] << " - was not digit! Stop building the tree..." << std::endl;
    ss.str(list);
    BST<int> tree;
    int value;
    while(ss >> value)
        tree.insert(value);
    std::cout << "Tree before search:" << std::endl;
    tree.display();
    std::cout << "Enter an item to search:" << std::endl;
    std::cin >> value;
    if(std::cin.fail()) {                       //Проверка символа для поиска на принадлежность целому типу
        std::cout << "Error! Items for search can only be of one type(digits)!" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        return 0;
    }
    if(!tree.search(value)) {
        std::cout << "Element wasn't found! Add an element in BST: " << value << std::endl;
        tree.insert(value);
    }
    tree.display();
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
 }