#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BRACKETS "brackets"
#define LEN 8
#define OFFSET 4
#define BLOCK 50

enum err_num {err1 = 1, err2, err3, err4, err5, err6};

void Error(enum err_num ERR, char* str){
	switch(ERR){
		case 1: 
			printf("\nProcessed sequence: %s\nError! Expected: ')'.\n", str);
			break;
		case 2:
			printf("\nProcessed sequence: %s\nError! Expected: 'A', 'B' or '('.\n", str);
			break;
		case 3:
			printf("\nProcessed sequence: %s\nError! Wrong symbol found.\n", str);
			break;
		case 4:
			printf("\nNot a sequence has been entered.\n");
			break;
		case 5:
			printf("\nProcessed sequence: %s\nExtra symbols found!\n", str);
			break;
		default:
			printf("\nWrong err_num received.\n");
	}
}

int brackets(int k, char* str, int* i, int* block_num){					// brackets ::= A | B | (brackets brackets)
	printf("%*s ", LEN + k*OFFSET, BRACKETS);
	k++;
	char ch = getchar();
	printf("*proccesing '%c'*\n", ch);
	if(strlen(str) + 2 == (*block_num)*BLOCK){ // +2 for not writing the same stuff on ln 50-54
		(*block_num)++;
		str = realloc(str, (*block_num)*BLOCK);
	}
	if(ch == 'A' || ch == 'B'){
		str[*i] = ch;
		(*i)++;
		str[*i] = '\0';
		return 1;
	}
	if(ch == '('){
		str[*i] = ch;
		(*i)++;
		str[*i] = '\0';
		if(!(brackets(k, str, i, block_num) && brackets(k, str, i, block_num)))
			return 0;
		ch = getchar();
		if(ch != ')'){
			Error(1, str);
			return 0;
		}
		else{
			str[*i] = ch;
			(*i)++;
			str[*i] = '\0';
			return 1;
		}
	}
	if(ch == '\n' || ch == ')' || ch == EOF){
		Error(2, str);
		return 0;
	}
	Error(3, str);
	return 0;
}

int main(){
	char ch;
	ch = getchar();
	if(ch == EOF || ch == '\n'){
		Error(4, NULL);
		return 0;
	}
	else
		ungetc(ch, stdin);
	char* str = malloc(BLOCK);
	str[0] = '\0';
	int block_num = 1;
	int i = 0;		//processing symbol
	if(brackets(0, str, &i, &block_num))
			if((ch = getchar()) == '\n' || ch == EOF)
				printf("The input sequence is indeed brackets.\n");
			else
				Error(5, str);
	free(str);
	return 0;
}