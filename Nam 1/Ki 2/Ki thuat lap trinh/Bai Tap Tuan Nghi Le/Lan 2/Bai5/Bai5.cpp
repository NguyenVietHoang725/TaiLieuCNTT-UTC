#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

typedef struct POINT {
	float x;
	float y;
} POINT;

void inputFile(int* n, POINT** a) {
	char fileName[]="input.txt";
//    char fileName[30];
//    printf("Nhap ten File: ");
//    gets(fileName);
    FILE* f = fopen(fileName, "rt");
    if (f == NULL) {
        printf("Doc File ko thanh cong\n");
        return;
    }

    fscanf(f, "%d\n", n);
    
	*a = (POINT*)malloc(*n * sizeof(POINT*));
    for (int i = 0; i < *n; i++) {
		fscanf(f, "%f%f", &(*a)[i].x, &(*a)[i].y);
		fgetc(f);
	}
    
    fclose(f);
}

void xuat(POINT a) {
	printf("(%.2f, %.2f)\n", a.x, a.y);
}

void xuat(int n, POINT* a) {
	for (int i = 0; i < n; i++) {
		xuat(a[i]);
	}
}

POINT timDiemXaGocToaDoNhat(int n, POINT* a) {
	float max = FLT_MIN;
	POINT p;
	for (int i = 0; i < n; i++) {
		float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (temp > max) {
			max = temp;
			p = a[i];
		}
	}
	
	return p;
}

int demSoDoanThangNamBenTrongGPT3(int n, POINT* a, int* check) {
	*check = 0;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].x < 0 && a[i].y < 0) {
			for (int j = i + 1; j < n; j++) {
				if (a[j].x < 0 && a[j].y < 0) {
					cnt += 1;
					*check = 1;
				}
			}
		}
	}
	
	return cnt;
}

float timDoanThangDaiNhat(int n, POINT* a) {
	float max = FLT_MIN;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			float temp = sqrt(pow(a[j].x - a[i].x, 2) + pow(a[j].y - a[i].x, 2));
			if (temp > max) {
				max = temp;
			}
		}
	}
	
	return max;
}

int demDiemThuocGPT1(int n, POINT* a, int* check) {
	*check = 0;
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i].x > 0 && a[i].y > 0 && a[i].x == a[i].y) {
			cnt += 1;
		}
	}
	
	return cnt;
}

int main() {
	FILE* f;
	int n;
	POINT* a;

	// 1. Đọc dữ liệu của dãy điểm từ tệp trên
	inputFile(&n, &a);
	printf("Toa do %d diem doc duoc tu file:\n", n);
	xuat(n, a);
	
	// 2. Xác định một điểm ở xa gốc tọa độ nhất
	POINT p = timDiemXaGocToaDoNhat(n, a);
	printf("\nDiem xa goc toa do nhat la: ");
	xuat(p);
	printf("\n");
	
	// 3. Xác định số đoạn thẳng tạo bởi tập điểm n trên và nằm bên trong góc phần tư thứ 3
	int check;
	int dem1 = demSoDoanThangNamBenTrongGPT3(n, a, &check);
	if (check == 0)
		printf("Khong ton tai doan thang nao nam ben trong goc phan tu thu 3!\n");
	else 
		printf("Co tat ca %d doan thang nam ben trong goc phan tu thu 3!\n", dem1);
	
	// 4. Tìm đoạn thẳng dài nhất
	float max1 = timDoanThangDaiNhat(n, a);
	printf("\nDoan thang dai nhat co do dai la: %.2f\n", max1);
	
	// 5. Đếm số điểm thuộc đường phân giác góc phần tư thứ nhất
	int dem2 = demDiemThuocGPT1(n, a, &check);
	if (check == 0)
		printf("\nKhong ton tai diem nao thuoc duong phan gian goc phan tu thu 1!\n");
	else 
		printf("\nCo tat ca %d diem thuoc duong phan giac goc phan tu thu 1!\n", dem1);
		
	// Giải phóng bộ nhớ
	free(a);
	
	return 0;
}