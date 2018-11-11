#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef int type;

struct Stack{
	struct StackElem *topElem;
};

struct StackElem{
	type value;
	struct StackElem *next;
};

short isEmpty(struct Stack *stack){
	if (stack->topElem)
		return 0;
	else 
		return 1;
}

void destroy(struct Stack *stack){
	struct StackElem* tmp = stack->topElem;
	while(stack->topElem){
		tmp = stack->topElem;
		stack->topElem = stack->topElem->next;
		free(tmp);
	}
}

void push(struct Stack *stack, type value){
	struct StackElem* temp = (struct StackElem*) malloc(sizeof(struct StackElem));
	temp->value = value;
	temp->next = stack->topElem;
	stack->topElem = temp;
	printf("%d\n", value);
}

type pop(struct Stack *stack){
	if(isEmpty(stack)){
		printf("Error when trying to pop\n");
		destroy(stack);
		exit(1);
	}
	type value = stack->topElem->value;
	struct StackElem* temp = stack->topElem;
	stack->topElem = stack->topElem->next; 
	free(temp);
	printf("popped: %d\n", value);
	return value;
}

struct Stack initStack(void){
	struct Stack stack = {NULL};
	return stack;
}

int main(){
	struct Stack stack = initStack();
	printf("Input the expression in postfix notation to calculate.\n");
	printf("Beware of the fact that postfix notation should not include any brackets or variables.\n\n");
	char c;
	int a, b, n;
	for(c = getchar(); isspace(c) && c != '\n'; c = getchar());
	ungetc(c, stdin);
	while((c = getchar())!= EOF && c != '\n'){
		for(; isspace(c) && c != '\n'; c = getchar());
		if(isalpha(c)){
			printf("Error! Non-digital symbols found: %c.\n", c);
			destroy(&stack);
			exit(1);
		}
		if(isdigit(c)){
			ungetc(c, stdin);
			scanf("%d", &n);
			printf("pushed: ");
			push(&stack, n);
			continue;
		}
		if(c == '+'){
			a = pop(&stack);
			b = pop(&stack);
			printf("pushed: %d+%d = ", a, b);
			push(&stack, a + b);
			continue;
		}
		if(c == '-'){
			a = pop(&stack);
			b = pop(&stack);
			printf("pushed: %d-%d = ", b, a);
			push(&stack, b - a);
			continue;
		}
		if(c == '*'){
			a = pop(&stack);
			b = pop(&stack);
			printf("pushed: %d*%d = ", a, b);
			push(&stack, a * b);
			continue;
		}
		if(c == '^'){
			a = pop(&stack);
			b = pop(&stack);
			if(a < 0){
				printf("Sorry, don't want to calculate negative powers.\n");
				destroy(&stack);
				exit(0);
			}
			printf("pushed: %d^%d = ", b, a);
			push(&stack, pow(b, a));
			continue;
		}
		printf("Error! Improper symbols found: %c.\n", c);
		destroy(&stack);
		exit(1);
	}
	if(isEmpty(&stack)){
		printf("Empty sequence!\n");
		return 0;
	}
	if(stack.topElem->next)
		printf("Error! Operation expected.\n");
	else
		printf("Result of calculation: %d\n", pop(&stack));
	destroy(&stack);
	return 0;
}