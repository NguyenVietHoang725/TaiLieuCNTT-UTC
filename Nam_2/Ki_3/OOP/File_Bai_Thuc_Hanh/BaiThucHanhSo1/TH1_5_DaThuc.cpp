#include <iostream>
#include <cmath>

using namespace std;
#define int long long
#define endl '\n'

class DT {
	
private:
	int n;
	float *a;
	
public:
	// Default Constructor
	DT() : n(0), a(nullptr) {}
	// Parameterized Constructor
	DT(int _n) : n(_n) {
		a = new float[n+1];
		fill(a, a+n+1, 0);
	}
	// Copy Construtor
	DT(const DT &P) {
		n = P.n;
		a = new float[n+1];
		for (int i = 0; i <= P.n; i++) 
			a[i] = P.a[i];
	}
	// Destructor
	~DT() {
		if (a != nullptr) delete[] a;
	}
	
	// Methods
	void nhap();
	void xuat() const;
	float giaTri(float t) const;
};

void DT::nhap() {
	cout << "Nhap bac cua da thuc: ";
	cin >> n;
	if (a != nullptr) delete[] a;
	a = new float[n+1];
	cout << "Nhap lan luot cac he so cua da thuc: ";
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
}

void DT::xuat() const {
	cout << "Da thuc: ";
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			cout << a[i];
		} else {
			if (a[i] < 0) 
				cout << a[i] << "x^" << i;
			else if (a[i] > 0)
				cout << "+" << a[i] << "x^" << i;
		}
	}
	cout << endl;
}

float DT::giaTri(float t) const{
	float res = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			res += a[i];
		else 
			res += a[i] * pow(t, i);
	}
	return res;
}

signed main() {
	DT a;
	a.nhap();
	a.xuat();
	
	float t;
	cout << "Nhap so thuc t: ";
	cin >> t;
	cout << "Thay x = " << t << ", gia tri cua da thuc la: " << a.giaTri(t) << endl;
	
    return(0);
}
