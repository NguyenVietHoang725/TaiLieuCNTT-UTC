#include <iostream>
#include <cmath>
using namespace std;

class Diem {
    private:
        float x, y;
    public:
        Diem() {
        	x = 0;
        	y = 0;
		}
        Diem(float _x, float _y) {
        	x = _x;
        	y = _y;
		}

        friend istream& operator>>(istream& is, Diem& d) {
	        cout << "\tNhap hoanh do: ";
	        is >> d.x;
	        cout << "\tNhap tung do: ";
	        is >> d.y;
	        return is;
    	}

	    friend ostream& operator<<(ostream& os, const Diem& d) {
	        os << "( "<< d.x << ", " << d.y << ")";
	        return os;
	    }
	
	    friend float tinhKhoangCach(const Diem& d1, const Diem& d2);
};

float tinhKhoangCach(const Diem& d1, const Diem& d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    Diem* a = new Diem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap diem a[" << i + 1 << "]:\n";
        cin >> a[i];
        cout << "Diem a[" << i + 1 << "] la: ";
        cout << a[i] << endl;
    }

    float max = 0;
    Diem diemXaNhat1, diemXaNhat2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float kc = tinhKhoangCach(a[i], a[j]);
            if (kc > max) {
                max = kc;
                diemXaNhat1 = a[i];
                diemXaNhat2 = a[j];
            }
        }
    }

    cout << "\nHai diem cach xa nhau nhat la: " << diemXaNhat1 << " va " << diemXaNhat2;

    delete[] a;
    return 0;
}