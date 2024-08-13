#include <stdio.h>
#include <stdlib.h>

// Hàm nhập
void insertArray(int n, float* a){
	for (int i = 0; i < n; i++){
		printf("Enter the element at the index %d: ", i);
		scanf("%f", a+i);
	}
}

// Hàm xuất
void printArray(int n, float* a){
	for (int i = 0; i < n; i++){
		if (i != n-1) 
			printf("%.2f, ", *(a+i));
		else 
			printf("%.2f.\n", *(a+i));
	}
}

// Hàm tìm vị trí phần tử có giá trị x xuất hiện cuối cùng trong mảng
int findIndex(int n, float* a, float x, int* check){
	*check = 0;
	int index;
	for (int i = 0; i < n; i++){
		if (*(a+i) == x){
			index = i;	
			*check = 1;
		}

	}
	
	return index;
}

int main(){
	// Nhập số lượng phần tử của mảng
	int n;
	printf("Enter the number of elements of the Array: ");
	scanf("%d", &n);
	
	// Cấp phát động bộ nhớ cho mảng a
	float* a;
	a = (float*)malloc(n * sizeof(float));
	
	// Nhập và xuất mảng
	insertArray(n, a);
	printf("The Array is: ");
	printArray(n, a);
	
	// Nhập x
	float x;
	printf("Enter x: ");
	scanf("%f", &x);
	
	// Tìm vị trí phần tử có giá trị x xuất hiện cuối cùng trong mảng
	int check;
	int index = findIndex(n, a, x, &check);
	if (check == 0){
		printf("\nThere does not exist an element with a value equal to X in the Array");
	} else {
		printf("The last element equals X at the index %d", index);
	}
		
	// Giải phóng bộ nhớ
	free(a);
	
	return 0;
}