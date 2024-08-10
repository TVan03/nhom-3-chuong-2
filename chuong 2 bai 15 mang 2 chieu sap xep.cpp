#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hàm hoán đổi hai giá trị
void swapml(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng bằng phương pháp sắp xếp nổi bọt
void bubbleSort(int arr[], int n, bool tangDan) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((tangDan && arr[j] > arr[j + 1]) || (!tangDan && arr[j] < arr[j + 1])) {
                swapml(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng, dòng lẻ giảm
void sapXepTheoDong(int** a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        int* row = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            row[j] = a[i][j];
        }
        // Sắp xếp theo dòng chẵn tăng, dòng lẻ giảm
        bubbleSort(row, m, i % 2 == 0);
        for (int j = 0; j < m; ++j) {
            a[i][j] = row[j];
        }
        free(row);
    }
}

// Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng, cột lẻ giảm
void sapXepTheoCot(int** a, int n, int m) {
    for (int j = 0; j < m; ++j) {
        int* col = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            col[i] = a[i][j];
        }
        // Sắp xếp theo cột chẵn tăng, cột lẻ giảm
        bubbleSort(col, n, j % 2 == 0);
        for (int i = 0; i < n; ++i) {
            a[i][j] = col[i];
        }
        free(col);
    }
}

// Bài 3: Sắp xếp ma trận tăng dần/giảm dần theo zic-zac
void sapXepZicZac(int** a, int n, int m, bool tangDan) {
    int* arr = (int*)malloc(n * m * sizeof(int));
    int index = 0;

    // Chuyển ma trận thành mảng 1 chiều
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng
    bubbleSort(arr, n * m, tangDan);

    // Chuyển mảng trở lại ma trận
    index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = arr[index++];
        }
    }
    free(arr);
}

void inMaTran(int** a, int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main15() {
    int n, m;
    int** a;

    // Nhập kích thước ma trận
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    // Cấp phát động cho ma trận
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        a[i] = (int*)malloc(m * sizeof(int));
    }

    // Nhập các phần tử của ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Ma tran ban dau:\n");
    inMaTran(a, n, m);

    // Ví dụ sắp xếp
    sapXepTheoDong(a, n, m);
    printf("Ma tran sau khi sap xep theo dong:\n");
    inMaTran(a, n, m);

    sapXepTheoCot(a, n, m);
    printf("Ma tran sau khi sap xep theo cot:\n");
    inMaTran(a, n, m);

    sapXepZicZac(a, n, m, true);
    printf("Ma tran sau khi sap xep zic-zac tang dan:\n");
    inMaTran(a, n, m);

    sapXepZicZac(a, n, m, false);
    printf("Ma tran sau khi sap xep zic-zac giam dan:\n");
    inMaTran(a, n, m);

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}
