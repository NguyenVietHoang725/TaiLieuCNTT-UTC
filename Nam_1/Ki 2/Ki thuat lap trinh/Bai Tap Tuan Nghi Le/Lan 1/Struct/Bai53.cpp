#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

struct SV{
	char masv[10];
	char tensv[30];
	int namsinh;
	float diemToan, diemLy, diemHoa, diemTB;
};

void nhapSV(SV *a, int i){
	printf("\nSinh vien thu %d:\n", i);
	printf("   Ma sinh vien: ");
	fflush(stdin); gets(a->masv);
	printf("   Ten sinh vien: ");
	fflush(stdin); gets(a->tensv);
	printf("   Nam sinh: ");
	scanf("%d", &a->namsinh);
	printf("   Diem Toan: ");
	scanf("%f", &a->diemToan);
	printf("   Diem Ly: ");
	scanf("%f", &a->diemLy);
	printf("   Diem Hoa: ");
	scanf("%f", &a->diemHoa);
	a->diemTB = (a->diemToan + a->diemLy + a->diemHoa) / 3;
}

void nhapSV(int n, SV *sv){
	for (int i = 0; i < n; i++){
		nhapSV(sv+i, i);
	}
}

void xuatSV(SV sv){
	printf("%10s %30s %10d %10.2f %10.2f %10.2f %10.2f\n", sv.masv, sv.tensv, sv.namsinh, sv.diemToan, sv.diemLy, sv.diemHoa, sv.diemTB);
}

void xuatSV(int n, SV *sv){
	printf("     Ma SV                      Ho va ten   Nam sinh  Diem Toan    Diem Ly   Diem Hoa    Diem TB\n");
	for (int i = 0; i < n; i++){
		xuatSV(*(sv+i));
	}
}

SV timSinhVienDiemTBCaoNhat(int n, SV *sv){
	float max = FLT_MIN;
	SV temp;
	for (int i = 0; i < n; i++){
		if (sv[i].diemTB > max){
			max = sv[i].diemTB;
			temp = *(sv+i);
		}	
	}
	
	return temp;
}

int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	
	SV *sv;
	sv = (SV*)malloc(n * sizeof(SV));
	
	printf("\nNhap lan luot thong tin cua %d sinh vien:", n);
	nhapSV(n, sv);
	printf("\nDanh sach thong tin sinh vien:\n");
	xuatSV(n, sv);
	
	SV maxTB = timSinhVienDiemTBCaoNhat(n, sv);
	printf("\nSinh vien co diem trung binh cao nhat la:\n");
	printf("     Ma SV                      Ho va ten   Nam sinh  Diem Toan    Diem Ly   Diem Hoa    Diem TB\n");
	xuatSV(maxTB);
}