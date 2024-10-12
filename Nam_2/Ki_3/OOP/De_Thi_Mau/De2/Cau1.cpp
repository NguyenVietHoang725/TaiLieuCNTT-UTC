#include <iostream>
#include <algorithm>
using namespace std;

class PS {
private: 
    int tuSo, mauSo;
public:
    PS () : tuSo(0), mauSo(1) {}
    PS (int t, int m) : tuSo(t), mauSo(m) {}

    void nhap() {
        cout << "Nhap tu so: "; 
        cin >> tuSo;
        cout << "Nhap mau so (khac 0): ";
        cin >> mauSo;
        
        if (mauSo == 0) {
            cout << "Mau so phai khac 0. Dat mac dinh bang 1!" << endl;
            mauSo = 1;
        }
        rutGon();
    }

    void rutGon() {
        int gcd = __gcd(tuSo, mauSo);
        tuSo /= gcd;
        mauSo /= gcd;

        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    } 

    PS operator*(const PS& ps) const {
        PS res;
        res.tuSo = tuSo * ps.tuSo;
        res.mauSo = mauSo * ps.mauSo;
        res.rutGon();
        return res;
    }

    friend ostream& operator<<(ostream& os, const PS& ps) {
        os << ps.tuSo << "/" << ps.mauSo << endl;
        return os;
    }
};

int main() {
    PS a;
    PS b(2, 3);
    a.nhap();
    cout << endl;
    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;
    PS c = a * b;
    cout << "Tich hai phan so a va b: " << c << endl;
    return 0;
}