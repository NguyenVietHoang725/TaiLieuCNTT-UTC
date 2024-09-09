#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'

class Diem {
	
private:
	float x;
	float y;
	
public:
	// Default Constructor
	Diem() : x(0), y(0) {}
	// Parameterized Constructor
	Diem(float xVal, float yVal) : x(xVal), y(yVal) {}
	
	// Methods
	void nhap();
	void xuat() const;
	float tinhKC(const Diem &a, const Diem &b);
	
	// Friend Functions
	friend float tinhDienTich(const Diem &a, const Diem &b, const Diem &c);
	friend bool kiemTraTamGiac(const Diem &a, const Diem &b, const Diem &c);
};

void Diem::nhap() {
	cout << "Nhap lan luot hoanh do va tung do: ";
	cin >> x >> y;
} 

void Diem::xuat() const {
	cout << "Toa do cua diem vua nhap la: ";
	cout << "(" << x << ", " << y << ")" << endl;
}

float Diem::tinhKC(const Diem &a, const Diem &b) {
	float kc = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	return kc;
}

float tinhDienTich(const Diem &a, const Diem &b, const Diem &c) {
	return 0.5 * fabs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool kiemTraTamGiac(const Diem &a, const Diem &b, const Diem &c) {
	float dienTich = tinhDienTich(a, b, c);
	return dienTich > 0; 
}

int main() {
	// Yeu cau 1
	Diem a, b, c;
	a.nhap();
	a.xuat();
	b.nhap();
	b.xuat();
	c.nhap();
	c.xuat();

	if (kiemTraTamGiac(a, b, c)) {
		float dienTich = tinhDienTich(a, b, c);
		cout << "Dien tich tam giac duoc tao boi 3 diem la: " << dienTich << endl;
	} else {
		cout << "Ba diem nay khong tao thanh tam giac!" << endl;
	}
	
	// Yeu cau 2
	int n;
	cout << "\nNhap so luong diem: ";
	cin >> n;
	vector<Diem> d(n);
	d[0].nhap();
	d[0].xuat();
	float sum = 0;
	for (int i = 1; i < n; i++) {
		d[i].nhap();
		d[i].xuat();
		sum += d[i].tinhKC(d[i-1], d[i]);
	}
	cout << "Tong khoang cach giua cac diem lien tiep la: " << sum;
	
    return 0;
}
