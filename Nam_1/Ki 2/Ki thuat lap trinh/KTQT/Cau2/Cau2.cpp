#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char hoten[30];
	int luong;
	int maCV;
} NV;

void nhapThongTin(int* n, NV** nv) {
    printf("Nhap so luong nhan vien: ");
    scanf("%d", n);
    
    *nv = (NV*)malloc(*n * sizeof(NV));
    printf("\nNhap thong tin cho %d nhan vien:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Ho ten: ");
        fflush(stdin); gets((*nv)[i].hoten);
        printf("Luong: ");
        scanf("%d", &(*nv)[i].luong);
        printf("Ma cong viec: ");
        scanf("%d", &(*nv)[i].maCV);
    }
}

void xuat(int n, NV* nv) {
	for (int i = 0; i < n; i++) {
		printf("|%20s|%10d$|%3d|\n", nv[i].hoten, nv[i].luong, nv[i].maCV);
	}
}

float* tinhTrungBinhLuongTheoMaCV(int n, NV* nv) {
	float* luong;
	luong = (float*)calloc(3, sizeof(float));
	
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	
	for (int i = 0; i < n; i++) {
		if (nv[i].maCV == 1) {
			luong[0] += nv[i].luong;
			cnt1 += 1;
		} else if (nv[i].maCV == 2) {
			luong[1] += nv[i].luong;
			cnt2 += 1;
		} else if (nv[i].maCV == 3) {
			luong[2] += nv[i].luong;
			cnt3 += 1;
		}
	}
	
	if (cnt1 != 0) {
		luong[0] /= cnt1;
	} else {
		luong[0] = 0;
	}
	
	if (cnt2 != 0) {
		luong[1] /= cnt2;
	} else {
		luong[1] = 0;
	}
	
	if (cnt3 != 0) {
		luong[2] /= cnt3;
	} else {
		luong[2] = 0;
	}
	
	return luong;
}

void ghiTep(int n, NV* nv, FILE* fo) {
	fprintf(fo, "So nhan vien: %d\n", n);
	
	for (int i = 0; i < n; i++) {
		fprintf(fo, "\nNhan vien %d:\n", i + 1);
		fprintf(fo, "%s\n", nv[i].hoten);
		fprintf(fo, "%d$\n", nv[i].luong);
		fprintf(fo, "%d\n", nv[i].maCV);
	}
	
	fclose(fo);
}

int main() {
	int n;
	NV* nv;
	
	// 1. Nhập từ bàn phím một ds nhân viên
	nhapThongTin(&n, &nv);
	printf("Danh sach nhan vien:\n");
	xuat(n, nv);
	
	// 2. Tính trung bình lương nhân viên theo mã công việc
	float* luongTB = tinhTrungBinhLuongTheoMaCV(n, nv);
	printf("\nTrung binh luong nhan vien theo ma cong viec:\n");
	printf("Ma cong viec 1 : %.2f$\n", luongTB[0]);
	printf("Ma cong viec 2 : %.2f$\n", luongTB[1]);
	printf("Ma cong viec 3 : %.2f$\n", luongTB[2]);
	
	// 3. Xuất ds nhân viên trên ra tệp văn bản theo dạng: dòng đầu là số nhân viên, 
	// trên mỗi ba dòng tiếp theo là các thông tin của một nhân viên
	FILE* fo;
	char tenFile[] = "output.txt";
//	char tenFile[30]; 
//	printf("Nhap ten file muon ghi vao: ");
//	gets(tenFile);
	
	fo = fopen(tenFile, "wt");
	ghiTep(n, nv, fo);
	
	
	// Giải phóng bộ nhớ
	free(nv);
	return 0;
}