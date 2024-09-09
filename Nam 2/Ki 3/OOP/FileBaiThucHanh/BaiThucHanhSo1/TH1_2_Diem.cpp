#include <iostream>
#include <cmath> 

using namespace std;

#define ll long long
#define endl '\n'

class Diem {
	
private:
    float x, y;
    
public:
	// Ham khoi tao khong tham so (Ham tao mac dinh)
	Diem() {
		x = 0;
		y = 0;
	}
	
	// Ham khoi tao co tham so
	Diem(float xVal, float yVal) {
		x = xVal;
		y = yVal;
	}
	
	// Ham nhap/xuat
    void nhap(); 
    void xuat();
    
    // Ham tinh khoang cach giua hai diem a va goc toa do O
    float tinhKhoangCach();
    
    // Ham tinh khoang cach giua hai diem a, b voi 1 doi so
    float tinhKhoangCach(const Diem &a);
    
    // Ham ban (Friend Function) tinh khoang cac giua hai diem a, b voi 2 doi so
    friend float tinhKhoangCach(const Diem &a, const Diem &b);
    
    // Nap chong toan tu << de in diem
    friend ostream& operator<<(ostream &os, const Diem &d);
};

void Diem::nhap() {  
    cout << "Nhap lan luot hoanh do va tung do: ";
    cin >> x >> y;
}

void Diem::xuat() { 
    cout << "(" << x << ", " << y << ")" << endl;
}

float Diem::tinhKhoangCach() {
	float kc = sqrt(pow(x, 2) + pow(y, 2));
	return kc;
}

float Diem::tinhKhoangCach(const Diem &a) { 
    float kc = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
    return kc;
}

float tinhKhoangCach(const Diem &a, const Diem &b) {
	float kc = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	return kc;
}

ostream& operator<<(ostream &os, const Diem &d) {
    os << "(" << d.x << ", " << d.y << ")";
    return os;
}

int main() {
    Diem a, b;
    a.nhap();
    a.xuat();
    b.nhap();
    b.xuat();
    
    float res0 = a.tinhKhoangCach();
    cout << "Khoang cach giua diem " << a << " va goc toa do O la: ";
    cout << res0 << endl;
    
    float res1 = a.tinhKhoangCach(b);
    cout << "Khoang cach giua hai diem " << a << " va " << b << " la: ";
    cout << res1 << endl;  
    
    float res2 = tinhKhoangCach(a, b);
    cout << "Khoang cach giua hai diem " << a << " va " << b << " la: ";
    cout << res2 << endl;
    
    return 0;
}
