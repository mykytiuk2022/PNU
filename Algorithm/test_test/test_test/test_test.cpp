#include <iostream>
#include <string>

using namespace std;
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

}
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}

int main() {
	int choice;
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	while (true) {
		cout << "Enter 1 for bubble sort, 2 for selection sort, 3 for exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			bubbleSort(arr, 7);
			printArray(arr, 7);
			break;

		case 2:
			selectionSort(arr, 7);
			printArray(arr, 7);
			break;
		case 3: return 0;
		}
	}
	return 0;
}
