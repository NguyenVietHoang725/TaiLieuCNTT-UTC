#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SV {
	char hoten[30];
	char quequan[15];
	char hocluc;
} SV;

// Hàm nhập thông tin sinh viên
void nhap(int n, SV* sv, FILE *f) {
	for (int i = 0; i < n; i++) {
		fgets(sv[i].hoten, sizeof(sv[i].hoten), f);
		sv[i].hoten[strcspn(sv[i].hoten, "\n")] = '\0';
		fgets(sv[i].quequan, sizeof(sv[i].quequan), f);
		sv[i].quequan[strcspn(sv[i].quequan, "\n")] = '\0';
		fscanf(f, "%c\n", &sv[i].hocluc);
	}   
}

// Hàm đọc thông tin từ file
void docFile(int* n, SV** sv, FILE* f) {
	char tenFile[] = "input.txt"; 
//	char tenFile[30];
//	printf("Nhap ten file: ");
//	gets(tenFile);
	
	// Mở file + chế độ rt - đọc file
	f = fopen(tenFile, "rt");
	if (f == NULL) {
		printf("Khong doc duoc file %s!\n", tenFile);
		return;
	}
	
	// Nhập n - số sinh viên đầu vào
	fscanf(f, "%d\n", n);
	
	// Cấp phát động cho con trỏ mảng cấu trúc SV
	*sv = (SV*)malloc(*n * sizeof(SV));
	
	// Nhập thông tin sử dụng hàm
	nhap(*n, *sv, f);
	
	// Sau khi đọc file xong -> đóng file
	fclose(f);
}

// Hàm xuất thông tin của 1 sinh viên
void xuat(SV sv) {
	printf("|%30s|%15s|%5c|\n", sv.hoten, sv.quequan, sv.hocluc);
}

// Hàm xuất thông tin sinh viên
void xuat(int n, SV* sv) {
	for (int i = 0; i < n; i++) {
		// Sử dụng hàm xuất thông tin của 1 sinh viên và lặp lại trong vòng for
		xuat(sv[i]);
	}
}

// Hàm tìm thông tin sinh viên dựa vào tên được nhập vào từ bàn phím
SV timThongTinSV(int n, SV* sv, int* check) {
	// Nhập tên sinh viên cần tìm
	char tenSV[30];
	printf("\nNhap ten sinh vien can tim thong tin: ");
	gets(tenSV);
	
	// Khởi tạo một biến cấu trúc SV để lưu thông tin sinh viên cần tìm
	SV temp;
	*check = 0; // Biến check để kiểm tra xem có tồn tại sinh viên đó hay không
	
	// Duyệt qua mảng con trỏ để tìm sinh viên
	for (int i = 0; i < n; i++) {
		if (strcmp(tenSV, sv[i].hoten) == 0) {
			temp = sv[i];
			*check = 1; // Nếu tìm được -> thay đổi giá trị biến check
		}
	}
	
	return temp;
}

// Hàm đếm số sinh viên có học lực (A | B | C)
int demSVHocLuc(int n, SV* sv, char hl, int* check) {
	*check = 0; // Biến check kiểm tra xem có tồn tại sinh viên có học lực (A | B | C)
	int dem = 0; // Biến đếm
	
	for (int i = 0; i < n; i++) {
		// Kiểm tra nếu học lực của sinh viên hiện tại có phải là học lực (A | B | C) hay không
		if (sv[i].hocluc == hl) {
			dem += 1;
			*check = 1; // Nếu tìm được -> thay đổi giá trị biến check
		}
	}
	
	return dem;
}

// Hàm xuất thông tin các sinh viên có học lực được nhập vào từ bàn phím
SV* xuatSVTheoHocLuc(int n, SV* sv, int* check, int* cnt) {
	*check = 0; // Biến check kiểm tra xem có tồn tại sinh viên có học lực (A | B | C)
	
	// Nhập học lực cần tìm
	char hl;
	printf("\nNhap hoc luc: ");
	scanf("%c", &hl);
	
	*cnt = 0; // Biến đếm số sinh viên có học lực (A | B | C)
	
	SV* dsSVHL = (SV*)malloc(n * sizeof(SV)); // Cấp phát động cho mảng con trỏ lưu thông tin các sinh viên tìm được
	
	for (int i = 0; i < n; i++) {
		// Kiểm tra nếu học lực của sinh viên hiện tại có phải là học lực (A, B, C) hay không
		if (sv[i].hocluc == hl) {	
			dsSVHL[*cnt] = sv[i]; // Nếu phải thì lưu thông tin sinh viên đó vào mảng con trỏ
			*cnt += 1; // Tăng biến đếm
			*check = 1; // Nếu tìm được -> thay đổi giá trị biến check
		}
	}
	
	return dsSVHL;
}

int main() {
	FILE *f;
	int n;
	SV* sv = NULL;
	
	// 1. Đọc danh sách sinh viên từ tệp
	docFile(&n, &sv, f);
	
	if (sv == NULL) {
		printf("Khong doc duoc danh sach sinh vien!\n");
		return 1;
	}
	
	// 2. Xuất thông tin từng sinh viên ra màn hình
    printf("Danh sach thong tin sinh vien:\n");
    xuat(n, sv);
    
    // 3. Tìm theo họ tên thông tin một sinh viên trong danh sách
    int check;
    SV svCanTim = timThongTinSV(n, sv, &check);
    if (check == 0) 
    	printf("\nKhong ton tai sinh vien nay!\n");
    else {
    	printf("Thong tin sinh vien co ten %s la:\n", svCanTim.hoten);
    	xuat(svCanTim);
	}
    
	// 4. Đếm số sinh viên đạt học lực loại A	
    int demSVHLA = demSVHocLuc(n, sv, 'A', &check);
	if (check == 0)
		printf("\nKhong ton tai sinh vien co hoc luc A!\n");
	else 
		printf("\nCo tat ca %d sinh vien co hoc luc A!\n", demSVHLA);
	
	// 5. Nhập vào một loại học lực từ bàn phím, in ra màn hình thông tin sinh viên đạt học lực vừa nhập
	int cnt;	
	SV* ds = xuatSVTheoHocLuc(n, sv, &check, &cnt);
	if (check == 0)
		printf("\nKhong ton tai sinh vien!\n");
	else {
		printf("Danh sach sinh vien can tim:\n");
		xuat(cnt, ds);
	} 
	
	free(sv); 
    free(ds); 

    return 0;	
}