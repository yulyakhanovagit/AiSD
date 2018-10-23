#include <stdio.h>
#include "L_func.h"

using namespace h_list;

bool explore(lisp L1, lisp L2){
	if(L1 == NULL && L2 == NULL)
		return true;
	if(L1 == NULL || L2 == NULL)
		return false;
	if(h_list::isAtom(L1) && h_list::isAtom(L2)){   //если оба элемнта атомы
		printf("Found atoms.\n");
		printf("%c %c\n", L1->node.atom, L2->node.atom);
		if(L1->node.atom == L2->node.atom){			//проверка атомов на идентичность
			printf("Atoms are identical.\n");
			return true;
		}
		else
			printf("Atoms are different.\n");
	} 
	
	if(!h_list::isAtom(L1) && !h_list::isAtom(L2)){	//если вложенные списки
		printf("Found hierarchical lists.\n");
		if(!explore(L1->node.pair.hd, L2->node.pair.hd))
			return false;
		else
			return explore(L1->node.pair.tl, L2->node.pair.tl);
	}
	return false;
}

int main(){
	lisp L1, L2;
	//printf("Input first list:\n");
	h_list::read_lisp(L1);
	//printf("Input second list:\n");
	h_list::read_lisp(L2);
	if(explore(L1, L2))
		printf("These two lists are identical.\n");
	else
		printf("These two lists are different.\n");
	h_list::destroy(L1);
	h_list::destroy(L2);
	return 0;
}