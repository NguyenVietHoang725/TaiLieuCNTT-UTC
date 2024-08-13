#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SV {
	char hoten[30];
	char quequan[15];
	char hocluc;
} SV;

void nhap(int n, SV* sv, FILE *f) {
	for (int i = 0; i < n; i++) {
		fgets(sv[i].hoten, sizeof(sv[i].hoten), f);
		sv[i].hoten[strcspn(sv[i].hoten, "\n")] = '\0';
		fgets(sv[i].quequan, sizeof(sv[i].quequan), f);
		sv[i].quequan[strcspn(sv[i].quequan, "\n")] = '\0';
		fscanf(f, "%c\n", &sv[i].hocluc);
	}   
}

void docFile(int* n, SV** sv, FILE* f) {
	char tenFile[] = "input.txt"; 
//	char tenFile[30];
//	printf("Nhap ten file: ");
//	gets(tenFile);
	
	f = fopen(tenFile, "rt");
	if (f == NULL) {
		printf("Khong doc duoc file %s!\n", tenFile);
		return;
	}
	
	fscanf(f, "%d\n", n);

	*sv = (SV*)malloc(*n * sizeof(SV));
	
	nhap(*n, *sv, f);

	fclose(f);
}

void xuat(FILE *fo, SV sv) {
	fprintf(fo, "|%20s|%15s|%5c|\n", sv.hoten, sv.quequan, sv.hocluc);
}

void xuat(FILE *fo, int n, SV* sv) {
	for (int i = 0; i < n; i++) {
		xuat(fo, sv[i]);
	}
}

SV timThongTinSV(int n, SV* sv, int* check) {
	char tenSV[30];
	printf("Nhap ten sinh vien can tim thong tin: ");
	gets(tenSV);
	
	SV temp;
	*check = 0;

	for (int i = 0; i < n; i++) {
		if (strcmp(tenSV, sv[i].hoten) == 0) {
			temp = sv[i];
			*check = 1;
		}
	}
	
	return temp;
}

int main() {
	FILE *f, *fo;
	int n;
	SV* sv = NULL;
	
	// 1. Doc danh sach sinh vien tu tep tren
	docFile(&n, &sv, f);
	
	if (sv == NULL) {
		printf("Khong doc duoc danh sach sinh vien!\n");
		return 1;
	}
	
	fo = fopen("output2.txt", "wt");
	
	// 2. Xuat thong tin cua tung sinh vien ra man hinh
    fprintf(fo, "Danh sach thong tin sinh vien:\n");
    xuat(fo, n, sv);
    
    // 3. Tim theo ho ten thong tin cua mot sinh vien trong danh sach
    int check;
    SV svCanTim = timThongTinSV(n, sv, &check);
    if (check == 0)
    	fprintf(fo, "\nKhong ton tai sinh vien nay!\n");
    else {
    	fprintf(fo, "Thong tin sinh vien co ten %s la:\n", svCanTim.hoten);
    	xuat(fo, svCanTim);
	}
	
	free(sv);
	
	if (ferror(fo)) {
		printf("Loi khi ghi vao file!");
		return 1;
	} else printf("Da ghi file thanh cong!");
	
	fclose(fo);
	
	return 0;
}