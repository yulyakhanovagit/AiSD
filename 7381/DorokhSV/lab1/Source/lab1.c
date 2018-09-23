//Вариант №6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_Valid(char *buffer) {
    if (strlen(buffer) == 1)
         return isalpha(buffer[0]);
    else if (!strlen(buffer))
        return 0;

    char *first_brackets;                                   //Указатели, которые будут строками после разделения исходного выражения
    char *second_brackets;                                  //

    int bracket_count = 0;
    int i = 1;
    do {                                                    //Начало блока 
        if (buffer[i] == '(')                               //по нахождению закрывающейся скобки
            bracket_count++;                                //для соответствующей открывающейся 
        if (buffer[i] == ')')
            bracket_count--;
        i++;
        if(buffer[i] == '\0' && bracket_count != 0){
            printf("Different number of brackets!\n");
            return 0;                                       
        }                                                   //
    } while (bracket_count != 0 && i <= strlen(buffer));    //

    if(buffer[i] != '+' && buffer[i] != '-' && buffer[i] != '*'){        //Проверка знака в выражении
        printf("%d element is an invalid character!\n", i);              //на его валидность
        return 0;
    }

    buffer[strlen(buffer)-1] = '\0';                        //Разделение строк
    first_brackets = buffer + 1;                            //на строку до знака выражения
    second_brackets = buffer + i + 1;                       //и строку после знака
    buffer[i] = '\0';

    if (is_Valid(first_brackets) && is_Valid(second_brackets)) {    //Одновременный вызов исходной функции для получившихся строк
        return 1;
    } 
    return 0;


}

int main(){
    char *buffer=malloc(sizeof(char)*50);
    fgets(buffer, 50, stdin);
    printf("%s\n", buffer);
    if (buffer[strlen(buffer) - 1] == '\n')
		buffer[strlen(buffer) - 1] = '\0';
    printf(is_Valid(buffer) ? "This expression is correct!\n" : "This expression is incorrect!\n");
    free(buffer);
}