#include <iostream>
#include <map>
#include <string>
#include "hierarchical_list.hpp"
#include <set>

int main(){
  setlocale(LC_ALL, "Russian"); // установлена русская локаль	
  std::string main_str;
  //std::cin >> main_str;
  getline(std::cin, main_str);
  H_List list;
  std::map<char,int> letter_to_int; //используется контейнер map
  char letter;
  int num;
  std::set<char> count_alpha;
  for(int i = 0 ; i < main_str.size() ; i++){ //подсчет уникальных элементов во входной строке
    if(isalpha(main_str[i]))
      count_alpha.insert(main_str[i]);
  }
  for(int i = 0 ; i < count_alpha.size() ; i++){ //заполнения контейнера map парами - (ключ; значение)
    std::cin >> letter;
    std::cin >> num;
    letter_to_int.insert(std::pair<char,int>(letter , num));
  }
  std::cout << "построение иерархического списка" << std::endl;
  list.create_list(&list , main_str, 0);
  std::cout << std::endl << std::endl << "подсчет иерархического списка" << std::endl;
  std::cout << list.result_list(&list, letter_to_int, 0) << " - is total result"<< std::endl << std::endl << std::endl;
  return 0;
}
