#include <stdio.h>



void interchangedownSortInt(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void interchangedownSortFloat(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


void interchangedownSortChar(char a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


#include <string.h>

void interchangedownSortString(char a[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) < 0) {
                char temp[100];
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
}


int main5() {
    int intArr[] = { 4, 2, 9, 1, 5, 6 };
    float floatArr[] = { 4.5, 2.2, 9.1, 1.0, 5.6, 6.3 };
    char charArr[] = { 'd', 'a', 'c', 'b', 'e' };
    char stringArr[][100] = { "apple", "orange", "banana", "pear", "grape" };

    int nInt = sizeof(intArr) / sizeof(intArr[0]);
    int nFloat = sizeof(floatArr) / sizeof(floatArr[0]);
    int nChar = sizeof(charArr) / sizeof(charArr[0]);
    int nString = sizeof(stringArr) / sizeof(stringArr[0]);

    printf("Mang so nguyen chua sap xep: ");
    for (int i = 0; i < nInt; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    printf("Mang so thuc chua sap xep: ");
    for (int i = 0; i < nFloat; i++) {
        printf("%.2f ", floatArr[i]);
    }
    printf("\n");

    printf("Mang ky tu chua sap xep: ");
    for (int i = 0; i < nChar; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n");

    printf("Mang chuoi ky tu chua sap xep: ");
    for (int i = 0; i < nString; i++) {
        printf("%s ", stringArr[i]);
    }
    printf("\n\n\n");


    interchangedownSortInt(intArr, nInt);
    interchangedownSortFloat(floatArr, nFloat);
    interchangedownSortChar(charArr, nChar);
    interchangedownSortString(stringArr, nString);

    printf("Mang so nguyen da sap xep: ");
    for (int i = 0; i < nInt; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    printf("Mang so thuc da sap xep: ");
    for (int i = 0; i < nFloat; i++) {
        printf("%.2f ", floatArr[i]);
    }
    printf("\n");

    printf("Mang ky tu da sap xep: ");
    for (int i = 0; i < nChar; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n");

    printf("Mang chuoi ky tu da sap xep: ");
    for (int i = 0; i < nString; i++) {
        printf("%s ", stringArr[i]);
    }
    printf("\n");

    return 0;
}
