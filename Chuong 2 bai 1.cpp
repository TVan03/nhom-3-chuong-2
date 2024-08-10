#include <stdio.h>

int timKiem(int mang[], int kichThuoc, int giaTri) {
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] == giaTri) {
            return i;
        }
    }
    return -1;
}

int main1() {
    int mang[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
    int kichThuoc = sizeof(mang) / sizeof(mang[0]);

    int giaTri1 = 17;
    int giaTri2 = 35;
    int giaTri3 = 40;
    int giaTri4 = 23;
    int giaTri5 = 10;
    int giaTri6 = 36;

    int ketQua1 = timKiem(mang, kichThuoc, giaTri1);
    int ketQua2 = timKiem(mang, kichThuoc, giaTri2);
    int ketQua3 = timKiem(mang, kichThuoc, giaTri3);
    int ketQua4 = timKiem(mang, kichThuoc, giaTri4);
    int ketQua5 = timKiem(mang, kichThuoc, giaTri5);
    int ketQua6 = timKiem(mang, kichThuoc, giaTri6);

    printf("Ket qua tim kiem x = %d: %d\n", giaTri1, ketQua1);
    printf("Ket qua tim kiem x = %d: %d\n", giaTri2, ketQua2);
    printf("Ket qua tim kiem x = %d: %d\n", giaTri3, ketQua3);
    printf("Ket qua tim kiem x = %d: %d\n", giaTri4, ketQua4);
    printf("Ket qua tim kiem x = %d: %d\n", giaTri5, ketQua5);
    printf("Ket qua tim kiem x = %d: %d\n", giaTri6, ketQua6);

    return 0;
}
