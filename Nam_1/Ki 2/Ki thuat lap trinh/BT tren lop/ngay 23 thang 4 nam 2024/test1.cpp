// Viết chương trình nhập vào một dãy số nguyên có n phần tử
// in ra màn hình trên cùng 1 dòng

#include <stdio.h>
#include <stdlib.h>

void nhap(int n, int* a, FILE* f){
	for (int i = 0; i < n; i++){
		fscanf(f, "%d", a+i);
	}
}

void xuat(int n, int* a){
	for (int i = 0; i < n; i++){
		printf("%d ", *(a+i));
	}
}

int main(){
	FILE* f; // Con trỏ file
	
	int n;
	int* a;
	
	char tenTep[100];
	printf("Nhap ten tep: ");
	gets(tenTep);
	
	// Mở tệp
	f = fopen(tenTep, "rt"); // syntax: fopen("name_file", "mode");
	
	fscanf(f, "%d", &n); 
	
	a = (int*) malloc(n * sizeof(int)); // Cấp phát bộ nhớ động
	
	nhap(n, a, f);

	xuat(n, a);
}