#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <Windows.h>
#include <climits>

using namespace std;

vector<vector<int>> readMatrixFromFile(const string& filename, int col) {
    vector<vector<int>> matrix;
    ifstream file(filename);

    if (!file) {
        cout << "������� �������� �����" << endl;
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
                cout << "������� ����� �������" << endl;
                return matrix;
            }
        }
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> adjacencyToIncidence(const vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size(); // ʳ������ ������ �����
    int m = 0; // ʳ������ ����� �����
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                ++m;
            }
        }
    }

    vector<vector<int>> incidenceMatrix(n, vector<int>(m)); // ������� ������������
    int edgeIndex = 0; // ������ ��������� ����� � ������� ������������

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                incidenceMatrix[i][edgeIndex] = adjacencyMatrix[i][j]; // �������� ���� ����� ��� ������� i
                incidenceMatrix[j][edgeIndex] = adjacencyMatrix[i][j]; // �������� ���� ����� ��� ������� j
                ++edgeIndex; // ���������� �� ���������� �����
            }
        }
    }

    return incidenceMatrix; 
}

vector<vector<int>> incidenceToAdjacency(vector<vector<int>> incidenceMatrix) {
    int n = incidenceMatrix.size(); // ʳ������ ������ �����
    int m = incidenceMatrix[0].size(); // ʳ������ ����� �����

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n)); // ������� ��������

    for (int edgeIndex = 0; edgeIndex < m; ++edgeIndex) {
        vector<int> connectedVertices; // ������ ������, ���'������ � �������� ������
        for (int i = 0; i < n; ++i) {
            if (incidenceMatrix[i][edgeIndex] != 0) {
                connectedVertices.push_back(i); // ������ �������, ���'����� � �������� ������, �� ������
            }
        }

        int numVertices = connectedVertices.size(); // ʳ������ ������, ���'������ � �������� ������
        if (numVertices > 1) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = i + 1; j < numVertices; ++j) {
                    int weight = incidenceMatrix[connectedVertices[i]][edgeIndex]; // ���� �����, ��� �������� � ������� ������������
                    adjacencyMatrix[connectedVertices[i]][connectedVertices[j]] = weight; // ������������ ���� ����� �� ���������
                    adjacencyMatrix[connectedVertices[j]][connectedVertices[i]] = weight; // ������������ ���� ����� �� ��������� (� ������������� �����)
                }
            }
        }
    }

    return adjacencyMatrix; 
}


vector<pair<int, int>> adjacencyToList(const vector<vector<int>>& adjacencyMatrix) {
    vector<pair<int, int>> edgeList;

    int n = adjacencyMatrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                edgeList.push_back(make_pair(i, j));
            }
        }
    }

    return edgeList;
}

vector<pair<int, int>> minimumSpanningTree(const vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> weight(n, INT_MAX);
    weight[0] = 0;  

    for (int i = 0; i < n - 1; ++i) {
        int minWeight = INT_MAX;
        int minWeightVertex = -1;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && weight[j] < minWeight) {
                minWeight = weight[j];
                minWeightVertex = j;
            }
        }

        visited[minWeightVertex] = true;

        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[minWeightVertex][j] != 0 && !visited[j] && adjacencyMatrix[minWeightVertex][j] < weight[j]) {
                parent[j] = minWeightVertex;
                weight[j] = adjacencyMatrix[minWeightVertex][j];
            }
        }
    }

    vector<pair<int, int>> mst;
    for (int i = 1; i < n; ++i) {
        mst.push_back(make_pair(parent[i], i));
    }

    return mst;
}

void printPair(const vector<pair<int, int>>& pairList) {
    for (const auto& edge : pairList) {
        cout << "(" << edge.first + 1 << ", " << edge.second + 1 << ")" << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<vector<int>> adjacencyMatrix = readMatrixFromFile("unoriented-adjacency-matrix.txt", 10);
    vector<vector<int>> incidenceMatrix = readMatrixFromFile("unoriented-incident-matrix.txt", 16);
    int choice;
    while (true) {
        cout << "�������: " << endl;
        cout << "1. �� ������� �������� �������� ���������� ������� ������������" << endl;
        cout << "2. �� ������� �������� ������������ ���������� ������� ��������" << endl;
        cout << "3. �� ������� �������� �������� ���������� ������ �����" << endl;
        cout << "4. ������ �������� ���������� ������" << endl;
        cout << "5. �����. " << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "����������� ������� ��������, ������� � �����" << endl;
            printMatrix(adjacencyMatrix);
            vector<vector<int>> incidence = adjacencyToIncidence(adjacencyMatrix);
            cout << "���������� ������� ������������" << endl;
            printMatrix(incidence);
            break;
        }
        case 2: {
            cout << "����������� ������� ������������, ������� � �����" << endl;
            printMatrix(incidenceMatrix);
            vector<vector<int>> adjacency = incidenceToAdjacency(incidenceMatrix);
            cout << "���������� ������� ��������" << endl;
            printMatrix(adjacency);
            break;
        }
        case 3: {
            vector<pair<int, int>> adjacencyList = adjacencyToList(adjacencyMatrix);
            cout << "������ �����: " << endl;
            printPair(adjacencyList);

            break;
        }
        case 4: {
            vector<pair<int, int>> mst = minimumSpanningTree(adjacencyMatrix);
            cout << "̳������� ���������� ������: " << endl;
            printPair(mst);
            break;
        }
        case 5: {
            exit(0);
        }
        default:
            cout << "�������. ������������ ����" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
