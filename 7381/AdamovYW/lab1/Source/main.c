#include  <stdio.h>

// сообщения об ошибках
void error_message(int numb_of_error){
    printf("\nОшибка: ");
    switch (numb_of_error){
        case 1:
            printf("вы ввели отрицательное значение.\n");
            break;
        case 2:
            printf("m > n\n");
            break;
        case 3:
            printf("необходима ввести целое число.\n");
            break;
    }
    printf("Программа завершила работу.\n\n");
}


// поиск значения биноманального коэфициента рекурсивным способом
int binominal_coef(int m , int n, int level){
    int i;
    for(i = 0; i < level; i++) // создание отступов
        printf("    ");
    printf("call: m = %d, n = %d ; ", m, n);
    if (m == 0 || m == n){
        printf("return 1\n");
        return 1;
    } else if (m > n){
        printf("return 0\n");
        return 1;
    } else {
        printf("return C(%d,%d) + C(%d,%d)\n", m-1, n-1, m, n-1);
        return binominal_coef(m-1, n-1, level+1) + binominal_coef(m, n-1, level+1);
    }
}


int main(void){
    
    int m, n, result;
    
    
    // описание программы
    printf("\nПрограмма для вычисления биноминальных коэффициентов.\n");
    printf("Вычисление происходит рекурсивно.\n");
    printf("\n  m   | 1, если m = 0, n = 0 или m = n >= 0,\n");
    printf("C   = | 0, если m > n >= 0,\n");
    printf("  n   | C(m-1, n-1) + C(m, n-1) в остальных случаях.\n");
    printf("\nЗначения m и n - целые неотрицательные числа.\n\n");
    
    
    // ввод данных
    printf("Введите значение m : ");
    if (scanf("%d", &m) == 0){
        error_message(3);
        return 0;
    }
    printf("Введите значение n : ");
    if (scanf("%d", &n) == 0){
        error_message(3);
        return 0;
    }
    if (m < 0 || n < 0){
        error_message(1);
        return 0;
    }
    if (m > n){
        error_message(2);
        return 0;
    }
    
    
    // вывод результата
    printf("\nХод работы алгоритма:\n\n");
    result = binominal_coef(m, n, 1);
    printf("\n  %d   \n", m);
    printf("C   =  %d\n", result);
    printf("  %d   \n", n);
    printf("\nПрограмма завершила работу.\n\n");
    
    return 0;
}
