#include <stdio.h>
int main()
{
	char pheptoan;
	int a, b;
	do
	{
	printf("Nhap hai so nguyen: ");
	scanf("%d %d",&a,&b);
	} while (a<b);
	printf("Nhap phep toan: ");
	fflush(stdin);
	scanf("%c",&pheptoan);
	switch(pheptoan)
	
	case '+':
	 printf ("Tong la %d",a+b); break;
	case '-':
	 printf ("Hieu la %d",a-b); break;
	case '*':
	 printf ("Tich la %d",a*b); break;
	case '/':
	 printf ("Thuong la: %.2f",(float)a/b); break;
	)
	return 0;
}
