#include<stdio.h>
#include<string.h>

struct CONNGUOI 
{
    char hoten[30], diachi[100], gioitinh[4];
    int tuoi;
    float thunhap;
};

void nhap(CONNGUOI *a);  
void xuat(CONNGUOI a);   

int main() 
{
    CONNGUOI a;
    
    nhap(&a);  
    
    printf("\nThong tin vua nhap la:\n");
    xuat(a);   
    
    return 0;
}

void xuat(CONNGUOI a) 
{
    printf("%s\t%d\t%s\t%s\t%.2f\n", a.hoten, a.tuoi, a.gioitinh, a.diachi, a.thunhap);  
}

void nhap(CONNGUOI *a) 
{
    printf("\nNhap vao ho ten: ");
    gets(a->hoten);  

    printf("\nNhap vao tuoi: ");
    scanf("%d", &a->tuoi);
    getchar();  
    
    printf("\nNhap vao gioi tinh: ");
    gets(a->gioitinh);  
    
    printf("\nNhap vao dia chi: ");
    gets(a->diachi);  
    
    printf("\nNhap vao thu nhap: ");
    scanf("%f", &a->thunhap);  
}

