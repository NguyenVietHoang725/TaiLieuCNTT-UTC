/*
	Cho 1 tệp có cấu trúc sinh viên như sau:
	- Dòng 1: chứa 1 số là số sinh viên
	- Các dòng tiếp theo lần lượt chứa thông tin của sinh viên gồm 
		+ Mã sinh viên
		+ Tên sinh viên
		+ Điểm
	
	Viết chương trình nhập, xuất n sinh viên từ tệp	
*/

#include <stdio.h>
#include <stdlib.h>

struct SV {
	int ma;
	char ten[100];
	float diem;
};

void nhap(int n, SV* sv, FILE* f){
	for (int i = 0; i < n; i++){
		fscanf(f, "%d", &sv[i].ma);
		fgetc(f);
		fgets(sv[i].ten, sizeof(sv[i].ten), f);
		fscanf(f, "%f", &sv[i].diem);
	}
}

void xuat(int n, SV* sv){
	for (int i = 0; i < n; i++){
		printf("%d %s %.2f\n", sv[i].ma, sv[i].ten, sv[i].diem);
	}
}

int main(){
	FILE* f;
	
	int n;
	SV* sv;
	
	f = fopen("sinhvien.txt", "rt");
	
	fscanf(f, "%d", &n);
	
	sv = (SV*) malloc(n * sizeof(SV));
	
	nhap(n, sv, f);
	xuat(n, sv);
	
}