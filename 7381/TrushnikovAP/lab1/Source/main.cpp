#include <iostream>
#include <cctype>
#include <vector>
#include <cstdlib>


void function(std::vector <int> sequence, int depth, std::vector <int> &sequenceResult ){

    if(sequence.size() <= 2){                   // если последовательность состоит
        sequenceResult.push_back(sequence[0]);  //из двух или меньше двух чисел, то сохраняем ее
        sequenceResult.push_back(sequence[1]);
    }
    if(depth>0)
        std::cout << std::endl;


    if(sequence.size() % 2 == 0  && sequence.size() > 2){ // если кол-во чисел четное,
        depth++;                                          //то выполняем 2 правило
        for(int i = 0;i < depth;i++) // Вывод нужного числа отступов в консоль
            std::cout << " ";
        unsigned int size = sequence.size()/2;
        std::vector <int> sequenceBetta(size);
        std::vector <int> sequenceGamma(size);

        for(unsigned int i = 0; i < size;i++ ){
            sequenceBetta[i] = sequence[i];    
            std::cout << sequenceBetta[i] << " ";
        }

        function(sequenceBetta,depth,sequenceResult);

        for(int i = 0;i < depth;i++)// Вывод нужного числа отступов в консоль
            std::cout << " ";
        for(unsigned int i = size; i < sequence.size();i++ ){
            sequenceGamma[i-size] = sequence[i];
            std::cout << sequenceGamma[i-size] << " ";
        }
        function(sequenceGamma,depth,sequenceResult);
        return;

    }

    else if(sequence.size() % 2 && sequence.size() > 2){// если кол-во чисел нечетное,
        depth++;                                        //то выполняем 3 правило

        unsigned int size = (sequence.size()+1)/2;
        std::vector <int> sequenceBetta(size);
        std::vector <int> sequenceGamma(size);
        for(int i = 0;i < depth;i++)// Вывод нужного числа отступов в консоль
            std::cout << " ";
        for(unsigned int i = 0; i < size;i++ ){
            sequenceBetta[i] = sequence[i];
            std::cout << sequenceBetta[i] << " ";
        }

        function(sequenceBetta,depth,sequenceResult);

        for(int i = 0;i < depth;i++)// Вывод нужного числа отступов в консоль
            std::cout << " ";
        for(unsigned int i = size-1,j=0; i < sequence.size();i++,j++ ){
            sequenceGamma[j] = sequence[i];
            std::cout << sequenceGamma[j] << " ";
        }

        function(sequenceGamma,depth,sequenceResult);

        return;
    }

    return;
}

int main(int argc, char* argv[]){
    std::vector <int> sequence ;
    std::vector <int> sequenceResult;
    int num,arguments;

    if(argc > 1){         //если переданы аргументы строки, то копируем данные с argv[]
        for(int i=1; i < argc; i++){
            if(isdigit(*argv[i])){
                num=atoi(argv[i]);
                std::cout << num << " ";
                sequence.push_back(num);
            }
            else if(*argv[i]!=' ' && *argv[i]!='\n'){
                std::cout << "Error: wrong argument";
                return 0;
            }

        }

        std::cout << std::endl;
    }


    else{                              // считывание с консоли
        std::cout << "Enter number of arguments:"<< std::endl;
        std::cin >> arguments;
        std::cout << "Enter the sequence:" << std::endl;
        while(arguments > 0){
            std::cin >> num;
            if(!std::cin){
                std::cout << "Error: wrong argument ";
                return 0;
            }
                sequence.push_back(num);
                arguments--;
        }
    }

    function(sequence,0,sequenceResult);

    unsigned int size = sequenceResult.size();
    std::cout << std::endl<< "Result: ";
    for(unsigned int i=0; i< size ;i++) // вывод результата
        std::cout  <<   sequenceResult[i] << " ";

    return 0;
}
