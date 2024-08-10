#include <stdio.h>

// Hàm hoán đổi hai số nguyên
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (partition)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Pi là chỉ số nơi pivot được đặt đúng vị trí
        int pi = partition(arr, low, high);

        // Sắp xếp các phần tử trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main6() {
    int arr[] = { 10, 3, 7, 6, 2, 5, 16, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Mang da sap xep: ");
    printArray(arr, n);
    return 0;
}
