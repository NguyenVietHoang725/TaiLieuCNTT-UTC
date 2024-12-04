#include <iostream>
#include <algorithm>
using namespace std;

class PS {
    private:
        int tuSo;
        int mauSo;
    public:
        PS() : tuSo(0), mauSo(1) {}
        PS(int t, int m) : tuSo(t), mauSo(m) {
            if (m == 0) {
                cout << "Mau so phai khac 0. Dat mac dinh bang 1" << endl;
                mauSo = 1;
            }
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

        void nhap() {
            cout << "Nhap tu so: ";
            cin >> tuSo;
            cout << "Nhap mau so: ";
            cin >> mauSo;
            if (mauSo == 0) {
                cout << "Mau so phai khac 0. Dat mac dinh bang 1" << endl;
                mauSo = 1;
            }
        }

        void xuat() {
            rutGon();
            cout << tuSo << "/" << mauSo << endl;
        }

        PS operator+(const PS& ps) {
            PS sum;
            sum.tuSo = tuSo * ps.mauSo + mauSo * ps.tuSo;
            sum.mauSo = mauSo * ps.mauSo;

            sum.rutGon();
            return sum;
        }
};

int main() {
    PS a(2, 4);
    cout << "Phan so a la: "; 
    a.xuat();

    PS b;
    b.nhap();
    cout << "Phan so b la: ";
    b.xuat();

    cout << "Tong cua hai phan so a va b bang: ";
    PS sum = a + b;
    sum.xuat();
}