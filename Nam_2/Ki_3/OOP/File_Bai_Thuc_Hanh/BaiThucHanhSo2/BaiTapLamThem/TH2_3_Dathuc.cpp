#include <iostream>
using namespace std;

class DaThuc {
private:
    int bac;
    float* a;

public:
    DaThuc() : bac(0), a(nullptr) {}

    DaThuc(int n) : bac(n) {
        a = new float[bac + 1];
        fill(a, a + bac + 1, 0);
    }

    ~DaThuc() {
        if (a != nullptr) {
            delete[] a;
        }
    }

    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        is >> dt.bac;

        if (dt.a != nullptr) {
            delete[] dt.a;  
        }
        
        dt.a = new float[dt.bac + 1];

        cout << "Nhap cac he so cua da thuc:" << endl;
        for (int i = 0; i <= dt.bac; i++) {
            cout << "He so thu " << i + 1 << ": ";
            is >> dt.a[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        os << "Da thuc: ";
        for (int i = 0; i <= dt.bac; i++) {
            if (i != 0 && dt.a[i] >= 0) {
                os << "+" << dt.a[i] << "*x^" << i;
            } else if (i != 0 && dt.a[i] < 0) {
                os << dt.a[i] << "*x^" << i;
            } else {
                os << dt.a[i];
            }
        }
        return os;
    }

    DaThuc operator+(const DaThuc& dt) {
        int maxBac = max(bac, dt.bac);
        DaThuc result(maxBac);

        for (int i = 0; i <= min(bac, dt.bac); i++) {
            result.a[i] = a[i] + dt.a[i];
        }

        for (int i = min(bac, dt.bac) + 1; i <= maxBac; i++) {
            if (bac > dt.bac) {
                result.a[i] = a[i];
            } else {
                result.a[i] = dt.a[i];  
            }
        }

        return result;
    }

    DaThuc operator-(const DaThuc& dt) {
        int maxBac = max(bac, dt.bac);
        DaThuc result(maxBac);

        for (int i = 0; i <= min(bac, dt.bac); i++) {
            result.a[i] = a[i] - dt.a[i];
        }

        for (int i = min(bac, dt.bac) + 1; i <= maxBac; i++) {
            if (bac > dt.bac) {
                result.a[i] = a[i];  
            } else {
                result.a[i] = -dt.a[i];  
            }
        }

        return result;
    }
};

int main() {
    DaThuc a;
    cin >> a;
    cout << a << endl;

    DaThuc b;
    cin >> b;
    cout << b << endl;

    DaThuc sum = a + b;
    cout << "Tong da thuc: " << sum << endl;

    DaThuc diff = a - b;
    cout << "Hieu da thuc: " << diff;
}
