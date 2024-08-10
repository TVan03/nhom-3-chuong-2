#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_M 100
#define MAX_N 100

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTombb(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[MAX_M][MAX_N], int m, int n) {
    int tongCacCot[MAX_N] = { 0 };
    int minTong = INT_MAX;

    for (int j = 0; j < n; ++j) {
        int tong = 0;
        for (int i = 0; i < m; ++i) {
            tong += a[i][j];
        }
        tongCacCot[j] = tong;
        if (tong < minTong) {
            minTong = tong;
        }
    }

    printf("Cac cot co tong nho nhat:\n");
    for (int j = 0; j < n; ++j) {
        if (tongCacCot[j] == minTong) {
            printf("Cot %d\n", j);
        }
    }
}

// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
void lietKeDongNhieuSoHoanThienNhat(int a[MAX_M][MAX_N], int m, int n) {
    int soHoanThien[MAX_M] = { 0 };
    int maxHoanThien = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = a[i][j];
            int tong = 0;
            for (int k = 1; k <= num / 2; ++k) {
                if (num % k == 0) {
                    tong += k;
                }
            }
            if (tong == num) {
                soHoanThien[i]++;
            }
        }
        if (soHoanThien[i] > maxHoanThien) {
            maxHoanThien = soHoanThien[i];
        }
    }

    printf("Cac dong co nhieu so hoan thien nhat:\n");
    for (int i = 0; i < m; ++i) {
        if (soHoanThien[i] == maxHoanThien) {
            printf("Dong %d\n", i);
        }
    }
}

// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongToanChan(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; ++i) {
        bool toanChan = true;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            printf("Dong %d\n", i);
        }
    }
}

// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
void timGiaTriXuatHienNhieuNhat(int a[MAX_M][MAX_N], int m, int n) {
    int maxCount = 0;
    int valueWithMaxCount = a[0][0];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int currentValue = a[i][j];
            int count = 0;
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (a[x][y] == currentValue) {
                        count++;
                    }
                }
            }
            if (count > maxCount) {
                maxCount = count;
                valueWithMaxCount = currentValue;
            }
        }
    }

    printf("Gia tri xuat hien nhieu nhat: %d\n", valueWithMaxCount);
}

// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
void timSoNguyenToNhoNhat(int a[MAX_M][MAX_N], int m, int n) {
    int minPrime = INT_MAX;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTombb(a[i][j]) && a[i][j] < minPrime) {
                minPrime = a[i][j];
            }
        }
    }
    if (minPrime == INT_MAX) {
        printf("Khong co so nguyen to trong ma tran.\n");
    }
    else {
        printf("So nguyen to nho nhat: %d\n", minPrime);
    }
}

// Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
void timPhanTuLonNhatNhoNhatTrenDongK(int a[MAX_M][MAX_N], int m, int n, int k, bool timLonNhat) {
    if (k < 0 || k >= m) {
        printf("Dòng k không hợp lệ.\n");
        return;
    }

    int result = timLonNhat ? a[k][0] : a[k][0];
    for (int j = 1; j < n; ++j) {
        if (timLonNhat) {
            if (a[k][j] > result) result = a[k][j];
        }
        else {
            if (a[k][j] < result) result = a[k][j];
        }
    }

    printf("Phan tu %s nhat tren dong %d: %d\n", timLonNhat ? "lon" : "nho", k, result);
}

// Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
void timPhanTuLonNhatNhoNhatTrenCotK(int a[MAX_M][MAX_N], int m, int n, int k, bool timLonNhat) {
    if (k < 0 || k >= n) {
        printf("Cột k không hợp lệ.\n");
        return;
    }

    int result = timLonNhat ? a[0][k] : a[0][k];
    for (int i = 1; i < m; ++i) {
        if (timLonNhat) {
            if (a[i][k] > result) result = a[i][k];
        }
        else {
            if (a[i][k] < result) result = a[i][k];
        }
    }

    printf("Phan tu %s nhat tren cot %d: %d\n", timLonNhat ? "lon" : "nho", k, result);
}

int main14() {
    int m, n;
    int a[MAX_M][MAX_N];

    // Nhập kích thước ma trận
    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);

    // Nhập các phần tử của ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Ví dụ sử dụng các hàm
    lietKeCotTongNhoNhat(a, m, n);

    lietKeDongNhieuSoHoanThienNhat(a, m, n);

    lietKeDongToanChan(a, m, n);

    timGiaTriXuatHienNhieuNhat(a, m, n);

    timSoNguyenToNhoNhat(a, m, n);

    int k;
    printf("Nhap dong k: ");
    scanf("%d", &k);
    timPhanTuLonNhatNhoNhatTrenDongK(a, m, n, k, true);
    timPhanTuLonNhatNhoNhatTrenDongK(a, m, n, k, false);

    printf("Nhap cot k: ");
    scanf("%d", &k);
    timPhanTuLonNhatNhoNhatTrenCotK(a, m, n, k, true);
    timPhanTuLonNhatNhoNhatTrenCotK(a, m, n, k, false);

    return 0;
}
