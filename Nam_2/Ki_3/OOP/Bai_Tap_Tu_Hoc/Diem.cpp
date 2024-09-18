#include <iostream>
#include <cmath> 

using namespace std;

#define ll long long
#define endl '\n'

class Diem {
	
private:
    float x, y;
    
public:
    void nhap();
    void xuat();
    float tinhKhoangCach(Diem a);
    friend float tinhKhoangCach(Diem a, Diem b);
};

void Diem::nhap() {  
    cout << "Nhap lan luot hoanh do va tung do: ";
    cin >> x >> y;
}

void Diem::xuat() { 
    cout << "(" << x << ", " << y << ")" << endl;
}

float Diem::tinhKhoangCach(Diem a) { 
    float kc = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
    return kc;
}

float tinhKhoangCach(Diem a, Diem b) {
	float kc = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	return kc;
}

int main() {
    Diem a, b;
    a.nhap();
    a.xuat();
    b.nhap();
    b.xuat();
    float res1 = a.tinhKhoangCach(b);
    cout << res1 << endl;  
    
    float res2 = tinhKhoangCach(a, b);
    cout << res2 << endl;
    
    return 0;
}
