#include <bits/stdc++.h>
using namespace std;

class Mon_hoc {
private:
    string maMon;
    string tenMon;
    int soTinChi;
public:
    void nhap() {
        cout << "Nhap ma mon hoc: ";
        getline(cin, maMon);
        cout << "Nhap ten mon hoc: ";
        getline(cin, tenMon);
        cout << "Nhap so tin chi: ";
        cin >> soTinChi;
    }
    void xuat() {
        cout << maMon << " " << tenMon << " " << soTinChi << endl;
    }
};

class DKHP : public Mon_hoc { 
private:
    string maSV;
    string tenSV;
    int soLuongMonHoc;
    Mon_hoc* dsMH;
public:
    void nhapThongTinSinhVien() {
        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, maSV); // Using `cin >> ws` to clear whitespace
        cout << "Nhap ten sinh vien: ";
        getline(cin, tenSV);
    }

    void nhapDanhSachMonHoc() {
        cout << "Nhap so luong mon hoc dang ky: ";
        cin >> soLuongMonHoc;
        
        dsMH = new Mon_hoc[soLuongMonHoc];
        for (int i = 0; i < soLuongMonHoc; ++i) {
            cout << "Nhap thong tin mon hoc thu " << i + 1 << ":" << endl;
            dsMH[i].nhap();
        }
    }

    void xuatThongTinSinhVien() const {
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Ten sinh vien: " << tenSV << endl;
    }

    void xuatDanhSachMonHoc() const {
        cout << "Danh sach mon hoc da dang ky:" << endl;
        for (int i = 0; i < soLuongMonHoc; ++i) {
            dsMH[i].xuat();
        }
    }
};


int main() {

}