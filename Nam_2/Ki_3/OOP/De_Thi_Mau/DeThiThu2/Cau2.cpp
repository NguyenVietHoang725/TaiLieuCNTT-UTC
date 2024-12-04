#include <iostream>
#include <string>
using namespace std;

class Hang {
protected:
    string maHang;
    string tenHang;
    int soLuong;
    float donGia;

public:
    Hang() {
        maHang = "";
        tenHang = "";
        soLuong = 0;
        donGia = 0.0;
    }

    Hang(string mh, string th, int sl, float dg) {
        maHang = mh;
        tenHang = th;
        soLuong = sl;
        donGia = dg;
    }

    virtual void nhap() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cin.ignore(); 
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    virtual void xuat() const {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Don gia: " << donGia << endl;
    }

    float thanhTien() const {
        return soLuong * donGia;
    }

    string getMaHang() const {
        return maHang;
    }

    string getTenHang() const {
        return tenHang;
    }

    float getDonGia() const {
        return donGia;
    }
};

class MayGiat : public Hang {
private:
    float soCan; 

public:
    MayGiat() : Hang() {
        soCan = 0.0;
    }

    MayGiat(string mh, string th, int sl, float dg, float sc)
        : Hang(mh, th, sl, dg) {
        soCan = sc;
    }

    void nhap() override {
        Hang::nhap();
        cout << "Nhap so can (kg): ";
        cin >> soCan;
    }

    void xuat() const override {
        Hang::xuat();
        cout << "So can: " << soCan << " kg" << endl;
    }

    float getSoCan() const {
        return soCan;
    }
};

int main() {
    int n;
    cout << "Nhap so luong may giat: ";
    cin >> n;
    MayGiat* ds = new MayGiat[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin may giat thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    cin.ignore();
    string tuKhoa;
    cout << "\nNhap ma hang hoac ten hang de tim kiem: ";
    getline(cin, tuKhoa);

    bool timThay = false;
    cout << "\nThong tin may giat tim duoc:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getMaHang() == tuKhoa || ds[i].getTenHang() == tuKhoa) {
            ds[i].xuat();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay may giat co ma hoac ten phu hop.\n";
    }

    float giaThapNhat = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].getSoCan() >= 6) {
            if (ds[i].getDonGia() < giaThapNhat) {
                giaThapNhat = ds[i].getDonGia();
            }
        }
    }

    cout << "\nDanh sach may giat tu 6kg tro len co gia re nhat:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].getSoCan() >= 6 && ds[i].getDonGia() == giaThapNhat) {
            ds[i].xuat();
        }
    }

    delete[] ds;
    return 0;
}
