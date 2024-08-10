#include <stdio.h>
#include <string.h>

#define MAX_SV 100

typedef struct {
    char mssv[10];
    char hoTen[50];
    float diemNhapMonLapTrinh;
    float diemToanA1;
    float diemToanA2;
    float diemVatLyKyThuat;
    float diemAnhVan;
    float diemTrungBinhTichLuy;
} SinhVienM;

void nhapSinhVienM(SinhVienM* sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten sinh vien: ");
    getchar();  // Xoa ky tu \n con lai trong buffer
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0; // Xoa ky tu \n neu co
    printf("Nhap diem Nhap mon lap trinh: ");
    scanf("%f", &sv->diemNhapMonLapTrinh);
    printf("Nhap diem Toan A1: ");
    scanf("%f", &sv->diemToanA1);
    printf("Nhap diem Toan A2: ");
    scanf("%f", &sv->diemToanA2);
    printf("Nhap diem Vat ly ky thuat: ");
    scanf("%f", &sv->diemVatLyKyThuat);
    printf("Nhap diem Anh van: ");
    scanf("%f", &sv->diemAnhVan);
    sv->diemTrungBinhTichLuy = (sv->diemNhapMonLapTrinh + sv->diemToanA1 + sv->diemToanA2 + sv->diemVatLyKyThuat + sv->diemAnhVan) / 5.0;
}

void xuatSinhVienM(const SinhVienM* sv) {
    printf("MSSV: %s, Ho ten: %s, Diem Nhap mon lap trinh: %.2f, Diem Toan A1: %.2f, Diem Toan A2: %.2f, Diem Vat ly ky thuat: %.2f, Diem Anh van: %.2f, Diem trung binh tich luy: %.2f\n",
        sv->mssv, sv->hoTen, sv->diemNhapMonLapTrinh, sv->diemToanA1, sv->diemToanA2, sv->diemVatLyKyThuat, sv->diemAnhVan, sv->diemTrungBinhTichLuy);
}

void nhapDanhSachSinhVien(SinhVienM ds[], int* soLuong) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", soLuong);
    for (int i = 0; i < *soLuong; ++i) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVienM(&ds[i]);
    }
}

void xuatDanhSachSinhVien(const SinhVienM ds[], int soLuong) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuong; ++i) {
        xuatSinhVienM(&ds[i]);
    }
}

int timSinhVienTheoMSSV(const SinhVienM ds[], int soLuong, const char* mssv) {
    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(ds[i].mssv, mssv) == 0) {
            return i;
        }
    }
    return -1; // Khong tim thay
}

void timSinhVienCoDiemTrungBinhCaoNhat(const SinhVienM ds[], int soLuong) {
    if (soLuong == 0) {
        printf("Khong co sinh vien trong danh sach.\n");
        return;
    }
    float maxDiem = ds[0].diemTrungBinhTichLuy;
    int index = 0;
    for (int i = 1; i < soLuong; ++i) {
        if (ds[i].diemTrungBinhTichLuy > maxDiem) {
            maxDiem = ds[i].diemTrungBinhTichLuy;
            index = i;
        }
    }
    printf("Sinh vien co diem trung binh cao nhat:\n");
    xuatSinhVienM(&ds[index]);
}

void themSinhVien(SinhVienM ds[], int* soLuong) {
    if (*soLuong >= MAX_SV) {
        printf("Khong the them sinh vien. Danh sach day.\n");
        return;
    }
    printf("Nhap thong tin sinh vien moi:\n");
    nhapSinhVienM(&ds[*soLuong]);
    (*soLuong)++;
}

void xoaSinhVien(SinhVienM ds[], int* soLuong, const char* mssv) {
    int index = timSinhVienTheoMSSV(ds, *soLuong, mssv);
    if (index == -1) {
        printf("Khong tim thay sinh vien voi MSSV: %s\n", mssv);
        return;
    }
    for (int i = index; i < *soLuong - 1; ++i) {
        ds[i] = ds[i + 1];
    }
    (*soLuong)--;
    printf("Da xoa sinh vien voi MSSV: %s\n", mssv);
}

void sapXepSinhVienTangDan(SinhVienM ds[], int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (ds[i].diemTrungBinhTichLuy > ds[j].diemTrungBinhTichLuy) {
                SinhVienM temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void sapXepSinhVienGiamDan(SinhVienM ds[], int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (ds[i].diemTrungBinhTichLuy < ds[j].diemTrungBinhTichLuy) {
                SinhVienM temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void xepLoaiHocTap(const SinhVienM ds[], int soLuong) {
    printf("Xep loai hoc tap cua sinh vien:\n");
    for (int i = 0; i < soLuong; ++i) {
        printf("MSSV: %s, Ho ten: %s, Xep loai: ", ds[i].mssv, ds[i].hoTen);
        if (ds[i].diemTrungBinhTichLuy >= 8.5) {
            printf("Gioi\n");
        }
        else if (ds[i].diemTrungBinhTichLuy >= 7.0) {
            printf("Kha\n");
        }
        else if (ds[i].diemTrungBinhTichLuy >= 5.5) {
            printf("Trung binh\n");
        }
        else {
            printf("Yeu\n");
        }
    }
}

void thongKeSoMonDauRot(const SinhVienM ds[], int soLuong) {
    printf("Thong ke so mon dau rot cua sinh vien:\n");
    for (int i = 0; i < soLuong; ++i) {
        int soMonDau = 0;
        int soMonRot = 0;
        if (ds[i].diemNhapMonLapTrinh >= 5.0) soMonDau++; else soMonRot++;
        if (ds[i].diemToanA1 >= 5.0) soMonDau++; else soMonRot++;
        if (ds[i].diemToanA2 >= 5.0) soMonDau++; else soMonRot++;
        if (ds[i].diemVatLyKyThuat >= 5.0) soMonDau++; else soMonRot++;
        if (ds[i].diemAnhVan >= 5.0) soMonDau++; else soMonRot++;
        printf("MSSV: %s, Ho ten: %s, So mon dau: %d, So mon rot: %d\n", ds[i].mssv, ds[i].hoTen, soMonDau, soMonRot);
    }
}

int main12() {
    SinhVienM danhSach[MAX_SV];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo MSSV\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien\n");
        printf("6. Xoa sinh vien\n");
        printf("7. Sap xep danh sach sinh vien tang dan theo diem trung binh\n");
        printf("8. Sap xep danh sach sinh vien giam dan theo diem trung binh\n");
        printf("9. Xep loai hoc tap cua sinh vien\n");
        printf("10. Thong ke so mon dau rot cua sinh vien\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapDanhSachSinhVien(danhSach, &soLuong);
            break;
        case 2:
            xuatDanhSachSinhVien(danhSach, soLuong);
            break;
        case 3: {
            char mssv[10];
            printf("Nhap ma so sinh vien can tim: ");
            scanf("%s", mssv);
            int index = timSinhVienTheoMSSV(danhSach, soLuong, mssv);
            if (index != -1) {
                xuatSinhVienM(&danhSach[index]);
            }
            else {
                printf("Khong tim thay sinh vien voi MSSV: %s\n", mssv);
            }
            break;
        }
        case 4:
            timSinhVienCoDiemTrungBinhCaoNhat(danhSach, soLuong);
            break;
        case 5:
            themSinhVien(danhSach, &soLuong);
            break;
        case 6: {
            char mssv[10];
            printf("Nhap ma so sinh vien can xoa: ");
            scanf("%s", mssv);
            xoaSinhVien(danhSach, &soLuong, mssv);
            break;
        }
        case 7:
            sapXepSinhVienTangDan(danhSach, soLuong);
            xuatDanhSachSinhVien(danhSach, soLuong);
            break;
        case 8:
            sapXepSinhVienGiamDan(danhSach, soLuong);
            xuatDanhSachSinhVien(danhSach, soLuong);
            break;
        case 9:
            xepLoaiHocTap(danhSach, soLuong);
            break;
        case 10:
            thongKeSoMonDauRot(danhSach, soLuong);
            break;
        case 11:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 11);

    return 0;
}
