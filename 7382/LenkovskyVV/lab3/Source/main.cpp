#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <string.h>
#include <stdarg.h>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;

void call_error(Queue & Q3, char symb, int numb) // функция показывающая место ошибки
{
	cout << ",который не удовлетворяет условиям формулы." << endl;
	cout << "Это не формула!" << endl;
	switch (numb)
	{
	case 1:
	{
		cout << "Ожидалось имя, типа [x],[y],[z], или открывающая скобка - [(]." << endl;
		break;
	}
	case 2:
	{
		cout << "Ожидался знак, типа [+],[-], или закрывающая скобка - [)]." << endl;
		break;
	}
	default: break;
	}
	cout << "Часть строки, которая является формулой и может быть завершена." << endl;
	while (Q3.can_pop())
		cout << Q3.pop() << " ";
	cout << "\nПрограмма будет завершена." << endl;
	exit(1);
}
bool checkCloseBkt(char symb)  // проверка закрывающей скобки
{
	if (symb == ')')
		return true;
	else
		return false;
}
bool checkOpenBkt(char symb) // проверка открывающей скобки
{
	if (symb == '(')
		return true;
	else
		return false;
}
bool checkSign(char symb)    // проерка является эллемент знаком
{
	if (symb == '+' || symb == '-')
		return true;
	else
		return false;
}
bool checkSymb(char symb)      // проверка является ли элеммент именем
{
	if (symb == 'x' || symb == 'y' || symb == 'z')
		return true;
	else
		return false;
}
bool checkForm(Stack Q1, Queue & Q3)   // является ли строка формулой
{
	char symb;
	bool name = true;
	bool sign = false;
	bool bracket_c = false;
	bool bracket_o = true;
	bool is_el = false;
	int open = 0;
	int close = 0;
	while (Q1.can_pop())
	{
		symb = Q1.pop();
		cout << "Из стека извлечен элемент [" << symb << "] ";
		is_el = false;
		if (!is_el && name && checkSymb(symb))
		{
			cout << ",который является именем. " << endl;
			is_el = true;
			name = false;
			sign = true;
			bracket_c = true;
			bracket_o = false;
			Q3.push(symb);
		}
		if (!is_el && sign && checkSign(symb))
		{
			cout << ",который является знаком." << endl;
			is_el = true;
			name = true;
			sign = false;
			bracket_c = false;
			bracket_o = true;
			Q3.push(symb);
		}
		if (!is_el && bracket_o && checkOpenBkt(symb))
		{
			cout << ",который является открывающей скобкой. " << endl;
			is_el = true;
			bracket_o = true;
			bracket_c = false;
			name = true;
			sign = false;
			open++;
			Q3.push(symb);
		}
		if (!is_el && bracket_c && checkCloseBkt(symb))
		{
			close++;
			cout << ",который является закрывающей скобкой." << endl;
			if (close <= open)
			{
				close--;
				open--;
				is_el = true;
				bracket_o = false;
				bracket_c = true;
				name = false;
				sign = true;
				Q3.push(symb);
			}
			else
				call_error(Q3, symb, 2);
		}
		if (!is_el && (name && bracket_o))
			call_error(Q3, symb, 1);
		else
			if (!is_el && (sign && bracket_c))
				call_error(Q3, symb, 2);
	}
	if (open != close)
		call_error(Q3, symb, 2);
	return true;
}
void printForm(Queue & Q3)      // вывести формулу
{
	while (Q3.can_pop())
	{
		cout << Q3.pop() << " ";
	}
}
void checkCondition(ifstream & fin, Stack & Q2)   // функция в которой проверятся условие является ли формулой
{
	Queue Q3;
	int n = 1;
	char symb;
	fin >> symb;
	while (!(fin.eof()))
	{
		Q2.push(symb);
		Q3.push(symb);
		fin >> symb;
	}
	Stack Q1;
	cout << "Заносим элементы строки в стек:" << endl;
	while (Q2.can_pop())
	{
		char a = Q2.pop();
		cout << "В стек помещен элемент [" << a << "]." << endl;
		Q1.push(a);
	}
	cout << "Считанная из файла строка.";
	printForm(Q3);
	cout << endl;
	bool f = checkForm(Q1, Q3);
	cout << "Это формула." << endl;
	cout << "Ее вид: " << endl;
	printForm(Q3);
}
int main(int argc, char **argv)
{
	if (argc != 2)
		{
		cout << "Fail with number of arguments" << endl;
		return 0;
		}
	setlocale(LC_ALL, "rus");
	int answer=1;
	char x[20];
	strcpy(x,argv[1]);
	if (answer == 1)
	{
		ifstream fin(x);
		Stack Q2;
		checkCondition(fin, Q2);
		fin.close();
	}
	else
		cout << "Работа будет завершена." << endl;
	cout << endl;
}
