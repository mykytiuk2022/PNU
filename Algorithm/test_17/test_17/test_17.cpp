#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;
const int n = 9;
const int m = 8;
//Матрица iнцедентiв
int GM[n][m] =
{
{1, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 1, 0, 0},
{0, 0, 0, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 1}
}
;
//Стек
stack<int> Q;
//Функцiя пошуку в глибину.
void DFS(bool* visited, int unit)
{
	// Помiчаємо вершину графу як вiдвiдану.
	visited[unit] = true;
	//Помiщаємо першу вершину графу в стек.
	Q.push(unit);
	// Поки стек не стане порожньою.
	while (!Q.empty())
	{
		//Вибiр елементу, що знаходиться на вершинi стеку.
	q1: unit = Q.top();
		//Пошук сусiдiв у матрицi iнцедентiв.
		for (int i = 0; i < m; i++)
		{
			if (GM[unit][i] != 0)
			{
				for (int j = 0; j < n; j++)
					if (GM[j][i] != 0 && visited[j] == false)
					{
						visited[j] = true;
						Q.push(j);
						goto q1;
					}
			}
		}
		//Якщо нових сусiдiв не знайдено, то видаляється вершина зi
			//та вивести її на екран
			cout << " " << Q.top() + 1;
		Q.pop();
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Generator(n);
	int start;
	cout << "Введiть стартову вершина обходу графа » ";
	cin >> start;
	// Масив вершин, що були вiдвiданi.
	bool* visited = new bool[n];
	cout << endl;
	cout << "Матриця iнцедентiв графа: " << endl;
	// Жодна вершина ще не була вiдвiдана.
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		// Вивiд матрицi iнцедентiв.
		for (int j = 0; j < m; j++)
			cout << " " << GM[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "Порядок обходу: " << endl;
	DFS(visited, start - 1);
	delete[]visited;
	cout << endl;
}
