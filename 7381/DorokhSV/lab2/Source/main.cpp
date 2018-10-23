#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include "lisp_func.h"

void print_basic (int deepCount, lisp s) {   // Функция печати состояния иерарх. списка на определённом вызове рекурсии
    for (int i = 0; i < deepCount; i++)
        std::cout << "\t";
    std::cout << "call ";
    write_lisp(s);
    std::cout << std::endl;
}

void print_reverse (int deepCount, lisp s) {    // Функция печати состояния обратного иерарх. списка на определённом вызове рекурсии
    for (int i = 0; i < deepCount-1; i++)
        std::cout << "\t";
    std::cout << "llac ";
    write_lisp(s);
    std::cout << std::endl;
}

lisp reverse( lisp s, lisp z, int count) {  //Рекурсивная функция для создания обратного иерарх. списка
    print_basic(count, s);
    lisp k;
    if (isNull(s)){
        print_reverse(++count, z);
        --count;
        return z;
    }
    if(isAtom(head(s))){
        k = reverse(tail(s), cons(head(s), z), ++count);    //Если элемент атом, то вызывается reverse и выполняется запись атома в новый список
        print_reverse(count, z);
        return k;
    }
    k = reverse(tail(s), cons(reverse(head(s), NULL, count), z), ++count);  //Если не атом, то создаётся подсписок z для для записи в него 
    print_reverse(count, z);                                                //подсписка исходного иерархического списка
    return k;
   
}

int main () {
    std::stringbuf buffer;                 
    std::string list;                   
    char ch;
    
    getline(std::cin, list);            
    std::istream str(&buffer);             
    buffer.str(list);                      
    
    if(!list.length()){
        std::cout << "List is empty!" << std::endl;
        return 0;
    }
    lisp s1;
    read_lisp (s1, str);

    if(str >> ch){                                     //Проверка на то, осталось ли что в str после выполнения функции read_lisp
        std::cout<<"Extra characters!"<< std::endl;
        destroy(s1);
        return 0;
    }

    std::cout << "Entered list: ";
    write_lisp (s1);
    std::cout << std::endl;
    lisp array[20];
    lisp k = reverse(s1, NULL, 0);
    std::cout << "Reversed list:";
    write_lisp (k);
    std::cout << std::endl;
    destroy(k);
    delete(s1);
    return 0;
}