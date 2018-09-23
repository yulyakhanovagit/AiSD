#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define start "Start of recursion"
#define end "End of recursion"

int logic(int depth, int* err_flag){

	if(*err_flag){
		printf("%*s\n",16 + depth*4, end);
		return -1;
	} 
	char str[7] ;
	char ch;
	while((ch = getchar()) == ' ');
	printf("%*s\n",18 + depth*4, start);
	if(ch == '('){			//проверка на открывающую скобку
		printf("(\n");
		int arg1 = logic(depth + 1, err_flag);	//считывание первого аргумента
		if(*err_flag == 1){
			printf("%*s\n",16 + depth*4, end);
			return -1;
		}
		int arg2;
		while((ch = getchar()) == ' ')
		;
		int res = -1;
		if(ch == 'A'){
			ungetc(ch, stdin);
			fgets(str, 4, stdin);
		}
		if(ch == 'O'){
			ungetc(ch, stdin);
			fgets(str, 3, stdin);
		}
		if(!strcmp(str, "AND")){
			printf("%*s\n",3 + depth*4, str);
			arg2 = logic(depth + 1, err_flag);	//считывание второго аргумента
			if(*err_flag){						//для операции AND
				printf("%*s\n",16 + depth*4, end);
				return -1; 
			}
			res = arg1 && arg2;
		}
		if(!strcmp(str, "OR")){
			printf("%*s\n", 2 + depth*4, str);
			arg2 = logic(depth + 1, err_flag);	//считывание второго аргумента
			if(*err_flag){						//для операции OR
				printf("%*s\n",16 + depth*4, end);
				return -1; 
			}
			res = arg1 || arg2;
		}
		if(res == -1){
			*err_flag = 1;
			printf("%*s\n",16 + depth*4, end);
			return -1;
		}
		while((ch = getchar()) == ' ')
			;
		if(ch != ')'){
			*err_flag = 1; // (true and (false and false))
			printf("%*s\n",16 + depth*4, end);
			return -1;
		}
		else{
			printf(")\n");
			printf("%*s\n",16 + depth*4, end);
			return res;
		}
	}
	if(ch == 'T'){
		ungetc(ch, stdin);
		fgets(str, 5, stdin);
	}
	if(ch == 'F'){
		ungetc(ch, stdin);
		fgets(str, 6, stdin);
	}
	if(ch == 'N'){
		ungetc(ch, stdin);
		fgets(str, 4, stdin);
	}
	if(!strcmp(str, "TRUE")){
		printf("%*s\n", 4 + depth*4, str);
		printf("%*s\n",16 + depth*4, end);
		return 1;
	}
	if(!strcmp(str, "FALSE")){
		printf("%*s\n", 5 + depth*4, str);
		printf("%*s\n",16 + depth*4, end);
		return 0;
	}
	if(!strcmp(str, "NOT")){
		printf("%*s\n", 3 + depth*4, str);
		printf("%*s\n",16 + depth*4, end);
		return !logic(depth + 1, err_flag);
	}
	*err_flag = 1;
	printf("%*s\n",16 + depth*4, end);
	return -1;
}
int main(){
	int err_flag = 0;
	char ch;
	int res = logic(0, &err_flag);
	if(err_flag){
		printf("Syntax error!\n\n");
		return 0;
	}
	while((ch = getchar()) == ' ')
		;
	if(ch != '\n' && ch != EOF){
		printf("Extra symbols found\n\n");
		return 0;
	}
	if(res)
		printf("TRUE\n\n");
	else
		printf("FALSE\n\n");
	return 0;
}