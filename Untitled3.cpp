#include <stdio.h>
int main()
{
	//Nhap vao hai so nguyen
	int a, b;
	printf("Nhap vao so nguyen thu 1: ");
	scanf("%d", &a);
	printf("Nhap vao so nguyen thu 2: ");
	scanf("%d", &b);
	
	//Tim ra so be hon
	if (a < b)
		printf("So nho hon la: %d\n", a);
	else
		printf("So nho hon la: %d\n", b);
	return 0;
}
