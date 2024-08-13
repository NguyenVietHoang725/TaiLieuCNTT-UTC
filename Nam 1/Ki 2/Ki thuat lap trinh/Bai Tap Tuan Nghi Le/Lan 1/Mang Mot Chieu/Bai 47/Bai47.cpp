#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 30000
#define MAX_VALUE 20000

// Hàm phát sinh mảng ngẫu nhiên
void generateRandomArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE + 1); // Phát sinh số nguyên từ 0 đến MAX_VALUE
    }
}

// Hàm thống kê tần suất xuất hiện của các phần tử trong mảng
void countFrequency(int *arr, int size, int *frequency) {
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int frequency[MAX_VALUE + 1] = {0}; // Mảng lưu tần suất xuất hiện của các phần tử

    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));

    // Phát sinh mảng ngẫu nhiên
    generateRandomArray(arr, ARRAY_SIZE);

    // Thống kê tần suất xuất hiện của các phần tử
    countFrequency(arr, ARRAY_SIZE, frequency);

    // In tần suất xuất hiện của các phần tử ra màn hình
    printf("Tan suat xuat hien cua cac phan tu:\n");
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (frequency[i] > 0) {
            printf("%d xuat hien %d lan\n", i, frequency[i]);
        }
    }

    return 0;
}