#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>

using namespace std;

template <typename T> class Forest {
public:
	T root;
	int sonFrt;
	int broFrt;

	Forest() { sonFrt = -1; broFrt = -1; }
	int son() {	return sonFrt; }
	int bro() {	return broFrt; }
	T rt() { return root; }
	void enterRt(T x) {	root = x; }
};

class Queue {
	Forest<char> element[20];
	int first;
	int last;
public:
	Queue() { first = 0; last = 0; }
	bool isNull() {
		if (first == last) return 1;
		return 0;
	}
	void push(Forest<char> x) { element[last++] = x; }
	Forest<char> pop() { return element[first++]; }
	char topRt() { return element[first].root; }
};

char *ptrStart;      //Начало выражения

bool askEnterBracket();
void error(char **);
int readFrt(Forest<char> *, int &, char **);
int printForest(Forest<char> *, int index = 0, int deep = 0);
void printBT(Forest<char> *, int index = 0, int deep = 0);
void ForestForWidth(Forest<char> *, Queue *, int index = 0);

int main(int argc, char **argv) {
        if (argc != 2){
                cout << "Fail with number of arguments" << endl;
                return 0;
                }
        setlocale(LC_ALL, "rus");
	char x[20];
	strcpy(x,argv[1]);
	ifstream infile(x, ios::in | ios::binary);        //Открытие файла для чтения
	if (!infile) { cout << "File not open for reading!\n"; exit(1); }
	char strin[80] = "0";
	char *str = &strin[0];
	ptrStart = &strin[0];
	infile.get(strin, 60);
	infile.close();
	cout << "Forest: " << str << "\n\n";
	Forest<char> forest[20];
	Forest<char> *ptr = &forest[0];
	int index = 0;
	cout << "Reading of forest:\n";
	readFrt(&ptr[0], index, &str);       //Функция чтения леса
	cout << "\nPicture of forest:\n";
	printForest(ptr);                //Вывод изображения леса
	cout << "\nPicture of binary tree:\n";
	printBT(ptr);                        //Вывод изображения бинарного дерева
	Queue queue, *ptrQ;
	ptrQ = &queue;
	cout << "\nEnumeration of forest elements in horizontal order\n";
	ForestForWidth(ptr, ptrQ);           //Проход по лесу в ширину
	cout << endl;
	return 0;
}

void error(char **str) {//Функция, выводящая результат проверки выражения на скобку.
	cout << "ERROR\n";
	int x = strlen(ptrStart) - strlen(*str);
	while (*ptrStart) {
		printf("%c", *ptrStart);
		*(++ptrStart);
		if (!(--x))       //Отображается пробел, в месте, где сейчас находится указатель.
			cout << "<X>";
	}
	cout << endl;
	cout <<" <X> - Indicates the location of the error" << endl;
	cout << endl;
	exit(1);
}


int readFrt(Forest<char> *ptr, int &index, char **str) {
	int temp = index;
	if (**str == '(' && *(*str + 1) <= 'Z' && *(*str + 1) >= 'A') {
		cout << "Entrance to function tree " << *str << endl;
		++*str;
		ptr[temp].enterRt(*((*str)++));
		cout << "\tPush " << *(*str - 1) << " in " << temp << endl;
		if (**str == '(') {
			cout << "\t\tEntrance to Son " << *str << endl;
			cout <<"------------------------------------------"<< endl;
			ptr[temp].sonFrt = readFrt(ptr, ++index, str);
			if (ptr[temp].son() != -1)
				cout << "\t\tSon from " << ptr[temp].rt() << " is " << ptr[ptr[temp].son()].rt() << endl;
			else cout << "\t\tSon from " << ptr[temp].rt() << " is NULL\n" << endl;
			++*str;
			cout <<"------------------------------------------"<< endl;
		}
		if (**str == ')' && *(*str + 1) == '(') {
			cout << "\t\tEntrance to Bro " << *str << endl;
			cout <<"------------------------------------------"<< endl;
			++*str;
			ptr[temp].broFrt = readFrt(ptr, ++index, str);
			if (ptr[temp].bro() != -1)
				cout << "\t\tBro from " << ptr[temp].rt() << " is " << ptr[ptr[temp].bro()].rt() << endl;
			else cout << "\t\tBro from " << ptr[temp].rt() << " is NULL\n" << endl;
			cout <<"------------------------------------------"<< endl;
		}
		cout << "Exit from function tree " << *str << endl;
		if (!(**str == '(' || **str == ')' || (*(*str + 1) <= 'Z' && *(*str + 1) >= 'A')))
			error(str);
		return temp;
	}
	else error(str);
}


int printForest(Forest<char> *ptr, int index, int deep) {
	int returnPoints = 0;
	for (int i = 0; i < deep; i++)
		cout << ' ';
	cout << ptr[index].rt() << endl;
	if(ptr[index].son() != -1)
		returnPoints = printForest(ptr, (index + 1), (deep + 2));
	if (ptr[index].bro() != -1)
		returnPoints = printForest(ptr, (index + 1 + returnPoints), deep);
	return ++returnPoints;
}


void printBT(Forest<char> *ptr,int index, int deep) {
	for (int i = 0; i < deep; i++)
		cout << ' ';
	cout << ptr[index].rt() << endl;
	if (ptr[index].son() != -1) {
		printBT(ptr, ptr[index].son(), deep + 2);
	}
	if (ptr[index].son() == -1 && ptr[index].bro() != -1) {
		for (int i = 0; i < deep + 2; i++)
			cout << ' ';
		cout << '^' << endl;
	}
	if (ptr[index].bro() != -1) {
		printBT(ptr, ptr[index].bro(), deep + 2);
	}
	if (ptr[index].son() != -1 && ptr[index].bro() == -1) {
		for (int i = 0; i < deep + 2; i++)
			cout << ' ';
		cout << '^' << endl;
	}
}


void ForestForWidth(Forest<char> *ptr, Queue *queue, int index) {
	cout << ptr[index].rt() << ' ';
	if (ptr[index].son() != -1) {
		queue->push(ptr[index]);
		//cout << "Push " << ptr[index].rt() << endl;
	}
	if (ptr[index].bro() != -1) {
		//cout << "Entrance to Bro\n";                      //Закомментированные строки используются
		ForestForWidth(ptr, queue, ptr[index].bro());
		//cout << "Exit from Bro\n";                        //для вывода промежуточных результатов
	}
	if (!queue->isNull()) {
		ptr[index] = queue->pop();
		//cout << "Pop " << ptr[index].rt() << endl;
		if (ptr[index].son() != -1) {
			//cout << "Entrance to Son\n";
			ForestForWidth(ptr, queue, ptr[index].son());
			//cout << "Exit from Son\n";
		}
	}
}
