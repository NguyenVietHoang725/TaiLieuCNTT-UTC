#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
	int n;
	float *a;
public:
	DaThuc() {
		n = 0;
		a = nullptr;
	}
	
	DaThuc(int bac) {
		n = bac;
		a = new float[n + 1];
        fill(a, a + n + 1, 0);
	}
	
	friend istream& operator>>(istream& is, DaThuc& p) {
		is >> p.n;
		if (p.a != nullptr) delete[] p.a;
		p.a = new float[p.n + 1];
		fill (p.a, p.a+p.n+1, 0);
		for (int i = 0; i <= p.n; i++) is >> p.a[i];
		return is;
	}
	
	void xuat() {
		cout << "Da thuc: ";
		for (int i = 0; i <= n; i++) {
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
	
	friend float tinhGiaTri(const DaThuc& p, float x);
};

float tinhGiaTri(const DaThuc& p, float x) {
    float res = p.a[0];
    for (int i = 1; i <= p.n; i++) {
        res += p.a[i] * pow(x, i);
    }
    return res;
}

int main() {
	DaThuc a;
	cout << "Nhap da thuc A (lan luot bac den cac he so): ";
	cin >> a;
	cout << "Da thuc vua nhap la: ";
	a.xuat();
	float x; 
	cout << "\nNhap so thuc x: ";
	cin >> x;
	cout << "Gia tri cua da thuc A tai x bang: " << tinhGiaTri(a, x);
	
	
}