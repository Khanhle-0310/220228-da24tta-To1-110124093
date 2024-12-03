#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhapMang(int **a, int n);
void xuatMang(int *a, int n);
int tinhTong(int *a, int n);
int timGiaTriLonNhat(int *a, int n);
int demSoLanXuatHienMax(int *a, int n, int maxVal);
int demSoLanXuatHienX(int *a, int n, int x);
int kiemTraTonTaiSoDuong(int *a, int n);
void sapXepTangDan(int *a, int n);
void locSoAm(int *a, int n);

int main() {
    int n;
    int *a = NULL;

    printf("Nhap so luong phan tu (n < 50): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 50) {
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }

    nhapMang(&a, n);

    xuatMang(a, n);

    int tong = tinhTong(a, n);
    printf("Tong cua cac gia tri la: %d\n", tong);

    int maxVal = timGiaTriLonNhat(a, n);
    printf("Gia tri lon nhat trong mang la: %d\n", maxVal);

    int countMax = demSoLanXuatHienMax(a, n, maxVal);
    printf("Gia tri %d xuat hien %d lan.\n", maxVal, countMax);

    int x;
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    int countX = demSoLanXuatHienX(a, n, x);
    printf("Gia tri %d xuat hien %d lan.\n", x, countX);

    if (kiemTraTonTaiSoDuong(a, n)) {
        printf("Mang co chua so duong.\n");
    } else {
        printf("Mang khong co so duong.\n");
    }

    sapXepTangDan(a, n);
    printf("Danh sach sau khi sap xep: ");
    xuatMang(a, n);

    locSoAm(a, n);

    free(a);

    return 0;
}

void nhapMang(int **a, int n) {
    *a = (int*) malloc(n * sizeof(int));  
    if (*a == NULL) {
        printf("Khong the cap phat bo nho!\n");
    }
    printf("Nhap %d gia tri:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &(*a)[i]);
    }
}

void xuatMang(int *a, int n) {
    printf("Danh sach gia tri la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int tinhTong(int *a, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
    }
    return tong;
}

int timGiaTriLonNhat(int *a, int n) {
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    return maxVal;
}

int demSoLanXuatHienMax(int *a, int n, int maxVal) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == maxVal) {
            count++;
        }
    }
    return count;
}

int demSoLanXuatHienX(int *a, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

int kiemTraTonTaiSoDuong(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            return 1; 
        }
    }
    return 0; 
}

void sapXepTangDan(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void locSoAm(int *a, int n) {
    printf("Danh sach so am: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

