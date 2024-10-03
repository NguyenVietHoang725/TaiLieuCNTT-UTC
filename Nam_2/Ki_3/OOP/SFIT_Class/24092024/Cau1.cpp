#include <iostream>
#include <cmath>
using namespace std;

class Diem {
private:
    float x, y;

public:
    Diem() {
        x = 0;
        y = 0;
    }
    
    Diem(float _x, float _y) {
        x = _x;
        y = _y;
    }
    
    float tinhKhoangCach(Diem a) {
        return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
    }
    
    bool operator==(const Diem& a) const {
        return (a.x == x) && (a.y == y);
    }
    
    Diem operator*(const Diem& a) const {
        Diem res;
        res.x = a.x * x;
        res.y = a.y * y;
        return res;    
    }
    
    friend ostream& operator<<(ostream& os, const Diem& a) {
        os << "(" << a.x << ", " << a.y << ")";
        return os;
    }
    
    friend istream& operator>>(istream& is, Diem& a) {
        is >> a.x >> a.y;
        return is;
    }
};

int main() {
    Diem a;
    Diem b(3, 4);
    
    float res = a.tinhKhoangCach(b);
    cout << "Khoang cach hai diem a va b bang: " << res << "\n";
    
    if (a == b) 
        cout << "Diem a trung diem b\n";
    else 
        cout << "Diem a khong trung diem b\n";
    
    cout << "Nhap toa do cho diem a (x y): ";
    cin >> a;

    cout << "Diem a: " << a << endl;
    
    Diem c = a * b;
    cout << "Diem c: " << c;
    return 0;
}
