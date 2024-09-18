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
		}
		else if (nv[i].maCV == 2) {
			luong[1] += nv[i].luong;
			cnt2 += 1;
		}
		else if (nv[i].maCV == 3) {
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

int tinhTongLuongTheoMaCV(int n, NV* nv, int* check, int macv) {
	*check = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (nv[i].maCV == macv) {
			sum += nv[i].luong;
			*check = 1;
		}
	}
	
	return sum;
}

int* timCVDongNhat(int n, NV* nv, int* check) {
	*check = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int* temp = (int*)malloc(3 * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		if (nv[i].maCV == 1)
			cnt1 += 1;
		else if (nv[i].maCV == 2)
			cnt2 += 1;
		else if (nv[i].maCV == 3)
			cnt3 += 1;
	}
	
	int max = (cnt1 > cnt2) ? ((cnt1 > cnt3) ? cnt1 : cnt3) : ((cnt2 > cnt3) ? cnt2 : cnt3);
	if (cnt1 == max) {
		temp[*check] = 1;
		*check += 1;
	}
	if (cnt2 == max) {
		temp[*check] = 2;
		*check += 1;
	}
	if (cnt3 == max) {
		temp[*check] = 3;
		*check += 1;
	}
	
	return temp;
}

void xuatDay(int n, int* a) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	int n;
	NV* nv;
	
	// 1. Nhạp từ bàn phím một ds nhân viên
	nhapThongTin(&n, &nv);
	
	xuat(n, nv);
	
	// 2. Tính trung bình lương nhân viên theo mã công việc
	float* luongTB = tinhTrungBinhLuongTheoMaCV(n, nv);
	printf("\nTrung binh luong nhan vien theo ma cong viec:\n");
	printf("Ma cong viec 1 : %.2f$\n", luongTB[0]);
	printf("Ma cong viec 2 : %.2f$\n", luongTB[1]);
	printf("Ma cong viec 3 : %.2f$\n", luongTB[2]);
	
	// Xuất ds nhân viên trên ra tệp văn bản theo dạng: dòng đầu là số nhân viên, 
	// trên mỗi ba dòng tiếp theo là các thông tin của một nhân viên
	FILE* fo;
	char tenFile[] = "output.txt";
//	char tenFile[30]; 
//	printf("Nhap ten file muon ghi vao: ");
//	gets(tenFile);
	
	fo = fopen(tenFile, "wt");
	ghiTep(n, nv, fo);
	
	// Tính tổng tiền lương của nhân viên có mã công việc là 2
	int check;
	int tong = tinhTongLuongTheoMaCV(n, nv, &check, 2);
	if (check == 0)
		printf("\nKhong ton tai nhan vien co ma cong viec la 2!\n");
	else
		printf("\nTong tien luong cua nhan vien co ma cong viec 2 la: %d\n", tong);
		
	// 5. Công việc nào có nhiều nhân viên tham gia nhất
	int* ds = timCVDongNhat(n, nv, &check);
	printf("\nCac cong viec co nhieu nhan vien tham gia nhat la: ");
	xuatDay(check, ds);
	
	// Giải phóng bộ nhớ
	free(nv);
	free(ds);
	return 0;
}