#include <stdio.h>
int main()
{
	int n, S, P;
	//Nhap
	do
	{
		printf("Nhap so nguyen duong: ");
		scanf("%d",&n);
	}
	while (n<=0);
	int i=1;
	while (i<=n)
	{
		S +=i;
		P +=i;
		i++;
	}
	//Xuat
	printf("S(%d)= %d\n",n,S);
	printf("P(%d)= %d\n",n,P);
	return 0;
}
