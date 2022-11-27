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

void shortBubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // n-1 passes
        bool isSwap = false;
        cout << "YES" << endl;

        for (int j = 0; j < size - i - 1; j++) {
            // single pass which set last element to the largest
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
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

void merge(int arr[], int first, int middle, int last) {
    int i, j, k;
    int size1 = middle - first + 1;
    int size2 = last - middle;
    int *tempArr1 = new int[size1];
    int *tempArr2 = new int[size2];

    //MOVING DATA TO TEMP ARRAYS
    for (int i = 0; i < size1; i++) {
        tempArr1[i] = arr[first + i];
    }
    for (int i = 0; i < size1; i++) {
        tempArr2[i] = arr[middle + 1 + i];
    }

    i = 0;
    j = 0;
    k = first;

    while (i < size1 & j < size2) {
        if (tempArr1[i] <= tempArr2[j]) {
            arr[k] = tempArr1[i];
            i++;
        } else {
            arr[k] = tempArr2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        arr[k] = tempArr1[i];
        i++;
        k++;
    }
    while (j < size1) {
        arr[k] = tempArr2[j];
        j++;
        k++;
    }
    delete tempArr1;
    delete tempArr2;
}

void mergeSort(int arr[], int first, int last) {
    if (last > first) {
        int middle = (last + first) / 2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);
        merge(arr, first, middle, last);
    }
}


int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

//    selectionSort(arr, 9);
//    bubbleSort(arr, 9);
//    shortBubbleSort(arr, 9);
//    mergeSort(arr, 0, 9 - 1);
    return 0;
}