#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

typedef struct {
    char maNV[10];
    char tenNV[100];
    float luong;
    char phong;
} NV;

// Hàm nhập thông tin nhân viên
void nhap(int n, NV* nv, FILE* f) {
    for (int i = 0; i < n; i++) {
        fgets(nv[i].maNV, sizeof(nv[i].maNV), f);
        nv[i].maNV[strcspn(nv[i].maNV, "\n")] = '\0';
        fgets(nv[i].tenNV, sizeof(nv[i].tenNV), f);
        nv[i].tenNV[strcspn(nv[i].tenNV, "\n")] = '\0';
        fscanf(f, "%f\n", &nv[i].luong);
        fscanf(f, "%c\n", &nv[i].phong);
    }
}

// Hàm đọc thông tin từ file
void docFile(int* n, NV** nv, FILE* fi) {
    char tenFileIn[] = "input.txt";
    // char tenFile[30];
    // printf("Nhap ten file: ");
    // gets(tenFile);

    fi = fopen(tenFileIn, "rt");
    if (fi == NULL) {
        printf("Khong doc duoc file %s!\n", tenFileIn);
        return;
    }

    fscanf(fi, "%d\n", n);

    *nv = (NV*)malloc(*n * sizeof(NV));

    nhap(*n, *nv, fi);

    fclose(fi);
}

// Hàm xuất thông tin nhân viên
void xuat(int n, NV* nv, FILE* f) {
    for (int i = 0; i < n; i++) {
        fprintf(f, "|%10s|%30s|%10.2f$|%5c|\n", nv[i].maNV, nv[i].tenNV, nv[i].luong, nv[i].phong);
    }
}

// Hàm tìm giá trị nhỏ nhất
float timMin(int n, float a[], int* index) {
    float min = FLT_MAX;
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            *index = i;
            min = a[i];
        }
    }

    return min;
}

// Hàm tính lương trung bình của từng phòng
float* tinhLuongTBTheoPhong(int n, NV* nv, float* min, int* index) {
    float* luong;

    luong = (float*)calloc(3, sizeof(float));
    int cntA = 0, cntB = 0, cntC = 0;

    for (int i = 0; i < n; i++) {
        if (nv[i].phong == 'A') {
            cntA += 1;
            luong[0] += nv[i].luong;
        } else if (nv[i].phong == 'B') {
            cntB += 1;
            luong[1] += nv[i].luong;
        } else if (nv[i].phong == 'C') {
            cntC += 1;
            luong[2] += nv[i].luong;
        }
    }

    if (cntA != 0)
        luong[0] /= cntA;
    else
        luong[0] = 0;

    if (cntB != 0)
        luong[1] /= cntB;
    else
        luong[1] = 0;

    if (cntC != 0)
        luong[2] /= cntC;
    else
        luong[2] = 0;

    *min = timMin(3, luong, index);

    return luong;
}
// Hàm hoán vị
void swap(NV* a, NV* b) {
    NV temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp sử dụng thuật toán Bubble Sort
void bubbleSort(int n, NV* a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].luong < a[j + 1].luong) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// Hàm sắp xếp nhân viên theo thứ tự lương giảm dần
NV* dsNVTheoThuTuLuongGiamDan(int n, NV* nv) {
    NV *a = (NV *)malloc(n * sizeof(NV));
    for (int i = 0; i < n; i++) {
        strcpy(a[i].maNV, nv[i].maNV);
        strcpy(a[i].tenNV, nv[i].tenNV);
        a[i].luong = nv[i].luong;
        a[i].phong = nv[i].phong;
    }

    bubbleSort(n, a);

    return a;
}

int main() {
    FILE *fi, *fo;
    int n;
    NV *nv = NULL;

    docFile(&n, &nv, fi);

    if (nv == NULL) {
        printf("Khong doc duoc danh sach nhan vien!\n");
        return 1;
    }
	
	// 3. Kết quả lưu vào tệp output.txt bao gồm cả thông tin về n nhân viên
    fo = fopen("output.txt", "wt");
    if (fo == NULL) {
        printf("Khong the mo file output.txt!");
        free(nv);
        return 1;
    }
	
	fprintf(fo, "Danh sach thong tin sinh vien:\n");
    xuat(n, nv, fo);
	
	// 1. Tính lương trung bình của từng phòng và cho biết phòng nào có lương trung bình thấp nhất
    int index;
    float minLuong;
    float *luong = tinhLuongTBTheoPhong(n, nv, &minLuong, &index);
    fprintf(fo, "\nLuong trung binh theo phong la:\n");
    fprintf(fo, "Phong A : %.2f\n", luong[0]);
    fprintf(fo, "Phong B : %.2f\n", luong[1]);
    fprintf(fo, "Phong C : %.2f\n", luong[2]);
    if (index == 0)
        fprintf(fo, "\nPhong A co luong trung binh thap nhat la: %.2f\n", minLuong);
    else if (index == 1)
        fprintf(fo, "\nPhong B co luong trung binh thap nhat la: %.2f\n", minLuong);
    else if (index == 2)
        fprintf(fo, "\nPhong C co luong trung binh thap nhat la: %.2f\n", minLuong);
	
	// 2. In danh sách nhân viên ra màn hình theo thứ tự giảm dần của lương
    fprintf(fo, "\nDanh sach nhan vien sap xep theo thu tu luong giam dan la:\n");
    NV *a = dsNVTheoThuTuLuongGiamDan(n, nv);
    xuat(n, a, fo);

	// Kết thúc chương trình
	printf("Ghi file thanh cong!\n");
    fclose(fo);
    free(nv);
    free(a);

    return 0;
}

