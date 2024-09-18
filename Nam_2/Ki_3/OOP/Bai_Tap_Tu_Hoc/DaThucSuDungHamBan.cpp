#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define endl '\n'

struct DaThuc {
    int n;        // Bac cua da thuc
    double* a;    // Cac he so cua da thuc

    // Ham tao mac dinh
    DaThuc() : n(0), a(nullptr) {}

    // Ham tao co tham so
    DaThuc(int _n) : n(_n) {
        a = new double[n + 1];
        fill(a, a + n + 1, 0); // Khoi tao tat ca he so bang 0
    }

    // Ham huy
    ~DaThuc() {
        if (a != nullptr) delete[] a; // Giai phong bo nho neu da duoc cap phat
    }

    // Ham tao sao chep
    DaThuc(const DaThuc &P) {
        n = P.n;
        a = new double[n + 1];
        for (int i = 0; i <= P.n; i++) a[i] = P.a[i]; // Sao chep cac he so
    }

    // Toan tu gan
    DaThuc& operator=(const DaThuc& P) {
        if (this != &P) { // Kiem tra tu gan chinh no
            // Xoa mang hien co
            delete[] a;

            // Sao chep du lieu tu P
            n = P.n;
            a = new double[n + 1];
            for (int i = 0; i <= n; i++) {
                a[i] = P.a[i];
            }
        }
        return *this;
    }

    // Toan tu nhap
    friend istream& operator>>(istream& is, DaThuc& p) {
        is >> p.n; // Nhap bac cua da thuc
        if (p.a != nullptr) delete[] p.a; // Xoa cac he so hien co neu co
        p.a = new double[p.n + 1];
        fill(p.a, p.a + p.n + 1, 0); // Khoi tao tat ca he so bang 0
        for (int i = 0; i <= p.n; i++) is >> p.a[i]; // Nhap cac he so
        return is;
    }

    // Toan tu xuat
    friend ostream& operator<<(ostream& os, const DaThuc& p) {
        for (int i = 0; i <= p.n; i++) os << p.a[i] << " "; // Xuat cac he so
        os << endl;
        return os;
    }

    // Toan tu cong
    friend DaThuc operator+(const DaThuc& P, const DaThuc& Q) {
        int maxDegree = max(P.n, Q.n); // Bac lon nhat giua hai da thuc
        DaThuc result(maxDegree);

        // Cong cac he so cua hai da thuc
        for (int i = 0; i <= maxDegree; i++) {
            if (i <= P.n) result.a[i] += P.a[i];
            if (i <= Q.n) result.a[i] += Q.a[i];
        }

        return result;
    }
};

int main() {
    DaThuc P, Q; // Khai bao cac da thuc
    cout << "Nhap da thuc P:" << endl;
    cin >> P; // Nhap da thuc P
    cout << "Nhap da thuc Q:" << endl;
    cin >> Q; // Nhap da thuc Q

    cout << "Da thuc P: " << P; // Xuat da thuc P
    cout << "Da thuc Q: " << Q; // Xuat da thuc Q

    DaThuc R = P + Q; // Cong hai da thuc P va Q

    cout << "Da thuc R = P + Q: " << R; // Xuat da thuc R

    return 0;
}
