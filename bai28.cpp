#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n;
    int arr[MAX_SIZE];

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    printf("Nhap %d gia tri cho mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    FILE *file = fopen("mang.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file!\n");
        return 1;
    }

    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d  ", arr[i]);
    }

    fclose(file);

    printf("Du lieu da duoc ghi vao file mang.txt\n");

    return 0;
}


