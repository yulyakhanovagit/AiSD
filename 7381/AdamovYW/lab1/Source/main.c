#include  <stdio.h>

// сообщения об ошибках
void error_message(int numb_of_error){
    printf("\nОшибка: ");
    switch (numb_of_error){
        case 1:
            printf("вы ввели отрицательное значение.\n");
            break;
        case 2:
            printf("необходима ввести целое число.\n");
            break;
    }
    printf("Программа завершила работу.\n\n");
}


// поиск значения биноманального коэфициента рекурсивным способом
int binominal_coef(int coef_m , int coef_n, int level){
    for(int i = 0; i < level; i++) // создание отступов
        printf("    ");
    printf("call: m = %d, n = %d ; ", coef_m, coef_n); // сообщение о вызове функции
    if ( (coef_m == 0 && coef_n > 0) || (coef_m == coef_n && coef_n >= 0) ){
        printf("return 1\n"); // самый глубокий уровень, возврат единицы
        return 1;
    } else if (coef_m > coef_n && coef_n >= 0){
        printf("return 0\n"); // случай, возможный только при вводе m > n
        return 0;
    } else {
        // вызов рекурсии в случае, если m < n
        printf("return C(%d,%d) + C(%d,%d)\n", coef_m-1, coef_n-1, coef_m, coef_n-1);
        int result = binominal_coef(coef_m-1, coef_n-1, level+1) + binominal_coef(coef_m, coef_n-1, level+1);
        for(int i = 0; i < level; i++)
            printf("    ");
        printf("C(%d,%d) + C(%d,%d) = %d\n", coef_m-1, coef_n-1, coef_m, coef_n-1, result);
        return result;
    }
}


int main(void){
    
    int coef_m, coef_n, result;
    
    
    // описание программы
    printf("\nПрограмма для вычисления биноминальных коэффициентов.\n");
    printf("Вычисление происходит рекурсивно.\n");
    printf("\n  m   | 1, если m = 0, n = 0 или m = n >= 0,\n");
    printf("C   = | 0, если m > n >= 0,\n");
    printf("  n   | C(m-1, n-1) + C(m, n-1) в остальных случаях.\n");
    printf("\nЗначения m и n - целые неотрицательные числа.\n\n");
    
    
    // ввод данных
    printf("Введите значение m : ");
    if (scanf("%d", &coef_m) == 0){ // ввод и проверка на корректность коэфициента m
        error_message(2);
        return 0;
    }
    printf("Введите значение n : ");
    if (scanf("%d", &coef_n) == 0){ // ввод и проверка на корректность коэфициента n
        error_message(2);
        return 0;
    }
    if (coef_m < 0 || coef_n < 0){ // проверка на отсутствие отрицательных значений
        error_message(1);
        return 0;
    }
    
    
    // вывод результата
    printf("\nХод работы алгоритма:\n\n");
    result = binominal_coef(coef_m, coef_n, 1); // вызов функции, получение результата
    // вывод результата
    printf("\n  %d   \n", coef_m);
    printf("C   =  %d\n", result);
    printf("  %d   \n", coef_n);
    printf("\nПрограмма завершила работу.\n\n");
    
    return 0;
}
