#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

void nhapDay(int n, int *a, FILE *f) {
	for (int i = 0; i < n; i++){
		fscanf(f, "%d", a+i);
	}
}

void docFile(int* n, int* m, int** a, int** b) {
	
	char tenFile[] = "input.txt";
//	char tenFile[30];
//	printf("Nhap ten file: ");
//	gets(tenFile);

	FILE* f = fopen(tenFile, "rt");
	if (f == NULL) {
		printf("Doc file khong thanh cong!\n");
		return;
	}
	
	fscanf(f, "%d", n);
	fscanf(f, "%d", m);
	
	*a = (int*)malloc(*n * sizeof(int));
	*b = (int*)malloc(*m * sizeof(int));
	
	nhapDay(*n, *a, f);
	nhapDay(*m, *b, f);
	
	fclose(f);
}

void xuatDay(int n, int *a) {
	for (int i = 0; i < n; i++) {
		if (i != n-1)
			printf("%d, ", *(a+i));
		else 
			printf("%d\n", *(a+i));
	}
}

int timMaxDay(int n, int *a) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (max < *(a+i))
			max = *(a+i);
	}
	
	return max;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int n, int *a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (*(a+j) > *(a+j+1)) {
				swap(a+j, a+j+1);
			}
		}
	}
}

int main() {
	FILE *f;
	
	int n, m;
	int *a = NULL, *b = NULL;
	
	// 1. Đọc từ tập hai dãy số nguyên, có cấp phát động bộ nhớ, in các dãy số ra màn hình
	docFile(&n, &m, &a, &b);
	
	if (a == NULL) {
		printf("Khong doc duoc day a!\n");
		return 1;
	}
	if (b == NULL) {
		printf("Khong doc duoc day b!\n");
		return 1;
	}
	
	printf("Day a: ");
	xuatDay(n, a);
	printf("Day b: ");
	xuatDay(m, b);
	
	// 2. Tính giá trị lớn nhất của dãy a và giá trị lớn nhất của dãy b
	printf("\nGia tri lon nhat cua day a la %d\n", timMaxDay(n, a));
	printf("Gia tri lon nhat cua day b la %d\n", timMaxDay(m, b));
	
	// 3. Sắp xếp dãy a và dãy b theo thự tự giảm dần, sau đó đưa các dãy số đã được sắp xếp ra màn hình
	printf("\nDay a sau khi sap xep theo thu tu giam dan la: ");
	bubbleSort(n, a);
	xuatDay(n, a);
	
	printf("Day b sau khi sap xep theo thu tu giam dan la: ");
	bubbleSort(m, b);
	xuatDay(m, b);
	
	// Giải phóng bộ nhớ
	free(a);
	free(b);
	
	return 0;
}