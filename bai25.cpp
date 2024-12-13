#include <stdio.h>
#include <string.h>

#define MAX_MON_HOC 10
#define MAX_LEN 100
#define MAX_SINH_VIEN 100

struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

struct MON_HOC {
    char ma_mh[MAX_LEN];
    float diem;
};

struct SINH_VIEN {
    char mssv[MAX_LEN];
    char hoten[MAX_LEN];
    struct NGAY_THANG ngaysinh;
    char gioi_tinh[MAX_LEN];
    char dia_chi[MAX_LEN];
    int somon;
    struct MON_HOC mon_hoc[MAX_MON_HOC];
};

void nhap_sinh_vien(struct SINH_VIEN* sv);
void xuat_sinh_vien(struct SINH_VIEN sv);
void nhap_danh_sach_sinh_vien(struct SINH_VIEN sv[], int n);
void xuat_danh_sach_sinh_vien(struct SINH_VIEN sv[], int n);
int tim_sinh_vien_theo_mssv(struct SINH_VIEN sv[], int n, char* mssv);
void tim_sinh_vien_theo_ten(struct SINH_VIEN sv[], int n, char* ten);
void tim_sinh_vien_sinh_thang_8(struct SINH_VIEN sv[], int n);
void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN sv[], int n, char* gioi_tinh);
void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN sv[], int n, char* dia_chi);

int main() {
    int n;
    struct SINH_VIEN sinh_vien[MAX_SINH_VIEN];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    nhap_danh_sach_sinh_vien(sinh_vien, n);

    printf("\nDanh sach sinh vien:\n");
    xuat_danh_sach_sinh_vien(sinh_vien, n);

    char mssv[MAX_LEN];
    printf("\nNhap MSSV can tim: ");
    scanf("%s", mssv);
    int index = tim_sinh_vien_theo_mssv(sinh_vien, n, mssv);
    if (index != -1) {
        printf("Sinh vien tim thay:\n");
        xuat_sinh_vien(sinh_vien[index]);
    } else {
        printf("Khong tim thay sinh vien co MSSV %s\n", mssv);
    }

    char ten[MAX_LEN];
    printf("\nNhap ten sinh vien can tim: ");
    scanf(" %[^\n]%*c", ten);
    printf("Danh sach sinh vien co ten %s:\n", ten);
    tim_sinh_vien_theo_ten(sinh_vien, n, ten);

    printf("\nDanh sach sinh vien sinh trong thang 8:\n");
    tim_sinh_vien_sinh_thang_8(sinh_vien, n);

    char gioi_tinh[MAX_LEN];
    printf("\nNhap gioi tinh can tim (Nam/Nu): ");
    scanf(" %[^\n]%*c", gioi_tinh);
    printf("Danh sach sinh vien gioi tinh %s:\n", gioi_tinh);
    tim_sinh_vien_theo_gioi_tinh(sinh_vien, n, gioi_tinh);

    char dia_chi[MAX_LEN];
    printf("\nNhap dia chi can tim: ");
    scanf(" %[^\n]%*c", dia_chi);
    printf("Danh sach sinh vien dia chi %s:\n", dia_chi);
    tim_sinh_vien_theo_dia_chi(sinh_vien, n, dia_chi);

    return 0;
}

void nhap_sinh_vien(struct SINH_VIEN* sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->mssv);
    
    printf("Nhap Ho ten: ");
    scanf(" %[^\n]%*c", sv->hoten);

    printf("Nhap Ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    
    printf("Nhap Gioi tinh: ");
    scanf(" %[^\n]%*c", sv->gioi_tinh);
    
    printf("Nhap Dia chi: ");
    scanf(" %[^\n]%*c", sv->dia_chi);
    
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);
    
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc %d: ", i + 1);
        scanf("%s", sv->mon_hoc[i].ma_mh);
        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &sv->mon_hoc[i].diem);
    }
}

void xuat_sinh_vien(struct SINH_VIEN sv) {
    printf("MSSV: %s\n", sv.mssv);
    printf("Ho ten: %s\n", sv.hoten);
    printf("Ngay sinh: %d/%d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi tinh: %s\n", sv.gioi_tinh);
    printf("Dia chi: %s\n", sv.dia_chi);
    printf("So mon hoc: %d\n", sv.somon);
    
    for (int i = 0; i < sv.somon; i++) {
        printf("Mon hoc %d: %s, Diem: %.2f\n", i + 1, sv.mon_hoc[i].ma_mh, sv.mon_hoc[i].diem);
    }
}

void nhap_danh_sach_sinh_vien(struct SINH_VIEN sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        nhap_sinh_vien(&sv[i]);
    }
}

void xuat_danh_sach_sinh_vien(struct SINH_VIEN sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nThong tin sinh vien %d:\n", i + 1);
        xuat_sinh_vien(sv[i]);
    }
}

int tim_sinh_vien_theo_mssv(struct SINH_VIEN sv[], int n, char* mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].mssv, mssv) == 0) {
            return i;
        }
    }
    return -1;
}

void tim_sinh_vien_theo_ten(struct SINH_VIEN sv[], int n, char* ten) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(sv[i].hoten, ten) != NULL) {
            xuat_sinh_vien(sv[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten %s\n", ten);
    }
}

void tim_sinh_vien_sinh_thang_8(struct SINH_VIEN sv[], int n) {
    for (int i = 0; i < n; i++) {
        if (sv[i].ngaysinh.thang == 8) {
            xuat_sinh_vien(sv[i]);
        }
    }
}

void tim_sinh_vien_theo_gioi_tinh(struct SINH_VIEN sv[], int n, char* gioi_tinh) {
    for (int i = 0; i < n; i++) {
        if (strstr(sv[i].gioi_tinh, gioi_tinh) != NULL) {
            xuat_sinh_vien(sv[i]);
        }
    }
}

void tim_sinh_vien_theo_dia_chi(struct SINH_VIEN sv[], int n, char* dia_chi) {
    for (int i = 0; i < n; i++) {
        if (strstr(sv[i].dia_chi, dia_chi) != NULL) {
            xuat_sinh_vien(sv[i]);
        }
    }
}
