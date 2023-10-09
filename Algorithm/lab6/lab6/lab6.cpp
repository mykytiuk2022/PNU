#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <Windows.h>
using namespace std;

int comparisons = 0;

double Th()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    double chas;
    chas = time.wHour * 60 * 60 * 1000 + time.wMinute * 60 * 1000 + time.wSecond * 1000 + time.wMilliseconds;
    return chas;
}

void generateArray(int arr[], int n) {
    //srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
     }
     cout << endl;
}

int binarySearch(int arr[], int l, int r, int x) {
    if (l <= r) {
        int mid = (l + r) / 2;
        comparisons++;
        if (arr[mid] == x) {
            return mid;
        }
        comparisons++;
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double t0, t1, T;

    int n, searchElement, result;

    cout << "Введіть об'єм випадкової послідовності: ";
    cin >> n;
    int* arr = new int[n];

    generateArray(arr, n);
    sort(arr, arr+n);

    cout << "Випадкова послідовність: " << endl;
    //printArray(arr, n);

    cout << "Введіть елемент для пошуку: ";
    cin >> searchElement;
    int a;
    cout << "Виберіть метод пошуку:" << endl;
    cout << "1. Лінійний пошук" << endl;
    cout << "2. Бінарний пошук" << endl;
    cin >> a;
    t0 = Th();
    switch (a)
    {
    case 1:
        result = linearSearch(arr, n, searchElement);
        break;
    case 2:
        result = binarySearch(arr, 0, n - 1, searchElement);
        break;
    default:
        cout << "Некоректний вибір." << endl;
    }
    t1 = Th();
    T = (t1 - t0);
    
    if (result == -1) {
        cout << "Елемент не знайдено в послідовності." << endl;
    }
    else {
        cout << "Елемент знайдено на позиції " << result << " в заданій послідовності" << endl;
        cout << "Час роботи алгоритму: " << T << endl;
        cout << "Кількість порівнянь: " << comparisons << endl;
        cout << "Хочете побачити елемент на цій позиції(Y / N) : ";
        char b;
        cin >> b;
        if (b == 'Y' || b == 'y') {
            cout << "Елемент на позиції " << result << " це: " << arr[result] << endl;
        }
    }

    delete[] arr;
    return 0;
}


