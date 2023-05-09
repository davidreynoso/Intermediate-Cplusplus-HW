// hw8

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m -l + 1;
    int n2 = r -m;
    int*L = new int[n1];
    int*R = new int[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
        }
        else {
        arr[k] = R[j];
        j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    }

void mergeSort(int arr[], int n) {
    for (int s = 1; s < n; s *= 2) {
        for (int l = 0; l < n-1; l += 2*s) {
            int m = l + s - 1;
            int r = l + 2*s - 1;
            if (r >= n) {
                r = n-1;
            }
            merge(arr,l,m,r);
        }
    }
}

int main() {
    int arr[] = {11, 9, 17, 5, 12, 1, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    cout<< "3/2/2023 " << "David Reynoso" << endl;
}
