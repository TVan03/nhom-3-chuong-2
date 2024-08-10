#include <stdio.h>

int timKiem(char mang[], int kichThuoc, char kyTu) {
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] == kyTu) {
            return i;
        }
    }
    return -1;
}

int main2() {
    char mang[] = { 'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A' };
    int kichThuoc = sizeof(mang) / sizeof(mang[0]);

    char kyTu1 = 'R';
    char kyTu2 = 'C';
    char kyTu3 = 'D';
    char kyTu4 = 'Q';

    int ketQua1 = timKiem(mang, kichThuoc, kyTu1);
    int ketQua2 = timKiem(mang, kichThuoc, kyTu2);
    int ketQua3 = timKiem(mang, kichThuoc, kyTu3);
    int ketQua4 = timKiem(mang, kichThuoc, kyTu4);

    printf("Ket qua tim kiem ky tu %c: %d\n", kyTu1, ketQua1);
    printf("Ket qua tim kiem ky tu %c: %d\n", kyTu2, ketQua2);
    printf("Ket qua tim kiem ky tu %c: %d\n", kyTu3, ketQua3);
    printf("Ket qua tim kiem ky tu %c: %d\n", kyTu4, ketQua4);

    return 0;
}
