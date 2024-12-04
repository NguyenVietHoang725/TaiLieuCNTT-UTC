#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int bac;        
    float* heSo;    

public:
    DaThuc() {
        bac = 0;
        heSo = new float[1];
        heSo[0] = 0;
    }

    DaThuc(int b) {
        bac = b;
        heSo = new float[b + 1];
        for (int i = 0; i <= b; i++) {
            heSo[i] = 0;
        }
    }

    ~DaThuc() {
        delete[] heSo;
    }

    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        heSo = new float[bac + 1];
        for (int i = 0; i <= bac; i++) {
            cout << "Nhap he so bac " << i << ": ";
            cin >> heSo[i];
        }
    }

    void xuat() const {
        for (int i = bac; i >= 0; i--) {
            if (heSo[i] != 0) {
                if (i != bac && heSo[i] > 0) {
                    cout << " + ";
                }
                if (i == 0 || heSo[i] != 1) {
                    cout << heSo[i];
                }
                if (i > 0) {
                    cout << "x";
                }
                if (i > 1) {
                    cout << "^" << i;
                }
            }
        }
        cout << endl;
    }

    float tinhGiaTri(float x) const {
        float ketQua = 0;
        for (int i = 0; i <= bac; i++) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }
};

int main() {
    DaThuc dt;
    float x;

    cout << "Nhap da thuc:\n";
    dt.nhap();

    cout << "Nhap gia tri cua x: ";
    cin >> x;

    float ketQua = dt.tinhGiaTri(x);

    cout << "Da thuc vua nhap la: ";
    dt.xuat();
    cout << "Gia tri cua da thuc tai x = " << x << " la: " << ketQua << endl;

    return 0;
}
