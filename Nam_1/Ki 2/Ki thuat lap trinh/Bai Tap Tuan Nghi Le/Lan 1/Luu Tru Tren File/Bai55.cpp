#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
    if (num <= 1) 
        return 0; // Không phải số nguyên tố
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0; // Không phải số nguyên tố
    }
    return 1; // Là số nguyên tố
}

int main() {
    FILE *fi, *fo;
    int m, n, num;
    int primeCount = 0; // Số lượng số nguyên tố

    // Mở file INPUT để đọc
    fi = fopen("MATRIX.INP", "r");
    if (fi == NULL) {
        printf("Khong the mo file INPUT.\n");
        return 1;
    }

    // Đọc m và n từ file INPUT
    fscanf(fi, "%d %d", &m, &n);

    // Đọc từng số từ file INPUT và kiểm tra xem có phải số nguyên tố không
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fi, "%d", &num);
            if (isPrime(num))
                primeCount++;
        }
    }

    // Đóng file INPUT
    fclose(fi);

    // Mở file OUTPUT để ghi
    fo = fopen("MATRIX.OUT", "w");
    if (fo == NULL) {
        printf("Khong the mo file OUTPUT.\n");
        return 1;
    }

    // Ghi số lượng số nguyên tố vào file OUTPUT
    fprintf(fo, "%d", primeCount);

    // Đóng file OUTPUT
    fclose(fo);

    printf("Da kiem tra va ghi ket qua vao file MATRIX.OUT.\n");

    return 0;
}