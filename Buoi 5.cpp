#include <stdio.h>
#define SIZE 100

void nhapMang(float a[], int n);
void xuatMang(float a[], int n);
float tinhTong(float a[], int n);
float trungBinhCongLe(float a[], int n);
int demSoDuong(float a[], int n);
void thuTuTangDan(float a[], int n);
void cacGiaTriLe(float a[], int n);
void inViTriZero(float a[], int n);
float timGiaTriLonNhat(float a[], int n);
int timViTriGiaTriLonNhat(float a[], int n);
int kiemTraToanSoAm(float a[], int n);

int main() 
{
    float a[SIZE];
    int n;

    do {
        printf("Nhap so phan tu n (0 < n <= %d): ", SIZE);
        scanf("%d", &n);
    } while (n <= 0 || n > SIZE); 

    nhapMang(a, n);
    printf("\nMang da nhap: ");  
    xuatMang(a, n); 
    printf("\nTong cac phan tu: %.2f", tinhTong(a, n));
    printf("\nTrung binh cong tai vi tri le la: %.1f", trungBinhCongLe(a, n));
    printf("\nSo phan tu duong trong mang la: %d", demSoDuong(a, n));
    printf("\nCac gia tri tai vi tri le cua mang la:\n"); 
    cacGiaTriLe(a, n);
    printf("\nCac vi tri co gia tri la so 0:\n"); 
    inViTriZero(a, n);
    printf("Gia tri lon nhat trong mang la: %.2f\n", timGiaTriLonNhat(a, n));
    printf("Vi tri cua gia tri lon nhat dau tien trong mang la: %d\n", timViTriGiaTriLonNhat(a, n));
    
    if (kiemTraToanSoAm(a, n)) {
        printf("Mang co toan so am.\n");
    } else {
        printf("Mang khong co toan so am.\n");
    }

    return 0;
}

void nhapMang(float a[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);  
    }
}

void xuatMang(float a[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("%.2f ", a[i]);  
    }
}

float tinhTong(float a[], int n) 
{
    float sum = 0;
    for (int i = 0; i < n; i++) 
	{
        sum += a[i];  
    }
    return sum;
}

float trungBinhCongLe(float a[], int n)
{
    float tbc = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
	{
		if((i+1) % 2 != 0)
		{
			tbc += a[i];
			count++;
		}
	}
	if(count == 0) return 0;  
	return tbc / count;  

int demSoDuong(float a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        }
    }
    return count;
}

void thuTuTangDan(float a[], int n)
{
    int i, j;
    float dasapxep;
    for (i = 0; i < n - 1; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			if (a[i] > a[j]) 
			{
				dasapxep = a[i];
				a[i] = a[j];
				a[j] = dasapxep;
			}
		}
	}
	printf("\nCac phan tu tang dan trong mang: ");
	for(i = 0; i < n; i++) 
	{
		printf("%8.2f ", a[i]);
	}
}

void cacGiaTriLe(float a[], int n) 
{
    for (int i = 1; i < n; i += 2) 
	{ 
        printf("a[%d] = %.2f\n", i, a[i]);
    }
}

void inViTriZero(float a[], int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("Vi tri co gia tri 0: %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co gia tri 0 trong mang.\n");
    }
}

float timGiaTriLonNhat(float a[], int n) {
    float max = a[0];  
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];  
        }
    }
    return max;
}

int timViTriGiaTriLonNhat(float a[], int n) {
    int viTriMax = 0; 
    for (int i = 1; i < n; i++) {
        if (a[i] > a[viTriMax]) {
            viTriMax = i;
        }
    }
    return viTriMax; 
}

int kiemTraToanSoAm(float a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            return 0;  
        }
    }
    return 1;  
}

