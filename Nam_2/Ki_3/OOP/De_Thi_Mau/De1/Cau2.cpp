#include <iostream>
#include <string>
using namespace std;

class MatHang {
private:
    string matHang;
    string tenHang;
    string nhaSX;
    int soLuong;
    int donGia;
public:
    MatHang() {
        matHang = tenHang = nhaSX = "empty";
        soLuong = donGia = 0;
    }

    MatHang(string mh, string th, string nsx, int sl, int dg) {
        matHang = mh;
        tenHang = th;
        nhaSX = nsx;
        soLuong = sl;
        donGia = dg;
    }

    void nhap() {
        cout << "Nhap ma hang: ";
        getline(cin, matHang);
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << "Nhap nha san xuat: ";
        getline(cin, nhaSX);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
        cin.ignore();
    }

    void xuat() {
        cout << "Ma hang: " << matHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Nha san xuat: " << nhaSX << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Don gia: " << donGia << " VND" << endl;
    }

    int getSoLuong() {
        return soLuong;
    }

    int getDonGia() {
        return donGia;
    }
};

class MayTinh : public MatHang {
private:
    string cpu;
    string heDieuHanh;
    int trongLuong;
public:
    void nhap() {
        MatHang::nhap();
        cout << "Nhap CPU: ";
        getline(cin, cpu);
        cout << "Nhap he dieu hanh: ";
        getline(cin, heDieuHanh);
        cout << "Nhap trong luong: ";
        cin >> trongLuong;
        cin.ignore();
    }

    void xuat() {
        MatHang::xuat();
        cout << "CPU: " << cpu << endl;
        cout << "He dieu hanh: " << heDieuHanh << endl;
        cout << "Trong luong: " << trongLuong << " (kg)" << endl;
    }

    string getHeDieuHanh() { 
        return heDieuHanh;
    }
};

int main() {
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    cin.ignore();

    MayTinh* dsMayTinh = new MayTinh[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho may tinh thu " << i + 1 << ":\n";
        dsMayTinh[i].nhap();
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin may tinh thu " << i + 1 << ":\n";
        dsMayTinh[i].xuat();
    }
    
    cout << endl;
    cout << "Danh sach cac loai may tinh dang het hang:\n";
    bool hetHang = false;
    for (int i = 0; i < n; i++) {
        if (dsMayTinh[i].getSoLuong() == 0) {
            dsMayTinh[i].xuat();
            hetHang = true;
        } 
    }

    if (!hetHang) {
        cout << "Khong co may tinh nao dang het hang.\n";
    }

    int maxDonGia = -1;

    for (int i = 0; i < n; i++) {
        if (dsMayTinh[i].getHeDieuHanh() == "Windows") {
            maxDonGia = max(maxDonGia, dsMayTinh[i].getDonGia());
        }
    }

    if (maxDonGia != 1) {
        cout << "\nMay tinh co he dieu hanh Windows co don gia cao nhat la:\n";
        for (int i = 0; i < n; i++) {
            if (dsMayTinh[i].getHeDieuHanh() == "Windows" && dsMayTinh[i].getDonGia() == maxDonGia) {
                dsMayTinh[i].xuat();
            }
        }
    } else {
        cout << "Khong co may tinh co he dieu hanh Windows.\n";
    }

    delete[] dsMayTinh;
    return 0;
}