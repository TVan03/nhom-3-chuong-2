#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int stt;
    char mssv[10];
    char hoTen[50];
    float diemTieuLuan;
    float diemThiKetThucMon;
    float diemTongKet;
    float diemHe4;
} SinhVien;

void nhapSinhVien(SinhVien* sv, int stt) {
    sv->stt = stt;
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten sinh vien: ");
    getchar();
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc mon: ");
    scanf("%f", &sv->diemThiKetThucMon);
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThiKetThucMon;
}

void xuatSinhVien(SinhVien sv) {
    printf("STT: %d, MSSV: %s, Ho ten: %s, Diem tieu luan: %.2f, Diem thi ket thuc mon: %.2f, Diem tong ket: %.2f, Diem he 4: %.2f\n",
        sv.stt, sv.mssv, sv.hoTen, sv.diemTieuLuan, sv.diemThiKetThucMon, sv.diemTongKet, sv.diemHe4);
}

void nhapDanhSachSinhVien(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&sv[i], i + 1);
    }
}

void xuatDanhSachSinhVien(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        xuatSinhVien(sv[i]);
    }
}

SinhVien timSinhVienDiemCaoNhat(SinhVien sv[], int n) {
    SinhVien max = sv[0];
    for (int i = 1; i < n; i++) {
        if (sv[i].diemTongKet > max.diemTongKet) {
            max = sv[i];
        }
    }
    return max;
}

SinhVien timSinhVienDiemThapNhat(SinhVien sv[], int n) {
    SinhVien min = sv[0];
    for (int i = 1; i < n; i++) {
        if (sv[i].diemTongKet < min.diemTongKet) {
            min = sv[i];
        }
    }
    return min;
}

void quyDoiDiemHe4(SinhVien* sv) {
    float diem = sv->diemTongKet;
    if (diem >= 8.5) {
        sv->diemHe4 = 4.0;
    }
    else if (diem >= 7.0) {
        sv->diemHe4 = 3.0;
    }
    else if (diem >= 5.5) {
        sv->diemHe4 = 2.0;
    }
    else if (diem >= 4.0) {
        sv->diemHe4 = 1.0;
    }
    else {
        sv->diemHe4 = 0.0;
    }
}

void quyDoiDanhSachDiemHe4(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        quyDoiDiemHe4(&sv[i]);
    }
}

void sapXepTangDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet > sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet < sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

float tinhDiemTrungBinh(SinhVien sv[], int n) {
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        tongDiem += sv[i].diemTongKet;
    }
    return tongDiem / n;
}

void ghiFile(SinhVien sv[], int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %s %.2f %.2f %.2f %.2f\n",
            sv[i].stt, sv[i].mssv, sv[i].hoTen, sv[i].diemTieuLuan, sv[i].diemThiKetThucMon, sv[i].diemTongKet, sv[i].diemHe4);
    }
    fclose(file);
}

void docFile(SinhVien sv[], int* n, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d %s %s %f %f %f %f\n",
        &sv[i].stt, sv[i].mssv, sv[i].hoTen, &sv[i].diemTieuLuan, &sv[i].diemThiKetThucMon, &sv[i].diemTongKet, &sv[i].diemHe4) != EOF) {
        i++;
    }
    *n = i;
    fclose(file);
}

void demSinhVienDatKhongDat(SinhVien sv[], int n) {
    int soSinhVienDat = 0;
    int soSinhVienKhongDat = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].diemTongKet >= 4.0) {
            soSinhVienDat++;
        }
        else {
            soSinhVienKhongDat++;
        }
    }
    printf("So sinh vien dat: %d\n", soSinhVienDat);
    printf("So sinh vien khong dat: %d\n", soSinhVienKhongDat);
}

void menu11() {
    SinhVien sv[50];
    int n = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien co diem tong ket cao nhat\n");
        printf("4. Tim sinh vien co diem tong ket thap nhat\n");
        printf("5. Quy doi diem he 4\n");
        printf("6. Sap xep danh sach sinh vien tang dan theo diem tong ket\n");
        printf("7. Sap xep danh sach sinh vien giam dan theo diem tong ket\n");
        printf("8. Tinh diem trung binh cua tat ca sinh vien\n");
        printf("9. Ghi danh sach sinh vien vao file\n");
        printf("10. Doc danh sach sinh vien tu file\n");
        printf("11. Dem so sinh vien dat va khong dat\n");
        printf("12. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            nhapDanhSachSinhVien(sv, n);
            break;
        case 2:
            printf("Danh sach sinh vien:\n");
            xuatDanhSachSinhVien(sv, n);
            break;
        case 3:
            printf("Sinh vien co diem tong ket cao nhat: ");
            xuatSinhVien(timSinhVienDiemCaoNhat(sv, n));
            break;
        case 4:
            printf("Sinh vien co diem tong ket thap nhat: ");
            xuatSinhVien(timSinhVienDiemThapNhat(sv, n));
            break;
        case 5:
            quyDoiDanhSachDiemHe4(sv, n);
            printf("Da quy doi diem he 4.\n");
            break;
        case 6:
            sapXepTangDan(sv, n);
            printf("Danh sach sinh vien sap xep tang dan theo diem tong ket:\n");
            xuatDanhSachSinhVien(sv, n);
            break;
        case 7:
            sapXepGiamDan(sv, n);
            printf("Danh sach sinh vien sap xep giam dan theo diem tong ket:\n");
            xuatDanhSachSinhVien(sv, n);
            break;
        case 8:
            printf("Diem trung binh cua tat ca sinh vien: %.2f\n", tinhDiemTrungBinh(sv, n));
            break;
        case 9:
            ghiFile(sv, n, "sinhvien.txt");
            printf("Da ghi danh sach sinh vien vao file.\n");
            break;
        case 10:
            docFile(sv, &n, "sinhvien.txt");
            printf("Da doc danh sach sinh vien tu file.\n");
            xuatDanhSachSinhVien(sv, n);
            break;
        case 11:
            demSinhVienDatKhongDat(sv, n);
            break;
        case 12:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 12);
}

int main11() {
    menu11();
    return 0;
}
