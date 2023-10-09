#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#define SIZE 5
using namespace std;


void generateArray(int arr[][SIZE]) {
    srand(time(0)); 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 20 - 10; 
        }
    }
}

int columnCharacteristic(int arr[][SIZE], int col) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i][col] < 0 && abs(arr[i][col]) % 2 == 1) {
            sum += abs(arr[i][col]);
        }
    }
    return sum;
}


void sortColumns(int arr[][SIZE]) {
    int characteristics[SIZE];
    for (int j = 0; j < SIZE; j++) {
        characteristics[j] = columnCharacteristic(arr, j);
    }

    for (int j = 0; j < SIZE - 1; j++) {
        for (int k = j + 1; k < SIZE; k++) {
            if (characteristics[j] > characteristics[k]) {
                for (int i = 0; i < SIZE; i++) {
                    swap(arr[i][j], arr[i][k]);
                }
                swap(characteristics[j], characteristics[k]);
            }
        }
    }
}
void printArray(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int arr[SIZE][SIZE];

    generateArray(arr);
    cout << "Generated matrix:" << endl;
    printArray(arr);

    
    sortColumns(arr);

    cout << "Sorted matrix by column characteristics:" << endl;
    printArray(arr);

    return 0;
}
