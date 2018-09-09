#include <iostream>
#include <fstream>

#define intermediate_result

int func(int argument_of_function){
  static int deep_of_recursion = 0;	
  #ifdef intermediate_result // вывод промежуточных результатов
  for(int i = 0 ; i <= deep_of_recursion; i++)  //генерация нужного числа отступов для вывода на экран
    std::cout << "    ";                        //
  std::cout << "function for " << argument_of_function << std::endl;
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
    result+= func(argument_of_function/i);         //рекурсия 
  } 
  return result; 
}

int main(){
  setlocale(LC_ALL, "Russian"); // установлена русская локаль
  std::streambuf *mem_cout;  
  std::ofstream file;
  file.open("save_result.txt" , std::ios::app); //ios::app для записи в конец файла ; std::ios::out для записи сначала файла(предыдущие данные стераются)
  mem_cout = std::cout.rdbuf(); //запоминаем вывод в консоль

  std::cout  << "программа по вычислению функции:" << std::endl << "f(n) = 1 , если n = 1" 
             << std::endl << "f(n) = sum(f(n div i)) , при n >=2 , где i изменяется от 2 до n , sum() - функция суммы" << std::endl
             << "введите агрумент функции: " << std::endl;
  int argument_of_function = 0;
  std::cin >> argument_of_function;
  if(std::cin.fail()){
    std::cout << "Ошибка ввода данных!" << std::endl << std::endl;
    return 0;
  }  
  if(argument_of_function <= 0){
    std::cout << "на вход поступают целые ПОЛОЖИТЕЛЬНЫЕ числа" << std::endl << std::endl;
    return 0;
  }
  std::cout.rdbuf(file.rdbuf());  //перенаправляем вывод в файл
  std::cout << func(argument_of_function) << " - TOTAL RESULT"<< std::endl; 
  std::cout.rdbuf(mem_cout); // перенаправляем вывод обратно в консоль
  std::cout << func(argument_of_function) << " - TOTAL RESULT"<< std::endl;
  std::cout << "результат программы сохранен в файле save_result.txt" << std::endl << std::endl << std::endl;
  return 0;
}
