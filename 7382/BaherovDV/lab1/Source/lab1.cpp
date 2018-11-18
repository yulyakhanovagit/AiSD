#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/* Функция, которая определяет: существует ли путь между двумя вершинами.
Для этого создаем массив в котором храним номер компоненты связности для каждой вершины. Затем достаточно узнать,
в одной ли компоненте связности находятся заданные вершины 
*/
bool find_way(int n, int town_i, int town_j, bool** road);

/*   Рекурсивная функция "Поиск в глубину"
Идея: для каждой непройденной вершины находим все непройденные смежные вершины и повторяем поиск для них 
*/

void search_in_depth(int n, int current_top, int* components, int& num_components, bool* visited, bool** road, int count);

/*  Функция ввода городов, между которыми существует путь,
возвращает возможную ошибку при некорректном вводе n
*/

int input_roads(int n, bool** road, int num_ways, std::istream& in);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;               // количество городов
	bool **road;             // матрица смежности
	int town_i = 0;          // начальный город
	int town_j = 0;          // конечный город 
	int num_ways = 0;        // общее количество существующих путей 
	cout << "Введите количество городов: " << endl;
	cin >> n;

	cout << "Введите количество путей: ";
	cin >> num_ways;

	road = new bool*[n];
	for (int i = 0; i < n; i++)
		road[i] = new bool[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			road[i][j] = 0;

	cout << "ведите номера городов, между которыми существует дорога: " << endl;
	int res = input_roads(n, road, num_ways, cin);

	if (res == 1)
	{
		cout << "Неверно введены даннные о городах (выход за пределы границ 1<=town<=n)" << endl;
		return -1;
	}
	if (res == 2)
	{
		cout << "Ошибка! По условию i < j" << endl;
		return -1;
	}

	cout << "Введите города, между которыми нужно узнать существование пути: " << endl;
	cin >> town_i >> town_j;
	town_i--;
	town_j--;
	cout << endl;
	
	cout << "Матрица смежности:  \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << road[i][j] << " ";
		cout << endl;
	}

	if (find_way(n, town_i, town_j, road))
		cout << "\nПуть между городами " << town_i + 1 << " и " << town_j + 1 << " существует." << endl;
	else
		cout << "\nПуть между городами " << town_i + 1 << " и " << town_j + 1 << " не существует." << endl;
	for (int i = 0; i < n; i++)
		delete[] road[i];
	delete[] road;
	road = NULL;
	system("pause");
	return 0;
}

int input_roads(int n, bool** road, int num_ways, std::istream& in)
{
	int town_i, town_j;
	for(int i = 0; i < num_ways; i++)
	{
		in >> town_i;
		in >> town_j;
		if (town_i >= town_j)
			return 2;
		if ((town_i < 1) || (town_i > n) || (town_j < 1) || (town_j > n))
			return 1;
		road[town_i - 1][town_j - 1] = true;
		road[town_j - 1][town_i - 1] = true;
	}
	return -1;
}

bool find_way(int n, int town_i, int town_j, bool** road)
{
	bool *visited;               //  указатель на массив, в котром хранится информация о посещении вершин 
	int *components;             //  указатель на массив номеров компонент связности для каждой вершины
	int num_components = 0;      //  количество компонент связности вершины 
	components = new int[n];
	visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		components[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			search_in_depth(n, i, components, num_components, visited, road, 0);
			num_components++;
		}
	}
	if (components[town_i] == components[town_j])
		return true;
	else return false;	
}

void search_in_depth(int n, int current_top, int* components, int& num_components, bool* visited, bool** road, int count)
{
	components[current_top] = num_components;
	visited[current_top] = true;
	for(int i=0; i < count; i++){
		cout << "\t";
	}
	cout << "Глубина рекурсии: " << count << endl;

	for (int j = 0; j < n; j++) 
	{
		if (road[current_top][j] != 0)
			if (!visited[j])
				search_in_depth(n, j, components, num_components, visited, road, ++count);
	}
	count--;
}
