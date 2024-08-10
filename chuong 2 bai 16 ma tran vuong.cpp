#include <stdio.h>
#include <stdlib.h>

// Hàm tính tổng các phần tử trên đường chéo chính
int tongDuongCheoChinh(int** a, int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += a[i][i];
    }
    return tong;
}

// Hàm tính tổng các phần tử trên đường chéo phụ
int tongDuongCheoPhu(int** a, int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += a[i][n - 1 - i];
    }
    return tong;
}

// Hàm tính tổng các phần tử phía trên đường chéo chính
int tongPhiaTrenDuongCheoChinh(int** a, int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm tính tổng các phần tử phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int** a, int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm in ma trận
void inMaTran(int** a, int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int** a;

    // Nhập kích thước ma trận
    printf("Nhap kich thuoc ma tran (n): ");
    scanf("%d", &n);

    // Cấp phát động cho ma trận
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    // Nhập các phần tử của ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Ma tran ban dau:\n");
    inMaTran(a, n);

    // Tính toán các yêu cầu
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongDuongCheoChinh(a, n));
    printf("Tong cac phan tu tren duong cheo phu: %d\n", tongDuongCheoPhu(a, n));
    printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", tongPhiaTrenDuongCheoChinh(a, n));
    printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tongPhiaTrenDuongCheoPhu(a, n));

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}
