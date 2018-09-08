#include <iostream>
#include <cmath>

bool checkNumber(int);
void doWork(int&);

int main(int argc, char** argv){
    // Reading data
    std::cout << "Enter natural number: \n";
    int number;
    std::cin >> number;

    // Checking data
    if (!checkNumber(number)){ 
        std::cout << "Input data is incorrect!\n";
        exit(-1);
    }


    // Solution
    // ... 
    doWork(number);
    // ...

    // Output data
    std::cout << "Result: " << number << std::endl;
}

bool checkNumber(int number){
    if (number > 0)
        return true;
    return false;
}

void doWork(int& number){
    number = pow(number,2);
}