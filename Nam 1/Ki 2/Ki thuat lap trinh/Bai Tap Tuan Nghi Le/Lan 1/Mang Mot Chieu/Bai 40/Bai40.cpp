#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Hàm nhập mảng
void nhapMang(int arr[], int *n) {
    srand(time(NULL)); // Hàm srand(time(NULL)) sẽ giúp khởi tạo bộ sinh số ngẫu nhiên dựa trên thời gian hiện tại

    printf("Nhap so luong phan tu n: ");
    scanf("%d", n);

    if (*n > 0) {
        arr[0] = rand() % 100; // Khởi tạo phần tử đầu tiên
        // Hàm rand() sẽ phát sinh số ngẫu nhiên và tạo mảng có thứ tự tăng dần
        for (int i = 1; i < *n; i++) {
            arr[i] = arr[i - 1] + rand() % 100;// Khởi tạo ngẫu nhiên từng phần tử chỉ số 1 đến n - 1
        }
    }
}

// Hàm xuất mảng
void xuatMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main() {
    int myArray[MAX];
    int nSize;

    nhapMang(myArray, &nSize);
    xuatMang(myArray, nSize);

    return 0;
}
