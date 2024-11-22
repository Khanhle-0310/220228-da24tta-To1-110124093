	#define SIZE 100
	#include<stdio.h>
	void nhapMang(int a[], int n);
	void xuatMang(int a[], int n);
	int tongMang(int a[], int n);
	int tongDuong(int a[], int n);
	int tongLe(int a[], int n);
	int soPhanTuAm(int a[], int n);
	int soPhanTuLe(int a[], int n);
	int soPhanTuNguyenTo(int a[], int n);
	int kiemtranguyento(int n);
	int soNguyenToDauTien(int a[], int n);
	void cacSoDuongLe(int a[], int n);
	int kiemTraSoAm(int a[], int n);
	int main()
	{
		int a[SIZE]	;
		int n, kq;
		
		do
		{
			printf("\nNhap vao so phan tu: ");
			scanf("%d",&n);
		}while(n<=0||n>100);
		
		//Goi ham
		nhapMang(a,n);
		printf("\nCac phan tu trong mang la: ");
		xuatMang(a,n);
		printf("\nTong mang: %d", tongMang(a,n));
		//HOAC
		kq = tongMang(a,n);
		printf("\nTONG MANG: %d", kq);
		printf("\nTong cac so duong trong mang la: %d", tongDuong(a, n));
		printf("\nTong cac phan tu tai vi tri le la: %d", tongLe(a, n));
		printf("\nCac phan tu am trong mang la: %d", soPhanTuAm(a, n));
		printf("\nCac phan tu le trong mang la: %d", soPhanTuLe(a, n));
		printf("\nCac phan tu la so nguyen to: %d", soPhanTuNguyenTo(a, n));
		printf("\nSo nguyen to dau tien la: %d", soNguyenToDauTien(a, n));
		printf("\nCac so duong le trong mang la: ");  cacSoDuongLe(a, n);
		return 0;
	}
	
	void nhapMang(int a[], int n)
	{
		int i;
		i = 0;
		while(i<=n-1)
		{
			printf("\nNhap gia tri tai vi tri %d: ", i);
			scanf("%d", &a[i]);//a + i
			i++;
		}
	}
	void xuatMang(int a[], int n)
	{
		int i;
		for(i=0; i<=n-1; i++)
		{
			printf("%8d", a[i]);//*(a+i)
		}
	}
	int tongMang(int a[], int n)
	{
		int tong = 0;
		int i = 0;
		do
		{
			tong = tong + a[i];
			i++;
		}while(i<=n-1);
		
		return tong;
	}
	int tongDuong(int a[], int n)
	{
		int tong = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				tong +=a[i];
			}
		}
		return tong;
	}
	int tongLe(int a[], int n)
	{
		int tong = 0;
		for (int i = 0; i < n; i++)
		{
			if (i%2!=0)
			tong +=a[i];
		}
		return tong;
	}
	int soPhanTuAm(int a[], int n)
	{
		int dso = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i]<0)
			dso++;
		}
		return dso;
	}
	int soPhanTuLe(int a[], int n)
	{
		int dso = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i]%2 !=0);
			dso++;
		}
		return dso;
	}
	
	int kiemtranguyento(int n)
	{
		if (n<2)
			return 0;
		int dem = 0;
		for (int i=1;i<=n;i++)
		{
			if (n%i==0)
				dem++;
		}
		if (dem==2)
			return 1;
		return 0;
	}
	
	int soPhanTuNguyenTo(int a[], int n)
	{
		int dem=0;
		for (int i=0; i<n; i++)
		{
			if (kiemtranguyento(a[i])==1)
				dem++;
		}
		return dem;
	}
	int soNguyenToDauTien(int a[], int n)
	{
		int u;
		int i;
		for (i = 0; i < n; i++)
		{
			if(kiemtranguyento(a[i])==1)
			{
					u=a[i];
					break;
			}
		}
		return u;
	}
	void cacSoDuongLe(int a[], int n)
	{
		for (int i = 0; i <= n; i++)
		{
			if (a[i]>0 && a[i]%2!=0)
			printf("%3d", a[i]);
		}
	}

