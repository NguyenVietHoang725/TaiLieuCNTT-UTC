#include <stdio.h>
#include <stdlib.h>

// Hàm nhập mảng từ file
void nhap(int n, int *a, FILE *fi) {
    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &a[i]);
    }
}

// Hàm xuất mảng ra file
void xuat(int n, int *a, FILE *fo) {
    for (int i = 0; i < n; i++) {
        fprintf(fo, "%d ", a[i]);
    }
    fprintf(fo, "\n");
}

// Hàm hoán đổi giá trị của hai phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng theo thứ tự tăng dần
void bubbleSort(int n, int *a) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    int *a;
    
    FILE *fi = fopen("ARRAY.INP", "r");
    FILE *fo = fopen("ARRAY.OUT", "w");
    
    // Đọc số phần tử của mảng từ file
    fscanf(fi, "%d", &n);
    
    // Cấp phát bộ nhớ cho mảng
    a = (int*)malloc(n * sizeof(int));
    
    // Nhập mảng từ file
    nhap(n, a, fi);
    
    // Xuất mảng ra file trước khi sắp xếp
    xuat(n, a, fo);
    
    // Sắp xếp mảng
    bubbleSort(n, a);
    
    // Xuất mảng ra file sau khi sắp xếp
    xuat(n, a, fo);
    
    // Giải phóng bộ nhớ sau khi sử dụng
    free(a);
    
    // Đóng file
    fclose(fi);
    fclose(fo);
    
    return 0;
}