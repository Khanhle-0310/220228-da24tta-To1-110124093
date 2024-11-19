#include <stdio.h>

void inGiaTriTu1DenN(int n);
void inGiaTriChan(int n);
void inGiaTriChiaHetCho5(int n);
void inGiaTriSoNguyenToNhoN(int n);
void inTongCacGiaTriTu1DenN(int n);
void inTongCacSoLeTu1DenN(int n);
int main()
{
	int n;
	do
	{
		printf("Nhap mot so nguyen duong n (n < 100): ");
		scanf("%d", &n);
	} while (n>=100||n<=0);

	printf("\nCac gia tri tu 1 den %d: ", n); 
	inGiaTriTu1DenN(n);
	printf("\nCac gia tri tu 1 den %d: ", n); 
	inGiaTriChan(n);
	printf("\nCac gia tri chia het cho 5 la: ", n); 
	inGiaTriChiaHetCho5(n);
	printf("\nCac gia tri so nguyen to nho hon N la: ", n);
	inGiaTriSoNguyenToNhoN(n);
	printf("\nTong cac gia tri tu 1 den n la: ", n);
	inTongCacGiaTriTu1DenN(n);
	printf("\nTong cac gia tri so le tu 1 den n la: ", n);
	inTongCacSoLeTu1DenN(n);
	return 0;
}

void inGiaTriTu1DenN(int n)
{
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void inGiaTriChan(int n)
{
	for (int i = 2; i <= n; i += 2 ) 
	{
		printf("%d ", i);
	}
	printf("\n");
}

void inGiaTriChiaHetCho5(int n)
{
	for (int i = 5; i <= n; i += 5 )
	{
		printf("%d ", i);
	}
	printf("\n");
}

void inGiaTriSoNguyenToNhoN(int n)
{
	for (int i; i < n; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
}

void inTongCacGiaTriTu1DenN(int n)
{
	int s = 0;
	for (int i=1; i<=n; i++)
		s += i;
		printf("Tong= %d ",s);
		printf("\n");
}

void inTongCacSoLeTu1DenN(int n)
{
	int s = 0;
	for(int i=1;i <= n; i++)
	{ 
		if (i%2!=0)
		s+=i;
	} 
	printf("Tong= %d",s);

}
