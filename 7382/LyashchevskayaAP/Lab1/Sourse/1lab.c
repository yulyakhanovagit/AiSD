#include <stdio.h>
#include <stdlib.h>

int rec(int indent, int length, int *vector, int *vectorNew){
	for(int i = 0; i < indent; i++)	printf("\t");
	printf("> rec with vector: ");
	for(int i = 0; i < length; i++)	printf("%d ", vector[i]);
	printf("\n");

	int halfl = length/2;
	if(length > 2)
		rec(indent + 1, length - halfl, vector, vectorNew) &
		rec(indent + 1, halfl, vector + length - halfl, vectorNew + length - halfl);
	if(length == 2)
		(vectorNew[0] = (vector[0] <= vector[1]) ? vector[0] : vector[1]) &
		(vectorNew[1] = (vector[0] <= vector[1]) ? vector[1] : vector[0]);
	if(length == 1)
		vectorNew[0] = vector[0];

	for(int i = 0; i < indent; i++)	printf("\t");
	printf("< rec\n");
}

int main(){
	int length;
	printf("Enter length your vector:\n");
	scanf("%d", &length);

	int *vector = (int *)malloc(length * sizeof(int));
	int *vectorNew = (int *)malloc(length * sizeof(int));

	printf("Enter your vector, like example: <1 2 3 4 5>\n");
	for(int i = 0; i < length ; i++)
		scanf("%d", &vector[i]);

	rec(0, length, vector, vectorNew);

	printf("Changed vector look like this:\n");
	for(int i = 0; i < length ; i++)
		printf("%d ", vectorNew[i]);
	printf("\n");
	return 0;
}
