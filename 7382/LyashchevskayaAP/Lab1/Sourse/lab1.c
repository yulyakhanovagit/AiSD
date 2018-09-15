#include <stdio.h>
#include <stdlib.h>

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
	int length;
	printf("Enter length your vector:\n");
	scanf("%d", &length);

	int *vector = (int *)malloc(length * sizeof(int));		//The memory allocation of the initial vector
	int *vectorNew = (int *)malloc(length * sizeof(int));		//and changed vector

	printf("Enter your vector, like example: <1 2 3 4 5>\n");
	for(int i = 0; i < length; i++)					//Reading a vector
		scanf("%d", &vector[i]);

	rec(0, length, vector, vectorNew);

	printf("Changed vector look like this:\n");
	for(int i = 0; i < length; i++)					//Print chandged vector
		printf("%d ", vectorNew[i]);
	printf("\n");
	return 0;
}
