#include <stdio.h>
#include <stdlib.h>

void nhap(int* n, float** a, char ten){
	printf("Nhap so luong phan tu cua day so %c: ", ten);
	scanf("%d", n);
	
	*a = (float*)malloc(*n * sizeof(float));
	for (int i = 0; i < *n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%f", *a+i);
	}
}

void xuat(int n, float* a){
	for (int i = 0; i < n; i++){
		if (i != n - 1)
			printf("%.2f, ", *(a+i));
		else 
			printf("%.2f.\n", *(a+i));
	}
}

void bubbleSort(float* arr, int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int loaiBoTrungLap(float* arr, int n) {
    int duyet, dung;
    for (duyet = 0, dung = 0; duyet < n; duyet++) {
    	// Duyệt từng phần tử trước và sau, kiểm tra xem có bằng nhau không
        if (duyet == 0 || arr[duyet] != arr[duyet - 1]) {
            arr[dung++] = arr[duyet];
        }
    }
    return dung; // Trả về số lượng phần tử duy nhất sau khi loại bỏ
}

void timPhanTuChiAKhongB(int n, int m, float* a, float* b){
	// Sắp xếp lại mảng
	bubbleSort(a, n); 
	bubbleSort(b, m);
	
	// Loại bỏ các phần tử trùng lặp
	loaiBoTrungLap(a, n);
	loaiBoTrungLap(b, m);
	
	// Kiểm tra điều kiện
	for (int i = 0; i < n; i++){
		int found = 0;
		for (int j = 0; j < m; j++){
			if (a[i] == b[j]){
				found = 1;
			}
		}
		if (found == 0){
			printf("%.2f  ", a[i]);
		}
	}
	printf("\n");
}

void timPhanTuCaAVaB(int n, int m, float* a, float* b){
	// Sắp xếp lại mảng
	bubbleSort(a, n); 
	bubbleSort(b, m);
	
	// Loại bỏ các phần tử trùng lặp
	loaiBoTrungLap(a, n);
	loaiBoTrungLap(b, m);
	
	// Kiểm tra điều kiện
	for (int i = 0; i < n; i++){
		int found = 0;
		for (int j = 0; j < m; j++){
			if (a[i] == b[j]){
				found = 1;
			}
		}
		if (found == 1){
			printf("%.2f  ", a[i]);
		}
	}
	printf("\n");
}

int main(){
	int n, m;
	float *a, *b;
	
	nhap(&n, &a, 'a');
	nhap(&m, &b, 'b');
	printf("Day a la: ");
	xuat(n, a);
	printf("\nDay b la: ");
	xuat(m, b);
	
	printf("\nCac phan tu chi xuat hien trong day a ma khong xuat hien trong day b la: ");
	timPhanTuChiAKhongB(n, m, a, b);
	
	printf("\nCac phan tu xuat hien o ca day a va b la: ");
	timPhanTuCaAVaB(n, m, a, b);
	
	free(a);
	free(b);
	
	return 0;
}