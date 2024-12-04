#include <iostream>
#include <cmath>
using namespace std;

class Toado {
private:
    float x;
    float y; 

public:
    Toado() : x(0), y(0) {}

    Toado(float hd, float td) : x(hd), y(td) {}

    void nhap() {
        cout << "Nhap hoanh do x: ";
        cin >> x;
        cout << "Nhap tung do y: ";
        cin >> y;
    }

    void xuat() const {
        cout << "(" << x << ", " << y << ")";
    }

    float khoangCachDenGocToaDo() const {
        return sqrt(x * x + y * y);
    }
};

class DiemMau : public Toado {
private:
    int mau; 

public:
    DiemMau() : Toado(), mau(1) {}

    DiemMau(float hd, float td, int m) : Toado(hd, td), mau(m) {}

    void nhap() {
        Toado::nhap();
        do {
            cout << "Nhap ma mau (1: Do, 2: Vang, 3: Xanh): ";
            cin >> mau;
            if (mau < 1 || mau > 3) {
                cout << "Ma mau khong hop le. Vui long nhap lai.\n";
            }
        } while (mau < 1 || mau > 3);
    }

    void xuat() const {
        Toado::xuat();
        cout << " - Mau: ";
        switch (mau) {
            case 1: cout << "Do"; break;
            case 2: cout << "Vang"; break;
            case 3: cout << "Xanh"; break;
        }
        cout << endl;
    }

    int getMau() const {
        return mau;
    }
};

int main() {
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    DiemMau* a = new DiemMau[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho diem thu " << i + 1 << ":" << endl;
        a[i].nhap();
    }

    int demDo = 0, demVang = 0, demXanh = 0;
    for (int i = 0; i < n; i++) {
        switch (a[i].getMau()) {
            case 1: demDo++; break;
            case 2: demVang++; break;
            case 3: demXanh++; break;
        }
    }
    cout << "So diem Do: " << demDo << endl;
    cout << "So diem Vang: " << demVang << endl;
    cout << "So diem Xanh: " << demXanh << endl;

    float kcMax = a[0].khoangCachDenGocToaDo();
    for (int i = 1; i < n; i++) {
        float kc = a[i].khoangCachDenGocToaDo();
        if (kc > kcMax) {
            kcMax = kc;
        }
    }
    cout << "Cac diem co khoang cach lon nhat den goc toa do (" 
         << kcMax << ") la:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].khoangCachDenGocToaDo() == kcMax) {
            a[i].xuat();
        }
    }

    delete[] a;

    return 0;
}
