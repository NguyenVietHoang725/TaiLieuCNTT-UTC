#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define ll long long
#define endl '\n'

void xuat(float a, float b, float c) {
	cout << fixed << setprecision(2);
	cout << "PT bac hai vua nhap: " << a <<"x^2 ";
	if (b >= 0) {
		cout << "+ " << b << "x ";
	} else {
		cout << "- " << -1 * b << "x ";
	}
	if (c >= 0) {
		cout << "+ " << c << endl;
	} else {
		cout << "- " << -1 * c << endl;
	}
}

int giaiPTBacHai(float a, float b, float c) {
	int res;
	float delta = b*b - 4*a*c;
	if (delta < 0)
		res = 0;
	if (delta == 0) 
		res = 1;
	if (delta > 0)
		res = 2;
	return res;
}

int main() {
	float a, b, c;
	cout << "Nhap lan luot he so cua phuong trinh bac 2: ";
	cin >> a >> b >> c;
	xuat(a, b, c);
	
	int res = giaiPTBacHai(a, b, c);
	cout << "So nghiem cua phuong trinh la: " << res;
	
    return(0);
}
