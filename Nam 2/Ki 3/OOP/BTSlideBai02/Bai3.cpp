#include <iostream>

using namespace std;

// Ham hoan vi
void swap(float &x, float &y) {
	float temp = x;
	x = y;
	y = temp;
}

// Ham sap xep su dung thuat toan noi bot Bubble Sort
void bubbleSort(float a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
			}
		}
	}
}

// Ham in mang
void printArray(float a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Nhap so luong so thuc cua day: ";
	cin >> n;
	
	// Nhap va in ra mang
	cout << "Nhap lan luot " << n << " so thuc:" << endl;
	float* a = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "a[1] = ";
		cin >> a[i];
	}
	cout << "Day so truoc khi sap xep la: ";
	printArray(a, n);
	
	// Sap xep mang va in ra mang sau khi sap xep
	bubbleSort(a, n);
	cout << "Day so sap xep theo thu tu tang dan la: ";
	printArray(a, n);
	
	// Giai phong mang
	delete[] a;
	
	return 0;
}