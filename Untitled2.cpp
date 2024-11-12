#include <stdio.h>
int main()
{
	//Nhap
	char hoten[25], mssv[10], lop[20];
	int namsinh;
	float diem;
	printf("Ma so sinh vien:");
	fflush(stdin);
	scanf("%s", mssv);
	printf("ho ten:");
	fflush(stdin);
	gets(hoten);
	printf("lop:");
	fflush(stdin);
	scanf("%s", lop);
	printf("nam sinh:");
	scanf("%d",&namsinh);
	printf("diem so:");
	scanf("%f",&diem);
	//Xuat
	printf("Ma so sinh vien: %s\n",mssv);
	printf("Ho ten:\n");
	printf("Lop:%s\n",lop);
	printf("Nam sinh: %d\n",namsinh);
	printf("Diem so:%f\n",diem);
	return 0;	
}
