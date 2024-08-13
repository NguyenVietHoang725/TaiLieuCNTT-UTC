#include <stdio.h>
#include <stdlib.h>

void insertArray(int n, float *a){
	for (int i = 0; i < n; i++){
		printf("Enter the element at the index %d: ", i);
		scanf("%f", a+i);
	}
}

void printArray(int n, float *a){
	for (int i = 0; i < n; i++){
		if (i != n-1)
			printf("%.2f, ", *(a+i));
		else 
			printf("%.2f.\n", *(a+i));
	}
}

void swap(float *a, float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

void deleteElementEqualToX(int *n, float *a, int x){
	for (int i = 0; i < *n; i++){
		if (*(a+i) == x){
			for (int j = i; j < *n; j++){
				swap(a+j, a+j+1);
			}
			
			(*n)--; // Giảm kích thước của mảng
			
			i--; // Đảm bảo kiểm tra lại phần tử mới sau khi xóa
		}
	}
}

int main(){
	int n;
	printf("Enter the number of the elements in the Array: ");
	scanf("%d", &n);
	
	float *a;
	a = (float*)malloc(n * sizeof(float));
	
	insertArray(n, a);
	printf("\nThe Array is: ");
	printArray(n, a);
	
	int x;
	printf("\nEnter x: ");
	scanf("%d", &x);
	
	deleteElementEqualToX(&n, a, x);
	printf("\nThe Array after deleting elements equal to X is: ");
	printArray(n, a);
	
	free(a);
	
	return 0;
}