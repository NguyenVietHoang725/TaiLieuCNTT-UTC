#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

void insertMT(int n, int **a, FILE *f) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}
}

void docFile(int* n, int*** a, FILE* f) {
	char tenFile[] = "input1.txt";
//	char tenFile[30];
//	printf("Enter the name of the file: ");
//	gets(tenFile);
	
	f = fopen(tenFile, "rt");
	if (f == NULL) {
		printf("Can't read file %s!\n", tenFile);
		return;
	}	
	
	fscanf(f, "%d", n);
	
	*a = (int**)malloc(*n * sizeof(int*));
	for (int i = 0; i < *n; i++) {
		(*a)[i] = (int*)malloc(*n * sizeof(int));
	}
	
	insertMT(*n, *a, f);
	
	fclose(f);
}

void printMT(int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

void printArray(int n, int *a) {
	for (int i = 0; i < n; i++) {
		printf("%3d", a[i]);
	}
}

float averageElementsBelowSubDiagonal(int n, int **a) {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i < n; i++)
		for (int j = n-1; j > 0; j--) {
			if (i + j >= n) {
				sum += a[i][j];
				cnt += 1;
			}
		}
		
	if (cnt == 0) return 0;
	return (float)sum / cnt;
}

bool isUpperTriangularMT(int n, int **a) {
	for (int i = 1; i < n; i++)
		for (int j = n-1; j > 0; j--) {
			if (j - i < 0) {
				if (a[i][j] != 0)
					return false;
			}
		}
	
	return true;
}

bool isSymmetricMT(int n, int **a) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != j)
				if (a[i][j] != a[j][i])
					return false;
		}
	
	return true;
}

int* findMaxRow(int n, int **a, int *index, int *max) {
	*max = INT_MIN;
	int *max_row;
	max_row = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		if (sum > *max) {
			*max = sum;	
			*index = i;
		}
	}
	
	for (int i = 0; i < n; i++) {
		max_row[i] = a[*index][i];
	}
	
	return max_row;
}

int main() {
	FILE *f;
	
	int n;
	int **a;
	
	// 1. Đọc dữ liệu của ma trận từ tệp
	docFile(&n, &a, f);
	
	printf("The matrix is:\n");
	printMT(n, a);
	
	// 2. Tính trung bình cộng các phần tử nằm dưới đường chéo phụ
	printf("\nAverage of the elements below the sub diagonal is equal to %.2f\n", averageElementsBelowSubDiagonal(n, a));
	
	// 3. Kiểm tra có phải ma trận tam giác trên
	if (isUpperTriangularMT(n, a))
		printf("\nThe matrix is an upper triangular matrix!\n");
	else 
		printf("\nThe matrix isn't an upper triangular matrix!\n");
	
	// 4. Kiểm tra có phải ma trận đối xứng
	if (isSymmetricMT(n, a))
		printf("\nThe matrix is a symmetric matrix!\n");
	else
		printf("\nThe matrix isn't a symmetric matrix!\n");
	
	// 5. Tìm hàng có tổng lớn nhất
	int index, max;
	int *max_row = findMaxRow(n, a, &index, &max);
	printf("\nThe row with the largest total is %d: ", index);
	printArray(n, max_row);
	printf("\nThis row has a total of %d\n", max);
	
	// Giải phóng bộ nhớ
	for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    fclose(f);
    return 0;
}
