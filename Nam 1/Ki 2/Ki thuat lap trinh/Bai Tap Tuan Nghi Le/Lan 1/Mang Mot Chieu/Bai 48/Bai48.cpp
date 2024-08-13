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

void sortArrayMode(int n, float *a, int mode){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (mode == 0){
				if (*(a+j) > *(a+j+1)){
					swap(a+j, a+j+1);
				}
			}
			else{
				if (*(a+j) < *(a+j+1)){
					swap(a+j, a+j+1);
				}
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the number of elements of the Array: ");
	scanf("%d", &n);
	
	float *a;
	a = (float*)malloc(n * sizeof(float));
	
	insertArray(n, a);
	printf("\nThe Array is: ");
	printArray(n, a);
	
	// S?p x?p theo th? t? tang d?n
	sortArrayMode(n, a, 0);
	printf("\nSorted Array in ascending order: ");
	printArray(n, a);
	
	// S?p x?p theo th? t? gi?m d?n
	sortArrayMode(n, a, 1);
	printf("\nSorted Array in descending order: ");
	printArray(n, a);
	
	free(a);
	
	return 0;
}