#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <windows.h>
#include "stack.h"
#include <cstring>
using namespace std;


int F(char *str,int *i, Array_stack * S){
	int a,b,res;

	if ((str[*i] >= '0') && (str[*i] <= '9') ) { 		//если цифра от 0 до 9 
		S->push(str[*i]);
		cout << "pushed:" << str[*i] << endl;
		return 0;																		 
	}

	if ((str[*i] == 'M')  && (str[*i+1] == '(') ) { 
		*i=(*i)+2;                      				 //если М и за ней (
		if((F(str, i, S) == 0) && (str[*i+1] == ','))	{	  //ищем первый аргумент
			*i=(*i)+2;
			if((F(str, i, S) == 0) && (str[*i+1] == ')')){
				a = S->pop();
				cout << "poped:" << a - 48 << endl;
				b = S->pop();
				cout << "poped:" << b - 48 << endl;
				res = max(a,b);
				S->push(res);
				cout << "pushed:" << res - 48 << endl;
				*i=(*i)+1;
				return 0;
			}	
		}
	}

	if ((str[*i] == 'm')  && (str[*i+1] == '(') ) { 
		*i=(*i)+2;                                 			 //если m и за ней (
		if((F(str, i, S) == 0) && (str[*i+1] == ','))	{	 //ищем первый аргумент
			*i=(*i)+2;
			if((F(str, i, S) == 0) && (str[*i+1] == ')')){
					a = S->pop();
				cout << "poped:" << a - 48 << endl;
				b = S->pop();
				cout << "poped:" << b - 48 << endl;
				res = min(a,b);
				S->push(res);
				cout << "pushed:" << res - 48 << endl;
				*i=(*i)+1;
				return 0;
			}	
		}
	}
	
		return (-1);
}


int main(){
char ch;
int i = 0;
int size = 10;
char *str = new char [size];
	cout << "Ведите формулу вида " <<endl;
 	cout << "<формула> ::= <цифра> | M(<формула>,<формула>) | m(<формула>,<формула>) " <<endl;
 	cout << "<цифра> ::= 0|1|...|9 " <<endl;

Array_stack S;

while(1){
	std::cin >> std::noskipws >> ch;

	if(i+1 == size){
		str[i]='\0';
		char *copy = new char [size];
		strncpy(copy,str,size);
		delete []str;
		size*=2;
		str = new char [size];
		strncpy(str,copy,size/2);
		delete []copy;
	}
	if(ch == '\n'){
		str[i]='\0';
		break;
	}
	str[i]=ch;
	i++;


	
}

i=0;

int result = F(str, &i, &S);

if((str[i+1] != '\0') || (result != 0))
	cout << "Строка некорректна! ";

else if(result== 0)
	cout << "Результат: " << S.pop() <<endl;

delete []str;
return 0;
}
