#include <iostream>
#include <algorithm>
using namespace std;

class Dathuc {
private:
    int n;
    float *a;

public:
    Dathuc() : n(0), a(nullptr) {}

    Dathuc(int _n) : n(_n) {
        a = new float[n + 1];
        fill(a, a + n + 1, 0);
    }

    ~Dathuc() {
        delete[] a;
    }

    friend istream& operator>>(istream& is, Dathuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        is >> dt.n;
        dt.a = new float[dt.n + 1];
        cout << "Nhap cac he so (tu bac cao den bac thap):" << endl;
        for (int i = dt.n; i >= 0; --i) {
            cout << "He so cho x^" << i << ": ";
            is >> dt.a[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Dathuc& dt) {
        for (int i = dt.n; i >= 0; --i) {
            if (i < dt.n && dt.a[i] >= 0) os << "+";
            os << dt.a[i] << "x^" << i << " ";
        }
        return os;
    }

    Dathuc& operator=(const Dathuc& dt) {
        if (this != &dt) {
            delete[] a;
            n = dt.n;
            a = new float[n + 1];
            for (int i = 0; i <= n; ++i) {
                a[i] = dt.a[i];
            }
        }
        return *this;
    }

    Dathuc operator+(const Dathuc& dt) const {
        Dathuc result(n);
        for (int i = 0; i <= n; ++i) {
            result.a[i] = a[i] + dt.a[i];
        }
        return result;
    }
};

int main() {
    Dathuc dt1, dt2;
    cin >> dt1;
    cin >> dt2;
    Dathuc dtSum = dt1 + dt2;
    cout << "Tong da thuc: " << dtSum << endl;
    return 0;
}
