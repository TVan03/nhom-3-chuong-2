#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_M 100
#define MAX_N 100

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTomb(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu là số lẻ
bool laSoDauLe(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return (n % 2 != 0);
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongSoDauLe(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoDauLe(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Bài 2: Liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac so hoan thien trong ma tran:\n");
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
                printf("%d ", num);
            }
        }
    }
    printf("\n");
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoi(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[i][j] > fabs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Bài 4: Tính tổng giá trị trên dòng k của ma trận
int tongTrenDongK(int a[MAX_M][MAX_N], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("Dòng k không hợp lệ.\n");
        return 0;
    }
    int tong = 0;
    for (int j = 0; j < n; ++j) {
        tong += a[k][j];
    }
    return tong;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int tongTrenBien(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int j = 0; j < n; ++j) {
        tong += a[0][j] + a[m - 1][j];  // Dòng trên và dòng dưới
    }
    for (int i = 1; i < m - 1; ++i) {
        tong += a[i][0] + a[i][n - 1];  // Cột trái và cột phải
    }
    return tong;
}

// Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
int demTanSuat(int a[MAX_M][MAX_N], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demSoLuongPhanTu(int a[MAX_M][MAX_N], int m, int n) {
    int soChan = 0, soLe = 0, soAm = 0, soDuong = 0, soNguyenTo = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] % 2 == 0) {
                soChan++;
            }
            else {
                soLe++;
            }
            if (a[i][j] < 0) {
                soAm++;
            }
            else if (a[i][j] > 0) {
                soDuong++;
            }
            if (laSoNguyenTomb(a[i][j])) {
                soNguyenTo++;
            }
        }
    }

    printf("So luong so chan: %d\n", soChan);
    printf("So luong so le: %d\n", soLe);
    printf("So luong so am: %d\n", soAm);
    printf("So luong so duong: %d\n", soDuong);
    printf("So luong so nguyen to: %d\n", soNguyenTo);
}

int main13() {
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
    printf("Tong cac phan tu co chu so dau la so le: %d\n", tongSoDauLe(a, m, n));
    lietKeSoHoanThien(a, m, n);
    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tongLonHonTriTuyetDoi(a, m, n));

    int k;
    printf("Nhap dong k: ");
    scanf("%d", &k);
    printf("Tong gia tri tren dong %d: %d\n", k, tongTrenDongK(a, m, n, k));

    printf("Tong cac gia tri nam tren bien: %d\n", tongTrenBien(a, m, n));

    int x;
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    printf("Tan suat xuat hien cua %d: %d\n", x, demTanSuat(a, m, n, x));

    demSoLuongPhanTu(a, m, n);

    return 0;
}
