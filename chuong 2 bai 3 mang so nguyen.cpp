#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demSoChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int demSoLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int demPhanTuX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

int demPhanTuLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

int tongMang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void xuatSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

bool laSoHoanThien(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void xuatSoHoanThien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatViTriChanLe(int a[], int n, bool chan) {
    for (int i = 0; i < n; i++) {
        if ((i % 2 == 0) == chan) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatMaxMinKemViTri(int a[], int n) {
    int max = timMax(a, n);
    int min = timMin(a, n);
    printf("Gia tri lon nhat la %d o vi tri: ", max);
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\nGia tri nho nhat la %d o vi tri: ", min);
    for (int i = 0; i < n; i++) {
        if (a[i] == min) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void ghepMangTangDan(int a[], int b[], int n, int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }
}

int main3() {
    int choice, n, m, x;
    int a[100], b[100], c[200];

    do {
        printf("\nMenu:");
        printf("\n1. Nhap/xuat mang");
        printf("\n2. Tim max/min");
        printf("\n3. Dem so phan tu chan/le");
        printf("\n4. Tim kiem phan tu x");
        printf("\n5. Dem so phan tu x");
        printf("\n6. Dem so phan tu lon hon x");
        printf("\n7. Tinh tong cac phan tu");
        printf("\n8. Xuat cac so nguyen to");
        printf("\n9. Xuat cac so hoan thien");
        printf("\n10. Xuat phan tu o vi tri chan/le");
        printf("\n11. Xuat max/min kem vi tri");
        printf("\n12. Ghep mang tang dan");
        printf("\n13. Thoat");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so phan tu cua mang: ");
            scanf("%d", &n);
            nhapMang(a, n);
            printf("Mang vua nhap: ");
            xuatMang(a, n);
            break;
        case 2:
            printf("Max: %d\n", timMax(a, n));
            printf("Min: %d\n", timMin(a, n));
            break;
        case 3:
            printf("So phan tu chan: %d\n", demSoChan(a, n));
            printf("So phan tu le: %d\n", demSoLe(a, n));
            break;
        case 4:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &x);
            int vt;
            vt = timKiemTuyenTinh(a, n, x);
            if (vt != -1) {
                printf("Tim kiem tuyen tinh: Phan tu %d nam o vi tri %d\n", x, vt);
            }
            else {
                printf("Tim kiem tuyen tinh: Khong tim thay phan tu %d\n", x);
            }
            vt = timKiemNhiPhan(a, n, x);
            if (vt != -1) {
                printf("Tim kiem nhi phan: Phan tu %d nam o vi tri %d\n", x, vt);
            }
            else {
                printf("Tim kiem nhi phan: Khong tim thay phan tu %d\n", x);
            }
            break;
        case 5:
            printf("Nhap gia tri x: ");
            scanf("%d", &x);
            printf("So phan tu %d xuat hien: %d lan\n", x, demPhanTuX(a, n, x));
            break;
        case 6:
            printf("Nhap gia tri x: ");
            scanf("%d", &x);
            printf("So phan tu lon hon %d: %d\n", x, demPhanTuLonHonX(a, n, x));
            break;
        case 7:
            printf("Tong cac phan tu: %d\n", tongMang(a, n));
            break;
        case 8:
            printf("Cac so nguyen to trong mang: ");
            xuatSoNguyenTo(a, n);
            break;
        case 9:
            printf("Cac so hoan thien trong mang: ");
            xuatSoHoanThien(a, n);
            break;
        case 10:
            printf("Cac phan tu o vi tri chan: ");
            xuatViTriChanLe(a, n, true);
            printf("Cac phan tu o vi tri le: ");
            xuatViTriChanLe(a, n, false);
            break;
        case 11:
            xuatMaxMinKemViTri(a, n);
            break;
        case 12:
            printf("Nhap so phan tu cua mang b: ");
            scanf("%d", &m);
            nhapMang(b, m);
            ghepMangTangDan(a, b, n, m, c);
            printf("Mang a va b ghep lai va sap xep tang dan: ");
            xuatMang(c, n + m);
            break;
        case 13:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 13);

    return 0;
}
