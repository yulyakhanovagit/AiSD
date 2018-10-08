#include <iostream>
#include <map>
#include <string>
#include "hierarchical_list.hpp"
#include <algorithm>
#include <vector>

#define print_create_list           // выполняется одно из двух
#define print_minimal_create_list   // 2 разных способа вывода построений списка - подробный и минимизированный
#define print_calculation           

bool is_operation(char);
int ret_result(char, std::vector<int>);
int transform_char_to_int(std::map<char, int>, char);

Pair::Pair(){
  down = nullptr; //конструктор класса Pair
  right = nullptr;
}

H_List::H_List(){ //конструктор класса H_List
  is_atom = false;
}

H_List::~H_List(){
  if(!this->is_atom && this->pair.down) //очистка памяти с помощью деструктора
    delete pair.down;
  if(!this->is_atom && this->pair.right)
    delete pair.right;	  
}

int H_List::result_list(H_List* list , std::map<char,int>& letter_to_int, int level){
  for(int i = 0; i < level ; i++)
    std::cout << "    ";	  
  char remember_operation;  //запоминаем операцию 
  if(list->pair.down && is_operation(list->pair.down->data)) 
    remember_operation = list->pair.down->data;
  std::vector<int> result_mas; //формируется вектор для его дальшейшего подсчета
  if(list->pair.down && !list->pair.down->is_atom){
    while(list->pair.down){
      if(list->pair.down->is_atom && list->pair.down->data)
        return transform_char_to_int(letter_to_int, list->pair.down->data);	      
      list = list->pair.down;
    }
    return 0;
  }    
  if(list->pair.down && isalpha(list->pair.down->data) && list->pair.right == nullptr)
    return transform_char_to_int(letter_to_int, list->pair.down->data);	  
  if(list->pair.right && list->pair.right->pair.right == nullptr && is_operation(list->pair.down->data)){ //if only one simvol
    if(remember_operation != '-')    	  
      return transform_char_to_int(letter_to_int, list->pair.right->pair.down->data);
    return transform_char_to_int(letter_to_int, list->pair.right->pair.down->data) * (-1);
  }  
  if(list->pair.down && list->pair.down->is_atom && is_operation(list->pair.down->data)){
    while(list->pair.right != nullptr){
      list = list->pair.right;
      if(list->pair.down && list->pair.down->is_atom && isalpha(list->pair.down->data))
        result_mas.push_back(transform_char_to_int(letter_to_int, list->pair.down->data));
      if(!list->pair.down->is_atom) 
        result_mas.push_back(result_list(list->pair.down, letter_to_int , level+1)); //рекурсивно подсчитываем весь иерархический список
    }
  }
  #ifdef print_calculation 
  for(int i = 0; i < result_mas.size(); i++){
    if(i == result_mas.size()-1){
      std::cout << result_mas[i] << std::endl; //если объявлено print_calculation то выводим способ подсчета списка
      continue;
    }
    std::cout << result_mas[i] << remember_operation;  
  }
  #endif
  return ret_result(remember_operation, result_mas);
}

void H_List::create_list(H_List* list, std::string main_str , int level){ //так как этот метод вызывается рекурсивно - конструктор использовать не стоит
  int depth = 0;
  for(int i = main_str.size()-1 ; i >= 0 ; i--){
    if(main_str[i] != ')' && main_str[i] != '(' && !isalpha(main_str[i]) && !is_operation(main_str[i]) && main_str[i] != ' '){
      std::cout << "some error simvol" << std::endl;
      exit(0);
    }	    
  }
  for(int i = main_str.size()-1 ; i >= 0 ; i--){
    if(main_str[i] != ')' && main_str[i] != '(' && !isalpha(main_str[i]) && !is_operation(main_str[i]))
      continue;	    
    if(main_str[i] == '(') //подсчет степени вложенности
      depth--;
    if(main_str[i] == ')')
      depth++;
    if((is_operation(main_str[i]) || isalpha(main_str[i])) && depth == 1){ //обработка степени вложенности == 1
      list->pair.down = new H_List;
      list->pair.down->is_atom = true;

      #ifdef print_create_list
      for(int i = 0; i <= level ; i++)
        std::cout << "    ";
      if(is_operation(main_str[i]))
        level++;
      std::cout << "down " << main_str[i] << std::endl;
      #else
        #ifdef print_minimal_create_list
          for(int i = 0; i <= level ; i++)
            std::cout << "    ";
	  if(is_operation(main_str[i]))
            level++;
          std::cout << main_str[i] << std::endl;
        #endif
      #endif
      list->pair.down->data = main_str[i];
      if(main_str[i-1] == '(')
        list->pair.right = nullptr;
      else{
	#ifdef print_create_list
	for(int i = 0; i <= level ; i++)
          std::cout << "    ";
	std::cout << "right " << main_str.substr(0 , i) << ')' << std::endl;
        #endif
	list->pair.right = new H_List; 	
	create_list(list->pair.right , main_str.substr(0 , i) + ')' , level); //
	return;
      }	
    }
    if(depth == 2){ //если это компонента вложенности тогда нужно её выделить
      std::string new_str;	    
      for(int k = 0 ; main_str[i] != '('; k++ , i--){
	if(main_str[i] == '(')
          depth--;
        if(main_str[i] == ')')
          depth++;      
        new_str += main_str[i];
      }
      std::reverse(new_str.begin() , new_str.end()); //реверсируем компоненту вложенности
      #ifdef print_create_list
      for(int i = 0; i <= level ; i++)
        std::cout << "    ";
      std::cout << "down " << '(' + new_str << std::endl;
      #endif
      list->pair.down = new H_List;
      create_list(list->pair.down , '(' + new_str , level+1);                
      if(main_str[i-1] == '(' || main_str.substr(0 , i).size() == 0)
        list->pair.right == nullptr;
      else{
	#ifdef print_create_list
        for(int i = 0; i <= level ; i++)
          std::cout << "    ";
	std::cout << "right " << main_str.substr(0 , i) + ')' << std::endl;  
 	#endif
	list->pair.right = new H_List;
        create_list(list->pair.right , main_str.substr(0 , i) + ')' , level);//
      }      
      return;  
    }
  }
}

bool is_operation(char simvol){
  if(simvol == '+' || simvol == '-' || simvol == '*' || simvol == '/')  //проверка является ли число оператором
    return true;
  return false;
}

int transform_char_to_int(std::map<char, int> letter_to_int, char letter){ // преобразование char к int
  for(auto it : letter_to_int)
    if(it.first == letter)
      return it.second;
  std::cout << "error! no value for letter: " << letter;
  std::cout << std::endl << std::endl << std::endl;
  exit(0);
}

int ret_result(char operation, std::vector<int> result_mas){ // применяет полусенную операцию ко всем элемента вектора
  int result = 0;
  int a,b;
  switch(operation){
    case '+' : for(auto it: result_mas)
                 result += it;
               break;
    case '-' : for(int i = 1; i < result_mas.size(); i++)
                 result_mas[0] -= result_mas[i];
               return result_mas[0];
               break;
    case '*' : result = result_mas[0];
               for(int i = 1 ; i < result_mas.size() ; i++)
                 result *= result_mas[i];
               break;
    case '/' : result = result_mas[0];
               for(int i = 1; i < result_mas.size(); i++){
                 if(result_mas[i] == 0){
                  std::cout << "Zero division attemp" << std::endl << std::endl << std::endl; //проверка деления на ноль
                  exit(0);
                 }
                 result /= result_mas[i];
               }
               break;
    default: return 0;
  }
  return result;
}
