#include <stdio.h>
int main()
{
	int n;
	do
	{
		printf("Nhap so nguyen duong: ");
		scanf("%d", &n);
	} while (n<=1||n>=10);
	int i=1;
	while (i<=10)
	{
		printf("%d * %d= %d\n",n,i,n*i);
		i++;
	}
	printf("\n");
	printf("Bang cuu chuong\n");
	for (i=2;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
		{
			printf ("%d * %d = %d\n",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}
