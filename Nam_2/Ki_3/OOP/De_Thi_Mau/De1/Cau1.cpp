#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
	int bac;
	float *a;
public:
	DaThuc() {
		bac = 0;
		a = nullptr;
	}
	
	DaThuc(int n) {
		bac = n;
		a = new float[n+1];
		fill(a, a+n+1, 0);
	}
	
	void nhap() {
		cout << "Nhap bac cua da thuc: ";
		cin >> bac;
		if (a != nullptr) delete[] a;
		a = new float[bac+1];
		for (int i = 0; i <= bac; i++) {
			cout << "Nhap he so thu " << i+1 << ": ";
			cin >> a[i];
		}
	}
	
	void xuat() {
		for (int i = 0; i <= bac; i++) {
			if (i == 0) {
				cout << a[i];
			} else {
				if (a[i] < 0) {
					cout << a[i] << "x^" << i;
				} else if (a[i] > 0) {
					cout << "+" << a[i] << "x^" << i;
				}
			}
		}
		cout << "\n";
	}
	
	float tinhGiaTri(float x) const {
		float res = a[0];
		for (int i = 1; i <= bac; i++) {
			res += a[i] * pow(x, i);
		}
		return res;
	}
};

int main() {
	DaThuc a;
	cout << "=> Nhap da thuc A:\n";
	a.nhap();
	cout << "=> Da thuc vua nhap la: ";
	a.xuat();
	
	float x;
	cout << "\nNhap so thuc x: ";
	cin >> x;
	cout << "Gia tri cua da thuc A tai x bang " << a.tinhGiaTri(x);
	
	return 0;
}