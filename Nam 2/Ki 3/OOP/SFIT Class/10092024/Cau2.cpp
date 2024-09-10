#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MatHang {
protected:  
    string maHang;
    string tenHang;
    string nhaSX;
    int sl;
    float donGia;

public:
    MatHang() : maHang("temp"), tenHang("temp"), nhaSX("temp"), sl(0), donGia(0.0) {}

    void nhapMH() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenHang);
        cout << "Nhap nha san xuat: ";
        getline(cin, nhaSX);
        cout << "Nhap so luong: ";
        cin >> sl;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuatMH() {
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Nha san xuat: " << nhaSX << endl;
        cout << "So luong: " << sl << endl;
        cout << "Don gia: " << donGia << endl;
    }

    string getMaHang() const { return maHang; }
    string getTenHang() const { return tenHang; }
    float getDonGia() const { return donGia; }
};

class MayTinh : public MatHang {
private:
    string loaiCPU;
    string heDieuHanh;
    float trongLuong;

public:
    MayTinh() : MatHang(), loaiCPU("temp"), heDieuHanh("temp"), trongLuong(0.0) {}

    void nhapMT() {
        nhapMH();  
        cout << "Nhap loai CPU: ";
        cin.ignore();
        getline(cin, loaiCPU);
        cout << "Nhap he dieu hanh: ";
        getline(cin, heDieuHanh);
        cout << "Nhap trong luong (kg): ";
        cin >> trongLuong;
    }

    void xuatMT() {
        xuatMH();  
        cout << "Loai CPU: " << loaiCPU << endl;
        cout << "He dieu hanh: " << heDieuHanh << endl;
        cout << "Trong luong: " << trongLuong << " kg" << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;

    vector<MayTinh> danhSachMayTinh(n);

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin may tinh thu " << i + 1 << ":\n";
        danhSachMayTinh[i].nhapMT();
    }

    string tuKhoa;
    cout << "\nNhap ma hang hoac ten hang de tim kiem: ";
    cin.ignore();
    getline(cin, tuKhoa);

    bool timThay = false;
    for (int i = 0; i < n; ++i) {
        if (danhSachMayTinh[i].getMaHang() == tuKhoa || danhSachMayTinh[i].getTenHang() == tuKhoa) {
            cout << "\nThong tin may tinh duoc tim thay:\n";
            danhSachMayTinh[i].xuatMT();
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "\nKhong tim thay may tinh nao phu hop!\n";
    }

    float maxDonGia = danhSachMayTinh[0].getDonGia();
    for (int i = 1; i < n; ++i) {
        if (danhSachMayTinh[i].getDonGia() > maxDonGia) {
            maxDonGia = danhSachMayTinh[i].getDonGia();
        }
    }

    cout << "\nDanh sach may tinh co don gia cao nhat:\n";
    for (int i = 0; i < n; ++i) {
        if (danhSachMayTinh[i].getDonGia() == maxDonGia) {
            danhSachMayTinh[i].xuatMT();
        }
    }

    return 0;
}
