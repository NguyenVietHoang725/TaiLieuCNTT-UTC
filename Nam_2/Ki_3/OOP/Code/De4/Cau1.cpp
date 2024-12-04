#include <iostream>
#include <cmath>
using namespace std;

class Diem {
    private:
        float x, y;
    public:
        Diem() : x(0.0), y(0.0) {}
        Diem(float x, float y) : x(x), y(y) {}

        void nhap() {
            cout << "Nhap toa do diem (x, y): ";
            cin >> x >> y;
        } 

        void xuat() {
            cout << "Toa do cua diem la: (" << x << ", " << y << ")" << endl;
        }

        float tinhKhoangCach(const Diem& d) {
            return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
        }
};

int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    Diem* a = new Diem[n];
    for (int i = 0; i < n; i++) {
        a[i].nhap();
        a[i].xuat();
    }

    float res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += a[i].tinhKhoangCach(a[i+1]);
    }
    cout << "Do dai duong gap khuc lan luot di qua cac diem 1, 2, ..., n bang: " << res;
}