#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
void nhapMT(int n, int **a, FILE *f) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(f, "%d", &a[i][j]);
		}
	}
}

void docFile(int *n, int***a, FILE *f) {
	char tenFile[] = "input.txt";
//	char tenFile[30];
//	printf("Nhap ten file: ");
//	gets(tenFile);
	
	f = fopen(tenFile, "rt");
	
	if (f == NULL) {
		printf("Khong doc duoc file %s\n", tenFile);
		return;
	}
	
	fscanf(f, "%d\n", n);
	
	*a = (int**)malloc(*n * sizeof(int*));
	for (int i = 0; i < *n; i++) {
		(*a)[i] = (int*)malloc(*n * sizeof(int));
	}
	
	nhapMT(*n, *a, f);
	
	fclose(f);
}

void xuatMT(int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("| %d ", a[i][j]);
		}
		printf("|\n");
	}
}

int timMinCuaMT(int n, int **a) {
	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
			}
		}
	}
	
	return min;
}

int* tinhTongTungCot(int n, int **a) {
	int *sumCol = (int*)calloc(n, sizeof(int));
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			sumCol[j] += a[i][j];
		}
	}
	return sumCol;
}

void xuatDay(int n, int *a) {
	for (int i = 0; i < n; i++) {
		if (i != n-1) printf("%d, ", a[i]);
		else printf("%d.\n", a[i]);
	}
}

int* timDayMax(int n, int *a, int *max, int *cnt) {
	*max = INT_MIN;
	int *idx = (int*)malloc(n * sizeof(int));
	*cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > *max) {
			*max = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == *max) {
			idx[*cnt] = i;
			*cnt += 1;
		}
	}
	return idx; 
}

int* timMaxTungHang(int n, int **a) {
	int *maxHang = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		int max = INT_MIN;
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
			maxHang[i] = max;
		}
	}
	return maxHang;
}

int* timMaxTungCot(int n, int **a) {
	int *maxCot = (int*)malloc(n * sizeof(int));
	for (int j = 0; j < n; j++) {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
			maxCot[j] = max;
		}
	}
	return maxCot;
}

int kiemTraMTTamGiacDuoi(int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int kiemTraMTTamGiacTren(int n, int **a) {
	for (int j = 0; j < n; j++) {
		for (int i = j + 1; i < n; i++) {
			if (a[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int kiemTraMTDoiXung(int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

int tinhTichPhanTuAmThuocDCP(int n, int **a, int *check) {
	*check = 1;
	int pow = 0;
	int i = 0, j = n - 1;
	while (j < 0) {
		if (a[i][j] < 0) {
			pow *= a[i][j];
			*check = 0;
		}
		i += 1; j -= 1;
	}
	return pow;
}

int* tinhTongTungHang(int n, int **a) {
	int *sumRow = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sumRow[i] += a[i][j];
		}
	}
	return sumRow;
}

float tinhTBCDuongCotLe(int n, int **a, int *check) {
	*check = 1;
	float sum = 0;
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (j % 2 != 0) {
				sum += a[i][j];
				cnt += 1;
				*check = 0;
			}
		}
	}
	return sum / cnt;
}

int tinhTongPhanTuDuoiDCC(int n, int **a) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
		for (int i = j + 1; i < n; i++) {
			sum += a[i][j];
		}
	}
	return sum;
}

int main() {
	FILE *f;
	int n;
	int **a = NULL;
	
	docFile(&n, &a, f);
	
	if (a == NULL) {
		printf("Khong doc duoc ma tran\n");
		return 1;
	}
	
	// In ra man hinh duoi dang bang
	printf("Ma tran nhap duoc tu file la:\n");
	xuatMT(n, a);
	
	// Tim min cua ma tran
	printf("\nPhan tu co gia tri nho nhat cua ma tran la: %d\n", timMinCuaMT(n, a));
	
	// Tinh tong tung cot, cho biet cac cot co tong lon nhat
	int *sumCols = tinhTongTungCot(n, a);
	printf("\nTong tung cot lan luot bang: ");
	xuatDay(n, sumCols);
	int maxCol, cntCol;
	int *idxCols = timDayMax(n, sumCols, &maxCol, &cntCol);
	printf("Cac cot co tong lon nhat (max = %d) la: ", maxCol);
	xuatDay(cntCol, idxCols);
	
	// Tim max tung hang
	int *maxEachRows = timMaxTungHang(n, a);
	printf("Phan tu co gia tri lon nhat cua tung hang lan luot la: ");
	xuatDay(n, maxEachRows);
	
	// Kiem tra xem ma tran co phai ma tran tam giac duoi hay khong
	if (kiemTraMTTamGiacDuoi(n, a)) printf("\nMa tran la ma tran tam giac duoi!\n");
	else printf("\nMa tran khong phai la ma tran tam giac duoi!\n");
	
	// Tinh tich cac phan tu am thuoc duong cheo phu
	int check;
	int powNega = tinhTichPhanTuAmThuocDCP(n, a, &check);
	if (check) printf("\nKhong ton tai phan tu am tren duong cheo phu!\n");
	else printf("\nTong cac phan tu am tren duong cheo phu bang %.2f\n", powNega);
	
	// Tinh tong tung hang, cho biet cac hang co tong lon nhat
	int *sumRows = tinhTongTungHang(n, a);
	printf("\nTong tung hang lan luot bang: ");
	xuatDay(n, sumRows);
	int maxRow, cntRow;
	int *idxRows = timDayMax(n, sumRows, &maxRow, &cntRow);
	printf("Cac hang co tong lon nhat (max = %d) la: ", maxRow);
	xuatDay(cntRow, idxRows);
	
	// Tinh trung binh cong cac phan tu duong thuoc cot le trong day
	float avgAct = tinhTBCDuongCotLe(n, a, &check);
	if (check) printf("\nKhong ton tai phan tu duong tren cac cot le!\n");
	else printf("\nTBC cac phan tu duong tren cac cot le bang %.2f\n", avgAct);
	
	// Kiem tra ma tran co phai tam giac tren
	if (kiemTraMTTamGiacTren(n, a)) printf("\nMa tran la ma tran tam giac tren!\n");
	else printf("\nMa tran khong phai la ma tran tam giac tren!\n");
	
	// Kiem tra xem ma tran co phai ma tran doi xung hay khong
	if (kiemTraMTDoiXung(n, a)) printf("\nMa tran la ma tran doi xung!\n");
	else printf("\nMa tran khong phai la ma tran doi xung!\n");
	
	// Tim max cac phan tu nam phia duoi DCC
	printf("\nTong cac phan tu nam duoi duong cheo chinh bang %d\n", tinhTongPhanTuDuoiDCC(n, a));
	
	// Tim max cua tung cot
	int *maxEachCols = timMaxTungCot(n, a);
	printf("\nPhan tu co gia tri lon nhat cua tung cot lan luot la: ");
	xuatDay(n, maxEachCols);
}