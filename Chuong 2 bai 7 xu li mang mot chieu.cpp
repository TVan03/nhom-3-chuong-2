#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Hàm hoán đổi hai số nguyên
void swap7(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (partition) cho Quick Sort
int partition7(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap7(&arr[i], &arr[j]);
        }
    }
    swap7(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm Quick Sort
void quickSort7(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition7(arr, low, high);
        quickSort7(arr, low, pi - 1);
        quickSort7(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray7(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số nguyên tố trong mảng
int countPrimes(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}

// Hàm kiểm tra nếu tất cả chữ số của số là số lẻ
bool allOddDigits(int n) {
    if (n == 0) return false;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

// Hàm xuất các phần tử có tất cả chữ số là số lẻ
void printAllOddDigits(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (allOddDigits(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Hàm tìm vị trí số lớn nhất cuối cùng trong mảng
int findLastMaxPosition(int arr[], int size) {
    int max = arr[0];
    int position = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            position = i;
        }
    }
    return position;
}

// Hàm kiểm tra mảng có toàn số chẵn không
bool allEven(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra mảng có phải dãy số chẵn lẻ xen kẽ không
bool isAlternating(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

int main7() {
    int arr[] = { 10, 3, 7, 6, 2, 5, 16, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray7(arr, size);

    quickSort7(arr, 0, size - 1);
    printf("Mang da sap xep: ");
    printArray7(arr, size);

    printf("So phan tu la so nguyen to: %d\n", countPrimes(arr, size));

    printf("Cac phan tu co tat ca chu so la so le: ");
    printAllOddDigits(arr, size);

    printf("Vi tri so lon nhat cuoi cung: %d\n", findLastMaxPosition(arr, size));

    if (allEven(arr, size)) {
        printf("Mang co tat ca so chan.\n");
    }
    else {
        printf("Mang khong co tat ca so chan.\n");
    }

    if (isAlternating(arr, size)) {
        printf("Mang la day so chan le xen ke.\n");
    }
    else {
        printf("Mang khong phai la day so chan le xen ke.\n");
    }

    return 0;
}
