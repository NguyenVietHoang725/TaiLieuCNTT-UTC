#include <bits/stdc++.h>
using namespace std;

class Ds_nguyen {
private:
    int soPT;
    int* arr;

public:
    Ds_nguyen() : soPT(0), arr(nullptr) {}

    Ds_nguyen(int sl) : soPT(sl) {
        arr = new int[soPT];
        fill(arr, arr + soPT, 0);
    }

    friend istream& operator>>(istream& is, Ds_nguyen& ds) {
        cout << "Nhap so phan tu: ";
        is >> ds.soPT;
        delete[] ds.arr; 
        ds.arr = new int[ds.soPT];
        cout << "Nhap lan luot cac so nguyen: ";
        for (int i = 0; i < ds.soPT; i++) {
            is >> ds.arr[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Ds_nguyen& ds) {
        for (int i = 0; i < ds.soPT; i++) {
            os << ds.arr[i] << " ";
        }
        return os;
    }

    int getSoPT() const {
        return soPT;
    }

    int* getArr() const {
        return arr;
    }
};

bool isPerfectSquare(int n) {
    if (n <= 1) return false;
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

int main() {
    Ds_nguyen ds;
    cin >> ds;
    cout << "Day so nguyen vua nhap la: ";
    cout << ds;

    float tbc = 0;
    int cnt = 0;
    for (int i = 0; i < ds.getSoPT(); i++) {
        if (ds.getArr()[i] > 0) {
            cnt++;
            tbc += ds.getArr()[i];
        }
    }

    if (cnt > 0) {
        tbc /= cnt;
        cout << "\nTrung binh cong cac so nguyen duong: " << tbc << endl;
    } else {
        cout << "\nKhong co so nguyen duong trong day so." << endl;
    }

    int perfectSquareCount = 0;
    for (int i = 0; i < ds.getSoPT(); i++) {
        if (isPerfectSquare(ds.getArr()[i])) {
            perfectSquareCount++;
        }
    }
    cout << "So luong phan tu la so chinh phuong: " << perfectSquareCount << endl;
}