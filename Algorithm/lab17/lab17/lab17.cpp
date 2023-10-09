#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <Windows.h>
#include <stack>

using namespace std;

vector<vector<int>> readMatrixFromFile(const string& filename, int col) {
    vector<vector<int>> matrix;
    ifstream file(filename);

    if (!file) {
        cout << "Помилка відкриття файлу" << endl;
        return matrix;
    }

    int num;
    for (int i = 0; i < 10; ++i) {
        vector<int> row;
        for (int j = 0; j < col; ++j) {
            if (file >> num) {
                row.push_back(num);
            }
            else {
                cout << "Невірний розмір матриці" << endl;
                return matrix;
            }
        }
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}

void depthFirstTraversal(vector<vector<int>> graph, int start) {
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int current = s.top();
        s.pop();

        cout << current + 1 << " ";
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[current][i] && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }

        cout << "( ";
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() + 1 << " ";
            temp.pop();
        }
        cout << ")" << endl;
    }
    cout << endl;
}

void breadthFirstTraversal(vector<vector<int>> graph, int start) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current + 1 << " ";

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

        cout << "( ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() +1 << " ";
            temp.pop();
        }
        cout << ")" << endl;
    }
    
}
int countVerticesWithinDistance(vector<vector<int>>& graph, int start, int d) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    vector<int> len;

    q.push(start);
    visited[start] = true;
    

    while (!q.empty()) {
        int current = q.front();
        q.pop();


        for (int i = 0; i < graph.size(); ++i) {
            if (graph[current][i] && !visited[i]) {
                if (graph[current][i] <= d) {
                    len.push_back(graph[current][i]);
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return len.size();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<vector<int>> graph = readMatrixFromFile("unoriented-adjacency-matrix.txt", 10);

    cout << "Обхід графа в глибину:" << endl;
    depthFirstTraversal(graph, 0);

    cout << endl;

    cout << "Обхід графа в ширину:" << endl;
    breadthFirstTraversal(graph, 0);


    int distance;
    cout << "Введіть значення d: ";
    cin >> distance;

    int count = countVerticesWithinDistance(graph, 0, distance);
    cout << "Кількість вершин на відстані, що не перевищує " << distance << ": " << count << endl;

    return 0;
}
