#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NGAY_THANG 
{
    int ngay;
    int thang;
    int nam;
};

struct SAN_PHAM 
{
    char maSP[50];
    char tenSP[100];
    float donGia;
    struct NGAY_THANG ngaySX;
    float thoiGianSuDung;
};

void nhapSanPham(struct SAN_PHAM *sp);
void hienThiDanhSach(struct SAN_PHAM *danhSachSP, int n);
void timKiemTheoMa(struct SAN_PHAM *danhSachSP, int n, char *maSP);
void timKiemTheoTen(struct SAN_PHAM *danhSachSP, int n, char *tenSP);
void timKiemTheoNamSX(struct SAN_PHAM *danhSachSP, int n, int namSX);
void sapXepTheoDonGia(struct SAN_PHAM *danhSachSP, int n);

int main() 
{
    struct SAN_PHAM *danhSachSP;
    int n;

    printf("Nhap so luong san pham: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong san pham khong hop le.\n");
        return 1;
    }
    getchar();

    danhSachSP = (struct SAN_PHAM *)malloc(n * sizeof(struct SAN_PHAM));
    if (danhSachSP == NULL) 
    {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        nhapSanPham(&danhSachSP[i]);
    }

    printf("\nDanh sach san pham ban dau:\n");
    hienThiDanhSach(danhSachSP, n);

    char maSP[50];
    printf("\nNhap ma san pham can tim: ");
    scanf("%s", maSP);
    timKiemTheoMa(danhSachSP, n, maSP);

    char tenSP[100];
    printf("\nNhap ten san pham can tim: ");
    getchar();  
    scanf("%[^\n]", tenSP);
    timKiemTheoTen(danhSachSP, n, tenSP);

    int namSX;
    printf("\nNhap nam san xuat can tim: ");
    scanf("%d", &namSX);
    timKiemTheoNamSX(danhSachSP, n, namSX);

    sapXepTheoDonGia(danhSachSP, n);
    printf("\nDanh sach san pham sau khi sap xep theo don gia giam dan:\n");
    hienThiDanhSach(danhSachSP, n);

    free(danhSachSP);
    
    return 0;
}

void hienThiDanhSach(struct SAN_PHAM *danhSachSP, int n) 
{
    for (int i = 0; i < n; i++) {
        printf("Ma SP: %s, Ten SP: %s, Don gia: %.2f, Ngay SX: %d/%d/%d, Thoi gian su dung: %.2f nam\n",
               danhSachSP[i].maSP, danhSachSP[i].tenSP, danhSachSP[i].donGia,
               danhSachSP[i].ngaySX.ngay, danhSachSP[i].ngaySX.thang, danhSachSP[i].ngaySX.nam,
               danhSachSP[i].thoiGianSuDung);
    }
}

void nhapSanPham(struct SAN_PHAM *sp) 
{
    printf("Nhap ma san pham: ");
    scanf("%s", sp->maSP);

    printf("Nhap ten san pham: ");
    getchar();  
    scanf("%[^\n]", sp->tenSP);

    printf("Nhap don gia: ");
    if (scanf("%f", &sp->donGia) != 1 || sp->donGia <= 0) {
        printf("Don gia khong hop le.\n");
        return;
    }

    printf("Nhap ngay san xuat(ngay thang nam): ");
    if (scanf("%d %d %d", &sp->ngaySX.ngay, &sp->ngaySX.thang, &sp->ngaySX.nam) != 3) {
        printf("Ngay san xuat khong hop le.\n");
        return;
    }

    printf("Nhap thoi gian su dung (so nam): ");
    if (scanf("%f", &sp->thoiGianSuDung) != 1 || sp->thoiGianSuDung < 0) {
        printf("Thoi gian su dung khong hop le.\n");
        return;
    }
}

void timKiemTheoMa(struct SAN_PHAM *danhSachSP, int n, char *maSP) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (strcmp(danhSachSP[i].maSP, maSP) == 0) 
        {
            printf("San pham tim thay: \n");
            printf("Ma SP: %s, Ten SP: %s, Don gia: %.2f, Ngay SX: %d/%d/%d, Thoi gian su dung: %.2f nam\n",
                   danhSachSP[i].maSP, danhSachSP[i].tenSP, danhSachSP[i].donGia,
                   danhSachSP[i].ngaySX.ngay, danhSachSP[i].ngaySX.thang, danhSachSP[i].ngaySX.nam,
                   danhSachSP[i].thoiGianSuDung);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham co ma %s.\n", maSP);
    }
}

void timKiemTheoTen(struct SAN_PHAM *danhSachSP, int n, char *tenSP) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (strstr(danhSachSP[i].tenSP, tenSP) != NULL) 
        {
            printf("San pham tim thay: \n");
            printf("Ma SP: %s, Ten SP: %s, Don gia: %.2f, Ngay SX: %d/%d/%d, Thoi gian su dung: %.2f nam\n",
                   danhSachSP[i].maSP, danhSachSP[i].tenSP, danhSachSP[i].donGia,
                   danhSachSP[i].ngaySX.ngay, danhSachSP[i].ngaySX.thang, danhSachSP[i].ngaySX.nam,
                   danhSachSP[i].thoiGianSuDung);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham co ten '%s'.\n", tenSP);
    }
}

void timKiemTheoNamSX(struct SAN_PHAM *danhSachSP, int n, int namSX) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (danhSachSP[i].ngaySX.nam == namSX) 
        {
            printf("San pham tim thay: \n");
            printf("Ma SP: %s, Ten SP: %s, Don gia: %.2f, Ngay SX: %d/%d/%d, Thoi gian su dung: %.2f nam\n",
                   danhSachSP[i].maSP, danhSachSP[i].tenSP, danhSachSP[i].donGia,
                   danhSachSP[i].ngaySX.ngay, danhSachSP[i].ngaySX.thang, danhSachSP[i].ngaySX.nam,
                   danhSachSP[i].thoiGianSuDung);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham san xuat trong nam %d.\n", namSX);
    }
}

void sapXepTheoDonGia(struct SAN_PHAM *danhSachSP, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (danhSachSP[i].donGia < danhSachSP[j].donGia) 
            {
                struct SAN_PHAM temp = danhSachSP[i];
                danhSachSP[i] = danhSachSP[j];
                danhSachSP[j] = temp;
            }
        }
    }
}

