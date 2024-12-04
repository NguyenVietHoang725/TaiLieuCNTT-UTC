#include <iostream>
#include <cmath> 
using namespace std;

class Diem {
private:
    float x;
    float y;

public:
    Diem() {
        x = 0.0;
        y = 0.0;
    }

    Diem(float hd, float td) {
        x = hd;
        y = td;
    }

    float khoangCachDenGocToaDo() const {
        return sqrt(x * x + y * y);
    }

    friend istream& operator>>(istream& is, Diem& d) {
        cout << "Nhap hoanh do x: ";
        is >> d.x;
        cout << "Nhap tung do y: ";
        is >> d.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Diem& d) {
        os << "(" << d.x << ", " << d.y << ")";
        return os;
    }
};

int main() {
    int n;
    cout << "Nhap so luong diem: ";
    cin >> n;

    Diem* a = new Diem[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do diem thu " << i + 1 << ":" << endl;
        cin >> a[i];
    }

    float tongkc = 0.0;
    for (int i = 0; i < n; i++) {
        tongkc += a[i].khoangCachDenGocToaDo();
    }
    cout << "Tong khoang cach tu cac diem den goc toa do: " << tongkc << endl;

    float kcMin = a[0].khoangCachDenGocToaDo();
    int vtMin = 0;
    for (int i = 1; i < n; i++) {
        float kc = a[i].khoangCachDenGocToaDo();
        if (kc < kcMin) {
            kcMin = kc;
            vtMin = i;
        }
    }
    cout << "Diem gan goc toa do nhat la: " << a[vtMin] 
         << " voi khoang cach: " << kcMin << endl;

    delete[] a;

    return 0;
}
