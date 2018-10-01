#include <stdio.h>
#include "L_func.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define N 20

using namespace h_list;

struct STACK{
	long arr[N];
	short topIndex;
	bool flag;
};
typedef struct STACK stack;

void push(stack* Stack, int value){
	(Stack->topIndex)++;
	if(Stack->topIndex == N){
		printf("Stack overflow!\n");
		exit(1);
	}
	Stack->arr[Stack->topIndex] = value;
}
void mul(stack *Stack){
	while(Stack->topIndex){
		Stack->arr[Stack->topIndex-1] *= Stack->arr[Stack->topIndex];
		(Stack->topIndex)--;
	}
}
void add(stack *Stack){
	while(Stack->topIndex){
		Stack->arr[Stack->topIndex-1] += Stack->arr[Stack->topIndex];
		(Stack->topIndex)--;
	}
}
void sub(stack *Stack){
	while(Stack->topIndex){
		Stack->arr[0] -= Stack->arr[Stack->topIndex];
		Stack->topIndex--;
	}
}
void simplify(lisp cur_el, stack *Stack){
	if(!Stack->arr[0] && !Stack->arr[1] || Stack->flag == true){ // case the whole lvl collapses
		h_list::destroy(cur_el->node.pair.hd);
		cur_el->node.pair.hd = new s_expr;
		cur_el->node.pair.hd->tag = true;
		cur_el->node.pair.hd->node.atom.num = Stack->arr[0];
		cur_el->node.pair.hd->node.atom.tag = 0;
		return;
	}
	bool flag;
	if(Stack->arr[0] == 1 && !Stack->arr[1] || !Stack->arr[0] && Stack->arr[1]) // case we have 1 by *, we need to delete all 1's in the list
		flag = false;
	else										//we need to delete all the nums except for the 1st 
		flag = true;
	lisp tmp = cur_el->node.pair.hd;
	lisp prev;
	if(flag == false){ 
		while(h_list::isAtom(tmp->node.pair.hd) && tmp->node.pair.hd->node.atom.tag == 0)
			tmp = tmp->node.pair.tl;
		cur_el = tmp;
	}
	else
		cur_el = cur_el->node.pair.hd;
	while(cur_el != NULL){
		if(h_list::isAtom(cur_el->node.pair.hd) && cur_el->node.pair.hd->node.atom.tag == 0){
			if(flag == true){
				cur_el->node.pair.hd->node.atom.num = Stack->arr[0];
				flag = false;
			}
			else{
				prev->node.pair.tl = cur_el->node.pair.tl;
				delete cur_el;
				cur_el = prev->node.pair.tl;
				continue;
			}
		}
	prev = cur_el;
	cur_el = cur_el->node.pair.tl;
	}
}
short trigcheck(lisp pr_el, lisp cur_el){
	long num = cur_el->node.pair.hd->node.atom.num;
	if(h_list::isAtom(pr_el->node.pair.hd) && pr_el->node.pair.hd->node.atom.tag == 2){
		if(!strcmp(pr_el->node.pair.hd->node.atom.trig, "sin") && !num){
			pr_el->node.pair.hd->tag = true; //we got a zero
			pr_el->node.pair.hd->node.atom.num = 0;
			pr_el->node.pair.hd->node.atom.tag = 0;
			pr_el->node.pair.tl = cur_el->node.pair.tl;
			delete cur_el;
			return 1;
		}
		if(!num){ // not a sin, thus a cos
			pr_el->node.pair.hd->tag = true; //we got a zero
			pr_el->node.pair.hd->node.atom.num = 1;
			pr_el->node.pair.hd->node.atom.tag = 0;
			pr_el->node.pair.tl = cur_el->node.pair.tl;
			delete cur_el;	//got a 1
			return 1;
		}
		return 2;
	}
	return 0;
}
void createBetw(lisp pr_el, lisp cur_el){
	lisp el = new s_expr;
	pr_el->node.pair.tl = el;
	el->tag = false;
	el->node.pair.hd = cur_el;
	el->node.pair.tl = cur_el->node.pair.tl;
	cur_el->node.pair.tl = NULL;
}

void examine(lisp head, lisp pr_el, lisp cur_el, stack *Stack){
	short k;
	if(cur_el == NULL)
		return;
	if(cur_el->tag == false){
		if(!h_list::isAtom(cur_el->node.pair.hd)){
			stack* Stack2 = new stack;
			Stack2->topIndex = -1;
			Stack2->flag = true;
			examine(head, cur_el, cur_el->node.pair.hd, Stack2);
			if(Stack2->topIndex != -1){
				simplify(cur_el, Stack2);
				if(h_list::isAtom(cur_el->node.pair.hd) && cur_el->node.pair.hd->node.atom.tag == 0)
					if((k = trigcheck(pr_el, cur_el)) == 1){
						cur_el = pr_el;
						push(Stack, cur_el->node.pair.hd->node.atom.num);
					}else if(k == 0)
						push(Stack, cur_el->node.pair.hd->node.atom.num);
					else{
						createBetw(pr_el, cur_el);
						cur_el = pr_el->node.pair.tl;
					}
				h_list::write_lisp(head);
				putchar('\n');
			}
			delete Stack2;	
		}
		else												
			examine(head, cur_el, cur_el->node.pair.hd, Stack);
		examine(head, cur_el, cur_el->node.pair.tl, Stack);
	}
	else{
		if(cur_el->node.atom.tag == 0){
			push(Stack, cur_el->node.atom.num);
			return;
		}
		if(cur_el->node.atom.tag == 1 && !isalpha(cur_el->node.atom.ch)){
			if(Stack->topIndex == -1)
				return;
			if(cur_el->node.atom.ch == '*'){
				mul(Stack);
				push(Stack, 0);
				return;
			}
			if(cur_el->node.atom.ch == '+'){
				add(Stack);
				push(Stack, 1);
				return;
			}
			if(cur_el->node.atom.ch == '-'){
				sub(Stack);
				push(Stack, 1);
				return;
			}
		}
		Stack->flag = false;
	}
}

int main(){
	stack* Stack = new stack;
	Stack->topIndex = -1;
	Stack->flag = true;
	lisp L;
	h_list::read_lisp(L);
	if(h_list::isNull(L)){
		printf("Nothing to simplify! Empty list.\n");
		delete Stack;
		return 0;
	}
	lisp el;
	printf("\n\nProcessing:\n");
	examine(L, NULL, L, Stack);
	if(Stack->topIndex != -1){
		el = new s_expr;
		el->node.pair.hd = L;
		el->node.pair.tl = NULL;
		el->tag = false;
		L = el;
		simplify(L, Stack);
	}
	if(L->node.pair.hd->tag == 0){
		el = L;
		L = L->node.pair.hd; 
		delete el;
	}
	printf("\nThe result of simplification of the expression:\n");
	h_list::write_lisp(L);
	delete Stack;
	h_list::destroy(L);
	putchar('\n');
	return 0;
}