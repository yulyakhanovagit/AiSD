#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstring>

int leftChild (int count) {
    return 2*count + 1;
}

int rightChild (int count) {
    return 2*count + 2;
}

bool readBT(char* buf, int count, std::istream &list) {
    char elem;
    list >> buf[count];
    list >> elem;
    if(elem != '(' && elem != '#') {
        std::cout << "Error! Subtree can start only with '(' or '#'." << std::endl;
        return false;
    }
    if(elem == '(') {
        if(!readBT(buf, leftChild(count), list))
            return false;
        list >> elem;
        if(elem != ')') {
            std::cout << "Error! Waiting ')', leaf cant have more then 2 sons" << std::endl;
            return false;
        }
    }
    if(elem == '#')
        buf[leftChild(count)] = elem;
    list >> elem;
    if(elem != '(' && elem != '#') {
        std::cout << "Error! Subtree can start only with '(' or '#'." << std::endl;
        return false;
    }
    if(elem == '(') {
        if(!readBT(buf, rightChild(count), list))
            return false;
        list >> elem;
        if(elem != ')') {
            std::cout << "Error! Waiting ')', leaf cant have more then 2 sons" << std::endl;
            return false;
        }
    }
    if(elem == '#')
        buf[rightChild(count)] = elem;
    return true;
}

int lvl(int count) {
    int lvl = 1;
    while((pow(2, lvl-1)-1) < count && count > (pow(2, lvl)-2))
        lvl++;
    return lvl;
}

void print_tabs(int count) {
    int lvl_s = lvl(count);
    for(int i = 0; i < lvl_s; i++)
        std::cout << '\t';
}

int numberOfElem(char *buf, size_t count, char elem, int &number) {         //Функция, проверяющая имеется ли заданный элемент в узлах дерева 
    if(count <= strlen(buf)) {                                              //и количество вхождений данного элемента в дерево
        if(elem == buf[count]) {
            print_tabs(count);
            std::cout << "call: Success! Element '" << elem << "' found at " << count+1 << " position" << std::endl;
            ++number;
        }
        else if(buf[count] != '#' && buf[count] != elem && buf[count] != '\0') {
            print_tabs(count);
            std::cout << "call: Failure! Element '" << buf[count] << "' not '" << elem << "'" << std::endl;
        }
        numberOfElem(buf, leftChild(count), elem, number);
        numberOfElem(buf, rightChild(count), elem, number);
        if(buf[count] != '\0' && buf[count] != '#') {
            print_tabs(count);
            std::cout << "llac" << std::endl;
        }
    }
    return number;

}

int depthOfBT(char *buf, size_t count, char elem) {                                             //Функция находящая минимальную длину пути до заданного элемента
    size_t left_depth = 1;
    size_t right_depth = 1;
    if(buf[count] == elem || (2*count+1 > strlen(buf) && 2*count+2 > strlen(buf))) {            //Если узел дерева не лист или искомый элемент заканчиваем рекурсию
        if(buf[count] != '#' && (isalpha(buf[count]) || isdigit(buf[count])))
            std::cout << "\tNot a leaf or disered element '" << buf[count] << '\'' << std::endl;
        return 0;
    }
    else {
        left_depth += depthOfBT(buf, 2*count+1, elem);                                         
        right_depth += depthOfBT(buf, 2*count+2, elem);
        if(buf[count] != '#')
            std::cout << "\tMinimal path length for this step: " << std::min(right_depth, left_depth) << std::endl;
        return std::min(right_depth, left_depth);
    }
}

int readEmptyBT(char *buf, int count, std::istream &list) {                                     //Функция считывания корня бинарного дерева
    char elem;
    list >> elem;
    if(elem != '(') {
        std::cout << "Error! Incorrect element at first leaf!" << std::endl;
        return 0;
    }
    return readBT(buf, count, list);
}

int main() {
    std::stringbuf buffer;                 
    std::string list;  
 
    std::cout << "Enter a bracket representation of binary tree: ";              
    getline(std::cin, list);
    list.erase(std::remove(list.begin(), list.end(), ' '), list.end());
    std::cout << "Entered tree: " << list << std::endl;  

    std::istream str(&buffer);             
    buffer.str(list);
    int size = 0, max = 0;

    for(unsigned int i = 0; i < list.size(); i++) {
        if(list[i] == '(')
            ++size;
        if(max < size)
            max = size;
        if(list[i] == ')')
            --size;
        }       
    max = pow(2, max) - 1;
    char* buf = new char [max];
    for(int i = 0; i < max; i++)
        buf[i] = '#';

    size_t count = 0;
    if(!readEmptyBT(buf, count, str))
        return 0;
    std::cout << "Tree was read: " << buf << std::endl;
    char elem;
    std::cout << "Enter a character to check >> ";
    std::cin >> elem;
    if(elem != '#'){
        int number = 0;
        if(numberOfElem(buf, count, elem, number))
            std::cout << "The number of occurences of '" << elem << "': " << number << std::endl;
        else {
            std::cout << "Error! Symbol '" << elem << "' was not found." << std::endl;
            delete[] buf;
            return 0;
        }
        size_t depth = depthOfBT(buf, 0, elem);
        std::cout << "Path length to symbol '" << elem << "' equally " << depth << std::endl;
    }
    else std::cout << "Error! Incorrect character." << std::endl;
    delete[] buf;
}

