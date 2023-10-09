#include <iostream>
#include <cstdlib>
#define SIZE 9
using namespace std;
void inputArray(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (/*i + j >= SIZE - 1 &&*/ i <= j) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

}
void printArray(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int arr[SIZE][SIZE];
    inputArray(arr);
    printArray(arr);
}