#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_SACH 100

struct SACH {
    char ma_sach[MAX_LEN];
    char ten_sach[MAX_LEN];
    char tac_gia[MAX_LEN];
    char nha_xuat_ban[MAX_LEN];
    int nam_xuat_ban;
    float don_gia;
    int so_luong_nhap;
    float thanh_tien;
    float thue;
    float thuc_tien;
};

void nhap_sach(struct SACH* sach);
void xuat_sach(struct SACH sach);
void nhap_danh_sach_sach(struct SACH sach[], int n);
void xuat_danh_sach_sach(struct SACH sach[], int n);
void tinh_thanh_tien(struct SACH sach[], int n);
void tinh_thuc_tien(struct SACH sach[], int n);
void sap_xep_sach(struct SACH sach[], int n);
void sach_thuc_tien_lon_nhat(struct SACH sach[], int n);
void tinh_tong_so_luong(struct SACH sach[], int n);

int main() {
    int n;
    struct SACH sach[MAX_SACH];

    printf("Nhap so luong sach: ");
    scanf("%d", &n);

    nhap_danh_sach_sach(sach, n);

    tinh_thanh_tien(sach, n);
    tinh_thuc_tien(sach, n);

    printf("\nDanh sach sach ban dau:\n");
    xuat_danh_sach_sach(sach, n);

    sap_xep_sach(sach, n);
    printf("\nDanh sach sach sau khi sap xep theo nam xuat ban (giam dan):\n");
    xuat_danh_sach_sach(sach, n);

    sach_thuc_tien_lon_nhat(sach, n);

    tinh_tong_so_luong(sach, n);

    return 0;
}

void nhap_sach(struct SACH* sach) {
    printf("Nhap ma sach: ");
    scanf("%s", sach->ma_sach);
    
    printf("Nhap ten sach: ");
    scanf(" %[^\n]%*c", sach->ten_sach);
    
    printf("Nhap tac gia: ");
    scanf(" %[^\n]%*c", sach->tac_gia);
    
    printf("Nhap nha xuat ban: ");
    scanf(" %[^\n]%*c", sach->nha_xuat_ban);
    
    printf("Nhap nam xuat ban: ");
    scanf("%d", &sach->nam_xuat_ban);
    
    printf("Nhap don gia: ");
    scanf("%f", &sach->don_gia);
    
    printf("Nhap so luong nhap: ");
    scanf("%d", &sach->so_luong_nhap);
    
    printf("Nhap thue VAT (%%): ");
    scanf("%f", &sach->thue);
    
    sach->thanh_tien = sach->so_luong_nhap * sach->don_gia;
    sach->thuc_tien = sach->thanh_tien + (sach->thanh_tien * sach->thue / 100);
}

void xuat_sach(struct SACH sach) {
    printf("Ma sach: %s\n", sach.ma_sach);
    printf("Ten sach: %s\n", sach.ten_sach);
    printf("Tac gia: %s\n", sach.tac_gia);
    printf("Nha xuat ban: %s\n", sach.nha_xuat_ban);
    printf("Nam xuat ban: %d\n", sach.nam_xuat_ban);
    printf("Don gia: %.2f\n", sach.don_gia);
    printf("So luong nhap: %d\n", sach.so_luong_nhap);
    printf("Thanh tien: %.2f\n", sach.thanh_tien);
    printf("Thue VAT: %.2f%%\n", sach.thue);
    printf("Thuc tien: %.2f\n", sach.thuc_tien);
    printf("-----------------------------------\n");
}

void nhap_danh_sach_sach(struct SACH sach[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);
        nhap_sach(&sach[i]);
    }
}

void xuat_danh_sach_sach(struct SACH sach[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nThong tin sach %d:\n", i + 1);
        xuat_sach(sach[i]);
    }
}

void tinh_thanh_tien(struct SACH sach[], int n) {
    for (int i = 0; i < n; i++) {
        sach[i].thanh_tien = sach[i].so_luong_nhap * sach[i].don_gia;
    }
}

void tinh_thuc_tien(struct SACH sach[], int n) {
    for (int i = 0; i < n; i++) {
        sach[i].thuc_tien = sach[i].thanh_tien + (sach[i].thanh_tien * sach[i].thue / 100);
    }
}

void sap_xep_sach(struct SACH sach[], int n) {
    struct SACH temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sach[i].nam_xuat_ban < sach[j].nam_xuat_ban) {
                temp = sach[i];
                sach[i] = sach[j];
                sach[j] = temp;
            }
        }
    }
}

void sach_thuc_tien_lon_nhat(struct SACH sach[], int n) {
    float max_thuc_tien = sach[0].thuc_tien;
    for (int i = 1; i < n; i++) {
        if (sach[i].thuc_tien > max_thuc_tien) {
            max_thuc_tien = sach[i].thuc_tien;
        }
    }
    printf("\nSach co thuc tien lon nhat (%.2f):\n", max_thuc_tien);
    for (int i = 0; i < n; i++) {
        if (sach[i].thuc_tien == max_thuc_tien) {
            xuat_sach(sach[i]);
        }
    }
}

void tinh_tong_so_luong(struct SACH sach[], int n) {
    int tong_so_luong = 0;
    for (int i = 0; i < n; i++) {
        tong_so_luong += sach[i].so_luong_nhap;
    }
    printf("\nTong so luong sach trong danh sach: %d\n", tong_so_luong);
}
