#include <iostream>
#include <fstream>

using namespace std;

#define intermediate_result
int deep_of_recursion = 0;  //глобальная переменная
ofstream save_file;         //

int func(int argument_of_function){
  #ifdef intermediate_result // вывод промежуточных результатов
  for(int i = 0 ; i <= deep_of_recursion; i++)  //генерация нужного числа отступов для вывода на экран
    cout << "    ";                              //
  cout << "function for " << argument_of_function;
  for(int i = 0 ; i <= deep_of_recursion; i++)  //генерация нужного числа отступов для ввода в файл
    save_file << "    ";                              //
  save_file << "function for " << argument_of_function;
  cout << endl;
  save_file << endl;
  #endif 

  if(argument_of_function == 1){  //
    if(deep_of_recursion - 1)	  //  если аргумент функции единица => 
      deep_of_recursion--;	  //  глубина рекурсии уменьшается
    return 1;                     //  если не единица => увеличивается
  }                               //
  deep_of_recursion++;            // 
  if(!argument_of_function) 
    return 0;
  int result = 0;
  for(int i = 2; i <= argument_of_function; i++){
    result+= func(argument_of_function/i); 
  }
  return result; 
}

int main(){
  save_file.open("Tests//result_of_program.txt" , ios::out); //ios::app для записи в конец файла

  string for_beauty = "***************************************************************************************************************"; 	
  cout << for_beauty << endl << for_beauty << endl  
       << "программа по вычислению функции:" << endl << "f(n) = 1 , если n = 1" 
       << endl << "f(n) = sum(f(n div i)) , при n >=2 , где i изменяется от 2 до n , sum() - функция суммы" << endl
       << "введите агрумент функции: ";

  int argument_of_function = 1;
  while(cin >> argument_of_function){ //возможность для поступления нескольких тестов сразу
    if(!argument_of_function)	  
      return 0;
    if(argument_of_function < 0){
      cout << "на вход поступают целые ПОЛОЖИТЕЛЬНЫЕ числа" << endl << "введите следующее число: ";
      continue;
    }     
    cout << func(argument_of_function) << " - result" << endl << for_beauty << endl << for_beauty << endl 
	 << "для завершения программы введите 0 , если ввод происходит из файла программа завершиться автоматически" << endl;
    save_file << for_beauty << endl;
  }

  save_file.close();
  return 0;
}
