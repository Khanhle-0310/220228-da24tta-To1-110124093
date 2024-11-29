#include <stdio.h>

#define ROW 10
#define COL 10

void nhapMang(int a[ROW][COL], int m, int n);
void xuatMang(int a[ROW][COL], int m, int n);
int tinhTong(int a[ROW][COL], int m, int n);
void tongDong(int a[ROW][COL], int m, int n);
void tongCot(int a[ROW][COL], int m, int n);
int kiemTraDongAm(int a[ROW][COL], int m, int n, int k);
void SNTCotk(int a[ROW][COL], int m, int n);
int kiemtraSNT(int n);
void dongkGiamDan(int a[ROW][COL], int m, int k);
int kiemTraCotLe(int a[ROW][COL], int m, int n, int k);
int kiemTraTonTai(int a[ROW][COL], int m, int n, int x);
void timViTri(int a[ROW][COL], int m, int n, int x);
void timMaxDongK(int a[ROW][COL], int m, int k);
void timMinDongK(int a[ROW][COL], int m, int k);

int main() {
    int a[ROW][COL];
    int m, n, k, x;

    do {
        printf("Nhap so dong m (1 <= m <= 10): ");
        scanf("%d", &m);
        printf("Nhap so cot n (1 <= n <= 10): ");
        scanf("%d", &n);
    } while ((m <= 0 || m > 10) || (n <= 0 || n > 10));

    nhapMang(a, m, n);
    printf("\nCac phan tu trong mang: \n");
    xuatMang(a, m, n);
    printf("\n");

    printf("Tong mang = %d\n", tinhTong(a, m, n));

    tongDong(a, m, n);
    printf("\n");
    tongCot(a, m, n);
    printf("\n");

    printf("Nhap so dong k (0 <= k < m): ");
    scanf("%d", &k);
    if (kiemTraDongAm(a, m, n, k)) {
        printf("Dong %d co chua so am.\n", k);
    } else {
        printf("Dong %d khong co so am.\n", k);
    }

    SNTCotk(a, m, n);

    printf("\nNhap so dong k (0 <= k < m) de sap xep giam dan: ");
    scanf("%d", &k);
    dongkGiamDan(a, m, k);
    printf("\nMang sau khi sap xep dong %d giam dan: \n", k);
    xuatMang(a, m, n);

    printf("\nNhap so cot k (0 <= k < n) de kiem tra co toan so le: ");
    scanf("%d", &k);
    if (kiemTraCotLe(a, m, n, k)) {
        printf("Cot %d co toan so le.\n", k);
    } else {
        printf("Cot %d khong toan so le.\n", k);
    }

    printf("Nhap gia tri x can kiem tra: ");
    scanf("%d", &x);
    if (kiemTraTonTai(a, m, n, x)) {
        printf("Gia tri %d ton tai trong mang.\n", x);
    } else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }
    timViTri(a, m, n, x);
    
    printf("\nNhap dong k (0 <= k < m) de tim gia tri lon nhat: ");
    scanf("%d", &k);
    timMaxDongK(a, m, k);
    
    printf("\nNhap dong k (0 <= k < m) de tim gia tri nho nhat: ");
    scanf("%d", &k);
    timMinDongK(a, m, k);
    
    return 0;
}

void timMinDongK(int a[ROW][COL], int m, int k) {
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le!\n");
        return;
    }

    int min = a[k][0];
    for (int j = 1; j < COL; j++) {
        if (a[k][j] < min) {
            min = a[k][j];
        }
    }

    printf("Gia tri nho nhat tren dong %d la: %d\n", k, min);
}

void timMaxDongK(int a[ROW][COL], int m, int k) {
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le!\n");
        return;
    }

    int max = a[k][0]; 
    for (int j = 1; j < COL; j++) {
        if (a[k][j] > max) {
            max = a[k][j];
        }
    }

    printf("Gia tri lon nhat tren dong %d la: %d\n", k, max);
}

void timViTri(int a[ROW][COL], int m, int n, int x) {
    int found = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                printf("Gia tri %d ton tai tai vi tri: Dong %d, Cot %d\n", x, i, j);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }
}

int kiemTraTonTai(int a[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                return 1;
            }
        }
    }
    return 0;
}

int kiemTraCotLe(int a[ROW][COL], int m, int n, int k) {
    if (k < 0 || k >= n) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        if (a[i][k] % 2 == 0) {
            return 0;
        }
    }

    return 1;
}

void dongkGiamDan(int a[ROW][COL], int m, int k) {
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le!\n");
        return;
    }
    for (int i = 0; i < COL - 1; i++) {
        for (int j = i + 1; j < COL; j++) {
            if (a[k][i] < a[k][j]) {
                int temp = a[k][i];
                a[k][i] = a[k][j];
                a[k][j] = temp;
            }
        }
    }
}

void SNTCotk(int a[ROW][COL], int m, int n) {
    int k;
    do {
        printf("\nNhap cot thu k (0 <= k < n): ");
        scanf("%d", &k);
    } while(k < 0 || k >= n);
    
    int kt = 0;
    for (int i = 0; i < m; i++) {
        if (kiemtraSNT(a[i][k]) == 1) {
            kt = 1;
            break;
        }
    }

    if (kt) {
        printf("Cot thu %d co ton tai so nguyen to\n", k);
    } else {
        printf("Cot thu %d khong ton tai so nguyen to\n", k);
    }
}

int kiemtraSNT(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int kiemTraDongAm(int a[ROW][COL], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[k][i] < 0) {
            printf("Dong %d co so am.\n", k);
            return 1;
        }
    }
    printf("Dong %d khong co so am.\n", k);
    return 0;
}

void tongCot(int a[ROW][COL], int m, int n) {
    for (int j = 0; j < n; j++) {
        int tong = 0;
        for (int i = 0; i < m; i++) {
            tong += a[i][j];
        }
        printf("Tong cac phan tu tren cot %d = %d\n", j, tong);  
    }
}

void tongDong(int a[ROW][COL], int m, int n) {
    for (int i = 0; i < m; i++) { 
        int tong = 0;  
        for (int j = 0; j < n; j++) {  
            tong += a[i][j]; 
        }
        printf("Tong cac phan tu tren dong %d = %d\n", i, tong);  
    }
}

int tinhTong(int a[ROW][COL], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

void xuatMang(int a[ROW][COL], int m, int n) {
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) {  
            printf("%d ", a[i][j]); 
        }
        printf("\n");  
    }
}

void nhapMang(int a[ROW][COL], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("\nNhap a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

