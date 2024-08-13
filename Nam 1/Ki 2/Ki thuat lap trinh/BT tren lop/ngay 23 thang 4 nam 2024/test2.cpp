/*
Đề bài: Cho một tệp có cấu trúc như sau:
- Dòng 1 chứa số bậc của đa thức 1
- Dòng 2 chứa các hệ số của đa thức 1
- Dòng 3 chứa số bậc của đa thức 2
- Dòng 4 chứa các hệ số của đa thức 2

Viết chương trình nhập vào tên tệp, in ra màn hình 2 đa thức
*/

#include <stdio.h>
#include <stdlib.h>

void nhapDaThuc(int n, float* a, FILE* f){
	for (int i = 0; i <= n; i++){
		fscanf(f, "%f", a+i);
	}
}

void xuatDaThuc(int n, float* a){
	for (int i = 0; i <= n; i++){
		if (i == 0)
			printf("%.2f + ", *(a+i));
		else if (i != n)
			printf("%.2f*x^%d + ", *(a+i), i);
		else 
			printf("%.2f*x^%d\n", *(a+i), i);
	}
}


int main(){
	FILE* f;
	
	int n, m;
	float* a;
	float* b;
	
	char tenTep[100];
	printf("Nhap ten tep: ");
	gets(tenTep);
	
	// Mở tệp
	f = fopen(tenTep, "rt"); // syntax: fopen("name_file", "mode");
	
	fscanf(f, "%d", &n); 
	
	a = (float*) malloc(n * sizeof(float)); // Cấp phát bộ nhớ động
	nhapDaThuc(n, a, f);
	
	fscanf(f, "%d", &m);
	b = (float*) malloc(n * sizeof(float));
	nhapDaThuc(m, b, f);
	
	
	xuatDaThuc(n, a);
	xuatDaThuc(m, b);
}