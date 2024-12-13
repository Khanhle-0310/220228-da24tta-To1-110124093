#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int n;
    FILE *file;
    char filename[] = "mang.txt";

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file %s!\n", filename);
        return 1;
    }

    fscanf(file, "%d", &n);
    printf("So phan tu trong file: %d\n", n);

    p = (int *)malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Khong the cap phat bo nho!\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &p[i]);
    }

    printf("Danh sach cac gia tri trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", p[i]);
    }
    printf("\n");

    free(p);
    fclose(file);

    return 0;
}

