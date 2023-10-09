#include <iostream>
#define N 10
using namespace std;

void inputArray(double arr[]) {
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}
int minIndex(double arr[]) {
    int min_idx = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

double negativesSum(double arr[]) {
    int first_neg_idx = -1;
    int second_neg_idx = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            if (first_neg_idx == -1) {
                first_neg_idx = i;
            }
            else {
                second_neg_idx = i;
                break;
            }
        }
    }
    double sum = 0.0;
    if (first_neg_idx != -1 && second_neg_idx != -1) {
        int start_idx = first_neg_idx + 1;
        int end_idx = second_neg_idx - 1;
        for (int i = start_idx; i <= end_idx; i++) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    
    double arr[N];
    cout << "Enter a data: " << endl;
    inputArray(arr);
    cout << "Index of the minimum element: " << minIndex(arr) << endl;

    cout << "Sum of elements between first and second negative elements: " << negativesSum(arr) << endl;

    return 0;
}
