#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Nhap so luong so thuc cua day: ";
	cin >> n;
	
	cout << "Nhap lan luot " << n << " so thuc:" << endl;
	float* a = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "a[1] = ";
		cin >> a[i];
	}
	
	cout << "Cac so duong trong day la: ";
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			cout << a[i] << " ";
		}
	}
	
	cout << endl << "Cac so am trong day la: ";
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cout << a[i] << " ";
		}
	}
	
	return 0;
}