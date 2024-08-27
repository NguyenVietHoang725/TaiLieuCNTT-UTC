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

int main() {
    Diem a, b;
    a.nhap();
    a.xuat();
    b.nhap();
    b.xuat();
    float res = a.tinhKhoangCach(b);
    cout << res << endl;  
    
    return 0;
}
