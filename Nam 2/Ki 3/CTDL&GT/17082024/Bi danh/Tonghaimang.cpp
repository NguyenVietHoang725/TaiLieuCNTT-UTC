// Nhap a1...an, b1...bn
// Tinh tong cua tong
#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

void nhap(int &n, int *&a) {
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	a = new int [n];
	cout << "Nhap lan luot " << n << " phan tu cua mang:\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "\n";
}

int tong(int n, int *a) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
	}
	
	return sum;
}

int main() {
	
	int n, m, *x, *y;
	nhap(n, x); // a la bi danh cua x
	nhap(m, y); // b la bi danh cua y
	
	cout << "Tong cua hai mang bang: ";
	cout << tong(n, x) + tong(m, y);
	
	delete []x;
	delete []y;
	
    return(0);
}
