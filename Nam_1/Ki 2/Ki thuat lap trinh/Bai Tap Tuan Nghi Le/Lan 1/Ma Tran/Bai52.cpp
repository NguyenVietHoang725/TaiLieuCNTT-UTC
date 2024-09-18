#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

void nhapMT(int n, int **a){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatMT(int n, int **a){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void xuatDay(int n, int *a){
	for (int i = 0; i < n; i++){
		printf("%5d", a[i]);
	}
}

int timMaxTrenDCC(int n, int **a){
	int max = INT_MIN;
	for (int i = 0; i < n; i++){
		if (a[i][i] > max)
			max = a[i][i];
	}
	
	return max;
}

float tinhTBCPhanTuNhoHonX(int n, int **a, int x){
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] < x){
			sum += a[i][j];
			cnt += 1;
			}
		}
	}
	
	return (float)sum / cnt;
}

int* timHangTongLonNhat(int n, int **a, int *index, int *max){
	*max = INT_MIN;
	int *hangmax;
	hangmax = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < n; j++){
			sum += a[i][j];
		}
		if (sum > *max){
			*max = sum;	
			*index = i;
		}
	}
	
	for (int i = 0; i < n; i++){
		hangmax[i] = a[*index][i];
	}
	
	return hangmax;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int n, int *a){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

int** sapXepMaTran(int n, int **a){
	int *day;
	day = (int*)malloc(n*n * sizeof(int));
	int size = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			day[size] = a[i][j];
			size += 1;
		}
	}
	
	bubbleSort(size, day);
	
	int **mt;
	mt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		mt[i] = (int*)malloc(n * sizeof(int));
	}
	
	size = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mt[i][j] = day[size];
			size += 1;
		}
	}
	
	free(day);
	
	return mt;
}

int main(){
	int n;
	printf("Nhap bac cua ma tran vuong A: ");
	scanf("%d", &n);
	
	int **a;
	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		a[i] = (int*)malloc(n * sizeof(int));
	}
	
	printf("\nNhap gia tri cua cac phan tu:\n");
	nhapMT(n, a);
	printf("\nMa tran vua nhap la:\n");
	xuatMT(n, a);
	
	printf("\nGia tri lon nhat tren duong cheo chinh la: %d\n", timMaxTrenDCC(n, a));
	
	int x;
	printf("\nNhap gia tri cua x: ");
	scanf("%d", &x);
	printf("Gia tri trung binh cac phan tu nho hon x = %d la: %.2f\n", x, tinhTBCPhanTuNhoHonX(n, a, x));
	
	int index, max;
	int *dongmax = timHangTongLonNhat(n, a, &index, &max);
	printf("\nDong co tong lon nhat la dong %d: ", index);
	xuatDay(n, dongmax);
	printf("\nHang nay co tong bang %d\n", max);
	
	int **mt = sapXepMaTran(n, a);
	printf("\nMa tran sau khi duoc sap xep la:\n");
	xuatMT(n, mt);
	
	 for (int i = 0; i < n; i++){
        free(a[i]);
        free(mt[i]);
    }
    free(a);
    free(mt);
    
    free(dongmax);
    
    return 0;
}