#include <stdio.h>

// Định nghĩa cấu trúc phân số
typedef struct {
    int tu;   // tử số
    int mau;  // mẫu số
} PhanSo;

// Hàm nhập vào phân số
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

// Hàm xuất phân số
void xuatPhanSom(PhanSo ps) {
    if (ps.mau == 1) {
        printf("%d\n", ps.tu);
    }
    else if (ps.mau == -1) {
        printf("%d\n", -ps.tu);
    }
    else if (ps.mau < 0) {
        printf("%d/%d\n", -ps.tu, -ps.mau);
    }
    else {
        printf("%d/%d\n", ps.tu, ps.mau);
    }
}

// Hàm tìm ước chung lớn nhất (gcd)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Hàm tối giản phân số
PhanSo toiGianPhanSo(PhanSo ps) {
    int uc = gcd(ps.tu, ps.mau);
    ps.tu /= uc;
    ps.mau /= uc;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

// Hàm tính tổng hai phân số
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    return toiGianPhanSo(ketqua);
}

// Hàm tính hiệu hai phân số
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    return toiGianPhanSo(ketqua);
}

// Hàm tính tích hai phân số
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.tu;
    ketqua.mau = ps1.mau * ps2.mau;
    return toiGianPhanSo(ketqua);
}

// Hàm tính thương hai phân số
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau;
    ketqua.mau = ps1.mau * ps2.tu;
    return toiGianPhanSo(ketqua);
}

int main9() {
    PhanSo ps1, ps2, kq;

    // Nhập hai phân số
    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    // Xuất hai phân số
    printf("Phan so thu nhat: ");
    xuatPhanSom(ps1);
    printf("Phan so thu hai: ");
    xuatPhanSom(ps2);

    // Tính tổng
    kq = tongPhanSo(ps1, ps2);
    printf("Tong hai phan so: ");
    xuatPhanSom(kq);

    // Tính hiệu
    kq = hieuPhanSo(ps1, ps2);
    printf("Hieu hai phan so: ");
    xuatPhanSom(kq);

    // Tính tích
    kq = tichPhanSo(ps1, ps2);
    printf("Tich hai phan so: ");
    xuatPhanSom(kq);

    // Tính thương
    kq = thuongPhanSo(ps1, ps2);
    printf("Thuong hai phan so: ");
    xuatPhanSom(kq);

    return 0;
}
