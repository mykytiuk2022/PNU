#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;
const int n = 9;
const int m = 8;
//������� i�������i�
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
//����
stack<int> Q;
//�����i� ������ � �������.
void DFS(bool* visited, int unit)
{
	// ���i���� ������� ����� �� �i��i����.
	visited[unit] = true;
	//���i���� ����� ������� ����� � ����.
	Q.push(unit);
	// ���� ���� �� ����� ���������.
	while (!Q.empty())
	{
		//���i� ��������, �� ����������� �� ������i �����.
	q1: unit = Q.top();
		//����� ���i�i� � ������i i�������i�.
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
		//���� ����� ���i�i� �� ��������, �� ����������� ������� �i
			//�� ������� �� �� �����
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
	cout << "����i�� �������� ������� ������ ����� � ";
	cin >> start;
	// ����� ������, �� ���� �i��i���i.
	bool* visited = new bool[n];
	cout << endl;
	cout << "������� i�������i� �����: " << endl;
	// ����� ������� �� �� ���� �i��i����.
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		// ���i� ������i i�������i�.
		for (int j = 0; j < m; j++)
			cout << " " << GM[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "������� ������: " << endl;
	DFS(visited, start - 1);
	delete[]visited;
	cout << endl;
}
