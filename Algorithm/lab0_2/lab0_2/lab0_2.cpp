#include <iostream>
#include <cmath>
#include <Windows.h>
#define N 10

using namespace std;
void printArray(int arr[]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[N];
    cout << "Введіть масив: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Оригінальний масив: " << endl;
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (abs(arr[i]) <= 10) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    cout << "Масив після перетворення: " << endl;
    

    return 0;
}
