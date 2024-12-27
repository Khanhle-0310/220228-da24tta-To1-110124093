#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SV 100
#define MAX_LOP 50

typedef struct {
    char maSV[10];
    char tenSV[50];
    int gioiTinh;
    float diem[10];
    int soMon;
} SINH_VIEN;

typedef struct {
    char maLop[10];
    char tenLop[50];
    int siSo;
    SINH_VIEN danhSachSV[MAX_SV];
} LOP_HOC;

void nhapSinhVien(SINH_VIEN *sv);
void nhapLopHoc(LOP_HOC *lop);
void xuatSinhVien(SINH_VIEN sv);
void xuatLopHoc(LOP_HOC lop);
void luuDanhSachLopHoc(LOP_HOC *lopHoc, int soLop);
int docDanhSachLopHoc(LOP_HOC *lopHoc);
void hienThiSinhVienTheoLop(LOP_HOC *lopHoc, int soLop, char *maLop);
void thongKeGioiTinh(LOP_HOC *lopHoc, int soLop);
void thongKeMonNo(LOP_HOC *lopHoc, int soLop);

int main() {
    LOP_HOC lopHoc[MAX_LOP];
    int soLop;
    
    printf("Nhap so lop hoc: ");
    scanf("%d", &soLop);
    
    for (int i = 0; i < soLop; i++) {
        printf("Nhap thong tin lop hoc %d:\n", i + 1);
        nhapLopHoc(&lopHoc[i]);
    }

    luuDanhSachLopHoc(lopHoc, soLop);

    int soLopDoc;
    soLopDoc = docDanhSachLopHoc(lopHoc);

    printf("\nDanh sach sinh vien cua lop maLop1:\n");
    hienThiSinhVienTheoLop(lopHoc, soLopDoc, "maLop1");

    thongKeGioiTinh(lopHoc, soLopDoc);

    thongKeMonNo(lopHoc, soLopDoc);

    return 0;
}

void nhapSinhVien(SINH_VIEN *sv) {
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv->maSV);
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(sv->tenSV, 50, stdin);
    sv->tenSV[strcspn(sv->tenSV, "\n")] = '\0';
    printf("Nhap gioi tinh (1: Nam, 2: Nu): ");
    scanf("%d", &sv->gioiTinh);
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->soMon);
    for (int i = 0; i < sv->soMon; i++) {
        printf("Nhap diem mon %d: ", i + 1);
        scanf("%f", &sv->diem[i]);
    }
}

void nhapLopHoc(LOP_HOC *lop) {
    printf("Nhap ma lop: ");
    scanf("%s", lop->maLop);
    printf("Nhap ten lop: ");
    getchar();
    fgets(lop->tenLop, 50, stdin);
    lop->tenLop[strcspn(lop->tenLop, "\n")] = '\0';
    printf("Nhap si so: ");
    scanf("%d", &lop->siSo);
    for (int i = 0; i < lop->siSo; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        nhapSinhVien(&lop->danhSachSV[i]);
    }
}

void xuatSinhVien(SINH_VIEN sv) {
    printf("Ma SV: %s\n", sv.maSV);
    printf("Ten SV: %s\n", sv.tenSV);
    printf("Gioi tinh: %s\n", sv.gioiTinh == 1 ? "Nam" : "Nu");
    printf("Diem: ");
    for (int i = 0; i < sv.soMon; i++) {
        printf("%.2f ", sv.diem[i]);
    }
    printf("\n");
}

void xuatLopHoc(LOP_HOC lop) {
    printf("Ma Lop: %s\n", lop.maLop);
    printf("Ten Lop: %s\n", lop.tenLop);
    printf("Si so: %d\n", lop.siSo);
    for (int i = 0; i < lop.siSo; i++) {
        printf("Sinh vien %d:\n", i + 1);
        xuatSinhVien(lop.danhSachSV[i]);
    }
}

void luuDanhSachLopHoc(LOP_HOC *lopHoc, int soLop) {
    FILE *f = fopen("danh_sach_lop_hoc.bin", "wb");
    if (f == NULL) {
        printf("Loi mo tep\n");
        return;
    }
    fwrite(&soLop, sizeof(int), 1, f);
    for (int i = 0; i < soLop; i++) {
        fwrite(&lopHoc[i], sizeof(LOP_HOC), 1, f);
    }
    fclose(f);
}

int docDanhSachLopHoc(LOP_HOC *lopHoc) {
    FILE *f = fopen("danh_sach_lop_hoc.bin", "rb");
    if (f == NULL) {
        printf("Loi mo tep\n");
        return 0;
    }
    int soLop;
    fread(&soLop, sizeof(int), 1, f);
    for (int i = 0; i < soLop; i++) {
        fread(&lopHoc[i], sizeof(LOP_HOC), 1, f);
    }
    fclose(f);
    return soLop;
}

void hienThiSinhVienTheoLop(LOP_HOC *lopHoc, int soLop, char *maLop) {
    for (int i = 0; i < soLop; i++) {
        if (strcmp(lopHoc[i].maLop, maLop) == 0) {
            printf("Danh sach sinh vien cua lop %s:\n", lopHoc[i].maLop);
            for (int j = 0; j < lopHoc[i].siSo; j++) {
                xuatSinhVien(lopHoc[i].danhSachSV[j]);
            }
            return;
        }
    }
    printf("Lop hoc khong ton tai!\n");
}

void thongKeGioiTinh(LOP_HOC *lopHoc, int soLop) {
    for (int i = 0; i < soLop; i++) {
        int nam = 0, nu = 0;
        for (int j = 0; j < lopHoc[i].siSo; j++) {
            if (lopHoc[i].danhSachSV[j].gioiTinh == 1) nam++;
            else nu++;
        }
        printf("Lop %s: Nam = %d, Nu = %d\n", lopHoc[i].maLop, nam, nu);
    }
}

void thongKeMonNo(LOP_HOC *lopHoc, int soLop) {
    for (int i = 0; i < soLop; i++) {
        printf("Lop %s:\n", lopHoc[i].maLop);
        for (int j = 0; j < lopHoc[i].siSo; j++) {
            int soMonNo = 0;
            for (int k = 0; k < lopHoc[i].danhSachSV[j].soMon; k++) {
                if (lopHoc[i].danhSachSV[j].diem[k] < 5) {
                    soMonNo++;
                }
            }
            if (soMonNo > 0) {
                printf("Sinh vien %s co %d mon no\n", lopHoc[i].danhSachSV[j].tenSV, soMonNo);
            }
        }
    }
}

