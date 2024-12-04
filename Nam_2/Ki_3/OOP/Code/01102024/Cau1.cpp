#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Dathuc {
private:
	int n;
	float *a;
public:
	Dathuc() {
		n = 0;
		a = nullptr;
	}
	
	Dathuc(int _n) {
		n = _n;
		a = new float[n+1];
		fill(a, a+n+1, 0);
	}
	
	friend istream& operator>>(istream& is, Dathuc& p) {
        is >> p.n; 
        if (p.a != nullptr) delete[] p.a; 
        p.a = new float[p.n + 1];
        fill(p.a, p.a + p.n + 1, 0); 
        for (int i = 0; i <= p.n; i++) is >> p.a[i]; 
        return is;
    }
	
	void xuatDaThuc() {
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
	
	friend float tinhGiaTri(const Dathuc& p, float x);
};

float tinhGiaTri(const Dathuc& p, float x) {
    float res = p.a[0];
    for (int i = 1; i <= p.n; i++) {
        res += p.a[i] * pow(x, i);
    }
    return res;
}

int main() {
	Dathuc P;
    cout << "Nhap da thuc P:" << endl;
    cin >> P; 

    P.xuatDaThuc();
	
	cout << "Gia tri cua da thuc P tai x = 3 bang: " << tinhGiaTri(P, 3);	

    return 0;
}