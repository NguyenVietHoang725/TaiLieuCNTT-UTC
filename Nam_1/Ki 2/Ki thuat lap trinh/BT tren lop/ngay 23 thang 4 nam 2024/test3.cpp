/* 
Cho tệp có cấu trúc như sau:
- Dòng 1: chứa 2 số là số hàng và số cột của ma trận
- Các dòng tiếp theo: chứa các phần tử của ma trận

Viết chương trình nhập vào tên tệp, đọc giá trị và in ra màn hình 
*/

#include <stdio.h>
#include <stdlib.h>

void nhapMT(int n, int m, int** a, FILE* f){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			fscanf(f, "%d", &a[i][j]);
		}
}

void xuatMT(int n, int m, int** a){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("  %d", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	FILE* f;
	
	int n, m;
	int** a;
	
	char tenTep[100];
	printf("Nhap ten tep: ");
	gets(tenTep);
	
	f = fopen(tenTep, "rt");
	
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	
	a = (int**) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++){
		a[i] = (int*) malloc(m * sizeof(int));
	}
	
	nhapMT(n, m, a, f);
	xuatMT(n, m, a);
}
