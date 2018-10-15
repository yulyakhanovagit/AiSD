#include<iostream>
#include<fstream>
using namespace std;

enum ANALISIS_RESULT{    //Перечисление констант
    OK,
    INCORRECT_SIGN,
    CLOSE_BRACKET_ERROR,
    UNKNOWN_SYMBOL,
    DELIMETER_MISS
};
void printResult(ostream &out, ANALISIS_RESULT res){          //Функция вывода
    switch(res){
    case OK:                   out<<"  / OK"						 <<endl; return;
    case INCORRECT_SIGN:       out<<"  / Некорректный знак, ожидался знак + - *"         <<endl; return;
    case CLOSE_BRACKET_ERROR:  out<<"  / Отсутствует закрывающая скобка"                 <<endl; return;
    case UNKNOWN_SYMBOL:       out<<"  / Неизвестный символ, ожидалось выражение"        <<endl; return;
    case DELIMETER_MISS:       out<<"  / Неизвестный символ, ожидался конец выражения"   <<endl; return;
    }
}
bool isSign(char c){                     //Функция, проверяющая являеться ли символ знаком +, - или *
    return c=='-'||c=='+'||c=='*';
}
bool isLetter(char c){                  //Функция, проверяющая являеться ли символ буквой верхнего или нижнего регистра
    return 'a'<=c&&'z'>=c || 'A'<=c&&'Z'>=c;
}
ANALISIS_RESULT analisis(istream &in,ostream &out){
							/*
							Функция производит синтаксический анализ строки.
							Не контролирует наличие лишних символов после вырожения.
							*/
    if(isLetter(in.peek())){
        out<<(char)in.get();
        return OK;
    }
    if('('==in.peek()){
        out<<(char)in.get();
        ANALISIS_RESULT res=analisis(in, out);
        if(OK!=res)return res;
        if(!isSign(in.peek())){
            out<<(char)in.peek();
            return INCORRECT_SIGN;
        }
        out<<(char)in.get();
        res=analisis(in,out);
        if(OK!=res)return res;
        if(in.peek()!=')'){
            out<<(char)in.peek();
            return CLOSE_BRACKET_ERROR;
        }
        out<<(char)in.get();
        return OK;
    }
    out<<(char)in.peek();
    return UNKNOWN_SYMBOL;
}
ANALISIS_RESULT analisisAndControlLastSymbol(istream &in,ostream &out){
									/*
									Аналог функции analisis, но проверяет дополнительно,
									чтобы после завершения разбора в строке не присутствовали лишние символы
									*/
    ANALISIS_RESULT res=analisis(in,out);
    if(OK!=res)return res;
    if(in.peek()!='\n'&&in.peek()!=' '&&in.peek()!='\0'&&in.peek()!=EOF){
        out<<(char)in.peek();
        return DELIMETER_MISS;
    }
    return OK;
}

int main(){
    setlocale(LC_ALL, "rus");
	std::cout<<"Строка: ";
	ANALISIS_RESULT res=analisisAndControlLastSymbol(cin,cout);
    printResult(cout,res);
    return 0;
}

