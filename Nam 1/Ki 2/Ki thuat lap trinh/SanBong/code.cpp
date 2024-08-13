#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SB {
	char ten[30];
	int socho;
	int nam;
} SB;

void nhap(int n, SB* a, FILE *f) {
	for (int i = 0; i < n; i++) {
		char temp[100];
		fgets(temp, sizeof(temp), f);
		temp[strcspn(temp, "\n")] = '\0';
		sscanf(temp, "%s %d %d", a[i].ten, &a[i].socho, &a[i].nam);
	}   
}

void docFile(int* n, SB** a, FILE* f) {
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
	
	*a = (SB*)malloc(*n * sizeof(SB));
	
	nhap(*n, *a, f);
	
	fclose(f);
}

void xuat(SB a) {
	printf("|%30s|%5d|%5d|\n", a.ten, a.socho, a.nam);
}


void xuat(int n, SB* a) {
	for (int i = 0; i < n; i++) {
		xuat(a[i]);
	}
}

int main() {
	FILE *f;
	int n;
	SB* a = NULL;
	
	docFile(&n, &a, f);
	
	if (a == NULL) {
		printf("Khong doc duoc danh sach sinh vien!\n");
		return 1;
	}
	
    xuat(n, a);
}