#include <iostream>
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Default Constructor
    PhanSo() : tuSo(0), mauSo(1) {}

    // Parameterized Constructor
    PhanSo(int tu, int mau) : tuSo(tu), mauSo(mau) {
        if (mauSo == 0) {
            cout << "Mau so khong duoc la 0. Dat mac dinh la 1." << endl;
            mauSo = 1;
        }
    }

    // Friend function to overload the >> operator for input
    friend istream& operator>>(istream& input, PhanSo& ps) {
        cout << "Nhap tu so: ";
        input >> ps.tuSo;
        cout << "Nhap mau so: ";
        input >> ps.mauSo;

        if (ps.mauSo == 0) {
            cout << "Mau so khong duoc la 0. Dat mac dinh la 1." << endl;
            ps.mauSo = 1;
        }

        return input;
    }

    // Friend function to overload the << operator for input
    friend ostream& operator<<(ostream& output, const PhanSo& ps) {
        output << ps.tuSo << "/" << ps.mauSo;
        return output;
    }

    // Friend function to overload the + operator for input
    friend PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2) {
        int tu = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
        int mau = ps1.mauSo * ps2.mauSo;
        return PhanSo(tu, mau);
    }
    
    // Friend function to overload the - operator for input
    friend PhanSo operator-(const PhanSo& ps1, const PhanSo& ps2) {
        int tu = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
        int mau = ps1.mauSo * ps2.mauSo;
        return PhanSo(tu, mau);
    }
    

    // Function to simplify the fraction
    void rutGon() {
        int ucln = gcd(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
    }

private:
    // Function to find the greatest common divisor (GCD) using Euclid's algorithm
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

int main() {
    PhanSo ps1, ps2;
    
    cout << "Nhap phan so thu nhat:" << endl;
    cin >> ps1;

    cout << "Nhap phan so thu hai:" << endl;
    cin >> ps2;

    PhanSo tong = ps1 + ps2;
    tong.rutGon();

    cout << "Tong hai phan so la: " << tong << endl;

    return 0;
}
