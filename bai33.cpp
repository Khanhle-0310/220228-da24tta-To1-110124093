#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tuSo;
    int mauSo;
} PHAN_SO;

int gcd(int a, int b);
void rutGon(PHAN_SO *ps);
void ghiVaoTep(PHAN_SO *ds, int n, const char *tenTep);
void docTep(PHAN_SO *ds, int *n, const char *tenTep);
float giaTri(PHAN_SO ps);
PHAN_SO timPhanSoMin(PHAN_SO *ds, int n);
int demPhanSoMin(PHAN_SO *ds, int n, PHAN_SO min);
void sapXep(PHAN_SO *ds, int n);
void hienThi(PHAN_SO *ds, int n);

int main() {
    PHAN_SO ds[100];
    int n = 0;

    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap tu so va mau so cho phan so %d: ", i + 1);
        scanf("%d %d", &ds[i].tuSo, &ds[i].mauSo);
    }

    ghiVaoTep(ds, n, "phanso.txt");

    int m = 0;
    docTep(ds, &m, "phanso.txt");

    for (int i = 0; i < m; i++) {
        rutGon(&ds[i]);
    }

    printf("Danh sach phan so sau khi rut gon: \n");
    hienThi(ds, m);

    PHAN_SO min = timPhanSoMin(ds, m);
    printf("Phan so co gia tri nho nhat: %d/%d\n", min.tuSo, min.mauSo);

    int dem = demPhanSoMin(ds, m, min);
    printf("So luong phan so co gia tri nho nhat: %d\n", dem);

    sapXep(ds, m);

    printf("Danh sach phan so sau khi sap xep: \n");
    hienThi(ds, m);

    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGon(PHAN_SO *ps) {
    int ucln = gcd(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln;
    ps->mauSo /= ucln;
}

void ghiVaoTep(PHAN_SO *ds, int n, const char *tenTep) {
    FILE *f = fopen(tenTep, "w");
    if (f == NULL) {
        printf("Loi mo tep\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %d\n", ds[i].tuSo, ds[i].mauSo);
    }
    fclose(f);
}

void docTep(PHAN_SO *ds, int *n, const char *tenTep) {
    FILE *f = fopen(tenTep, "r");
    if (f == NULL) {
        printf("Loi mo tep\n");
        return;
    }
    while (fscanf(f, "%d %d", &ds[*n].tuSo, &ds[*n].mauSo) != EOF) {
        (*n)++;
    }
    fclose(f);
}

float giaTri(PHAN_SO ps) {
    return (float)ps.tuSo / ps.mauSo;
}

PHAN_SO timPhanSoMin(PHAN_SO *ds, int n) {
    PHAN_SO min = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTri(ds[i]) < giaTri(min)) {
            min = ds[i];
        }
    }
    return min;
}

int demPhanSoMin(PHAN_SO *ds, int n, PHAN_SO min) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (giaTri(ds[i]) == giaTri(min)) {
            dem++;
        }
    }
    return dem;
}

void sapXep(PHAN_SO *ds, int n) {
    PHAN_SO temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTri(ds[i]) < giaTri(ds[j])) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void hienThi(PHAN_SO *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ds[i].tuSo, ds[i].mauSo);
    }
    printf("\n");
}
