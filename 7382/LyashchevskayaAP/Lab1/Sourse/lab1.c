#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

void abort_(const char * s, ...)					//Insert in case of incorrect length string
{
        va_list args;
        va_start(args, s);
        vfprintf(stderr, s, args);
        fprintf(stderr, "\n");
        va_end(args);
        abort();
}

int is_valid_string(char *string){					//Function check valid of string
	for(int i = 0; i < strlen(string); i++)
		if(!isdigit(string[i])){
			printf("alpha!");
			return 0;
		}
	return 1;
}

int rec(int indent, int length, int *vector, int *vectorNew){
	for(int i = 0; i < indent; i++)	printf("\t");			//Print the desired number of indents
	printf("> rec with vector: ");
	for(int i = 0; i < length; i++)	printf("%d ", vector[i]);	//Print current vector
	printf("\n");

	int halfl = length/2;
	if(length > 2)							//Case of using functions in a function
		rec(indent + 1, length - halfl, vector, vectorNew) &
		rec(indent + 1, halfl, vector + length - halfl, vectorNew + length - halfl);
	if(length == 2)							//Case of distribution of two vectors in ascending order
		(vectorNew[0] = (vector[0] <= vector[1]) ? vector[0] : vector[1]) &
		(vectorNew[1] = (vector[0] <= vector[1]) ? vector[1] : vector[0]);
	if(length == 1)							//Case of ordinary overwriting the vector
		vectorNew[0] = vector[0];

	for(int i = 0; i < indent; i++)	printf("\t");			//Print the desired number of indents
	printf("< rec\n");
}

int main(){
	char * str = (char *)malloc(50 * sizeof(char));
	printf("Enter your vector length:\n");
	scanf("%s", str);

	if(!is_valid_string(str))
		abort_("You enter incorrect value of string\n");

	int length = atoi(str);

	int *vector = (int *)malloc(length * sizeof(int));		//The memory allocation of the initial vector
	int *vectorNew = (int *)malloc(length * sizeof(int));		//and changed vector

	printf("Enter your vector, like example: <1 2 3 4 5>. Without brackets! Only digits!\n");
	for(int i = 0; i < length; i++)					//Reading a vector
		scanf("%d", &vector[i]);

	rec(0, length, vector, vectorNew);

	printf("Changed vector look like this:\n");
	for(int i = 0; i < length; i++)					//Print chandged vector
		printf("%d ", vectorNew[i]);
	printf("\n");
	return 0;
}
