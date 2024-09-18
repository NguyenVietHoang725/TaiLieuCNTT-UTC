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
//	char tenFile[] = "input.txt";
	char tenFile[30];
	printf("Nhap ten file: ");
	gets(tenFile);
	
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

void xuatMT(FILE *fo, int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(fo, "| %d ", a[i][j]);
		}
		fprintf(fo, "|\n");
	}
}

float tinhTBCPTDuoiDCP(int n, int **a) {
	float sum = 0;
	int dem = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j > n - 1) {
				sum += a[i][j];
				dem += 1;
			}
		}
	}
	
	return sum / dem;
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


int main() {
	FILE *f, *fo;
	int n;
	int **a = NULL;
	
	docFile(&n, &a, f);
	
	if (a == NULL) {
		printf("Khong doc duoc ma tran\n");
		return 1;
	}
	
	fo = fopen("output1.txt", "wt");
	
	// In ra man hinh duoi dang bang
	fprintf(fo, "Ma tran nhap duoc tu file la:\n");
	xuatMT(fo, n, a);
	
	// Tinh TBC cac phan tu nam  phia duoi duong chep ơhu cua ma tran A
	fprintf(fo, "\nTBC cac phan tu nam phia duoi duong cheo phu bang: %.2f\n", tinhTBCPTDuoiDCP(n, a));
	
	// Kiem tra ma tran tam giac tren
	if (kiemTraMTTamGiacTren(n, a)) fprintf(fo, "\nMa tran la ma tran tam giac tren!\n");
	else fprintf(fo, "\nMa tran khong phai la ma tran tam giac tren!\n");
	
	if (ferror(fo)) {
		printf("Loi khi ghi vao file!");
		return 1;
	} else printf("Da ghi file thanh cong!");
	
	fclose(fo);
	
	return 0;
}