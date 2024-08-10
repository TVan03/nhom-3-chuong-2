#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
bool isPrime8(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
bool allPrimes(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (!isPrime8(arr[i])) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra mảng có đối xứng hay không
bool isSymmetric(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra mảng có tăng dần hay không
bool isAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra mảng có giảm dần hay không
bool isDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void inMang(int arr[], int size)\
{
    for (int i = 0; i < size - 1; i++) {
        printf("%d ",arr[i]);
    }
}

// Hàm kiểm tra mảng không tăng không giảm
bool isNotSorted(int arr[], int size) {
    return !(isAscending(arr, size) || isDescending(arr, size));
}

int main8() {
    int arr[] = { 2, 3, 5, 7, 11, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);


    printf("mang :");
    inMang(arr,size);
    printf("\n");

    // Kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
    if (allPrimes(arr, size)) {
        printf("Mang chua toan bo so nguyen to.\n");
    }
    else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    // Kiểm tra mảng có đối xứng hay không
    if (isSymmetric(arr, size)) {
        printf("Mang doi xung.\n");
    }
    else {
        printf("Mang khong doi xung.\n");
    }

    // Kiểm tra mảng có tăng dần hay không
    if (isAscending(arr, size)) {
        printf("Mang tang dan.\n");
    }
    else if (isDescending(arr, size)) {
        printf("Mang giam dan.\n");
    }
    else {
        printf("Mang khong tang khong giam.\n");
    }

    return 0;
}
