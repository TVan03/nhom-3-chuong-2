#include <stdio.h>
#include <stdbool.h>

// Định nghĩa cấu trúc phân số
typedef struct {
    int tu;   // tử số
    int mau;  // mẫu số
} PhanSoM;

// Hàm tìm ước chung lớn nhất (gcdm)
int gcdm(int a, int b) {
    if (b == 0) return a;
    return gcdm(b, a % b);
}

// Hàm tối giản phân số
PhanSoM toiGianPhanSoM(PhanSoM ps) {
    int uc = gcdm(ps.tu, ps.mau);
    ps.tu /= uc;
    ps.mau /= uc;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

// Hàm nhập phân số
void nhapPhanSoM(PhanSoM* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
    *ps = toiGianPhanSoM(*ps);
}

// Hàm nhập danh sách phân số
void nhapDanhSachPhanSoM(PhanSoM ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSoM(&ps[i]);
    }
}

// Hàm xuất phân số
void xuatPhanSoM(PhanSoM ps) {
    if (ps.mau == 1) {
        printf("%d", ps.tu);
    }
    else {
        printf("%d/%d", ps.tu, ps.mau);
    }
}

// Hàm xuất danh sách phân số
void xuatDanhSachPhanSoM(PhanSoM ps[], int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSoM(ps[i]);
        printf("\n");
    }
}

// Hàm so sánh hai phân số
int soSanhPhanSoM(PhanSoM ps1, PhanSoM ps2) {
    int a = ps1.tu * ps2.mau;
    int b = ps2.tu * ps1.mau;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

// Hàm tìm phân số lớn nhất
PhanSoM timPhanSoMLonNhat(PhanSoM ps[], int n) {
    PhanSoM max = ps[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSoM(ps[i], max) > 0) {
            max = ps[i];
        }
    }
    return max;
}

// Hàm tìm phân số nhỏ nhất
PhanSoM timPhanSoMNhoNhat(PhanSoM ps[], int n) {
    PhanSoM min = ps[0];
    for (int i = 1; i < n; i++) {
        if (soSanhPhanSoM(ps[i], min) < 0) {
            min = ps[i];
        }
    }
    return min;
}

// Hàm tính tổng các phân số
PhanSoM tongPhanSoM(PhanSoM ps[], int n) {
    PhanSoM tong = { 0, 1 }; // khởi tạo phân số 0/1
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ps[i].mau + ps[i].tu * tong.mau;
        tong.mau *= ps[i].mau;
        tong = toiGianPhanSoM(tong);
    }
    return tong;
}

// Hàm tính tích các phân số
PhanSoM tichPhanSoM(PhanSoM ps[], int n) {
    PhanSoM tich = { 1, 1 }; // khởi tạo phân số 1/1
    for (int i = 0; i < n; i++) {
        tich.tu *= ps[i].tu;
        tich.mau *= ps[i].mau;
        tich = toiGianPhanSoM(tich);
    }
    return tich;
}

// Hàm xuất nghịch đảo phân số
void nghichDaoPhanSoM(PhanSoM ps) {
    int temp = ps.tu;
    ps.tu = ps.mau;
    ps.mau = temp;
    xuatPhanSoM(ps);
}

// Hàm xuất danh sách phân số nghịch đảo
void xuatNghichDaoDanhSach(PhanSoM ps[], int n) {
    for (int i = 0; i < n; i++) {
        nghichDaoPhanSoM(ps[i]);
        printf("\n");
    }
}

// Hàm hoán đổi hai phân số
void swap(PhanSoM* a, PhanSoM* b) {
    PhanSoM temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng phân số tăng dần bằng thuật toán Interchange Sort
void sapXepTangDan(PhanSoM ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhPhanSoM(ps[i], ps[j]) > 0) {
                swap(&ps[i], &ps[j]);
            }
        }
    }
}

// Hàm sắp xếp mảng phân số giảm dần bằng thuật toán Interchange Sort
void sapXepGiamDan(PhanSoM ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhPhanSoM(ps[i], ps[j]) < 0) {
                swap(&ps[i], &ps[j]);
            }
        }
    }
}

int main10() {
    PhanSoM ps[50];
    int n;

    // Nhập số lượng phân số
    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", &n);

    // Nhập danh sách phân số
    nhapDanhSachPhanSoM(ps, n);

    // Xuất danh sách phân số
    printf("Danh sach phan so vua nhap:\n");
    xuatDanhSachPhanSoM(ps, n);

    // Tìm phân số lớn nhất và nhỏ nhất
    PhanSoM max = timPhanSoMLonNhat(ps, n);
    PhanSoM min = timPhanSoMNhoNhat(ps, n);
    printf("Phan so lon nhat: ");
    xuatPhanSoM(max);
    printf("\nPhan so nho nhat: ");
    xuatPhanSoM(min);
    printf("\n");

    // Tính tổng và tích các phân số
    PhanSoM tong = tongPhanSoM(ps, n);
    PhanSoM tich = tichPhanSoM(ps, n);
    printf("Tong cac phan so: ");
    xuatPhanSoM(tong);
    printf("\nTich cac phan so: ");
    xuatPhanSoM(tich);
    printf("\n");

    // Xuất danh sách phân số nghịch đảo
    printf("Danh sach phan so nghich dao:\n");
    xuatNghichDaoDanhSach(ps, n);

    // Sắp xếp mảng tăng dần
    sapXepTangDan(ps, n);
    printf("Danh sach phan so sap xep tang dan:\n");
    xuatDanhSachPhanSoM(ps, n);

    // Sắp xếp mảng giảm dần
    sapXepGiamDan(ps, n);
    printf("Danh sach phan so sap xep giam dan:\n");
    xuatDanhSachPhanSoM(ps, n);

    return 0;
}
