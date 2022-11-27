#include <iostream>
#include <string>

using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // n-1 passes
        for (int j = 0; j < size - i - 1; j++) {
            // single pass which set last element to the largest
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }

        }
    }
    printArr(arr, size);


}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printArr(arr, size);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//    selectionSort(arr, 9);
    bubbleSort(arr, 9);
    return 0;
}