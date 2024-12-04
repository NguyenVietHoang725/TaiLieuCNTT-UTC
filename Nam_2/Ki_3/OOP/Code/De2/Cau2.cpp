#include <iostream>
#include <string>
using namespace std;

class MatHang {
private:
    string maHang;
    string tenHang;
    string nhaSX;
    int soLuong;
    int donGia;
public:
    MatHang() {
        maHang = tenHang = nhaSX = "empty";
        soLuong = donGia = 0;
    }

    MatHang(string mh, string th, string nsx, int sl, int dg) {
        maHang = mh;
        tenHang = th;
        nhaSX = nsx;
        soLuong = sl;
        donGia = dg;
    }

    void nhap() {
        cout << "Nhap ma hang: ";
        getline(cin, maHang);
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
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Nha san xuat: " << nhaSX << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Don gia: " << donGia << " VND" << endl;
    }
    
    string getMaHang() {
    	return maHang;
	}
	
	string getTenHang() {
		return tenHang;
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

    string timKiem;
    cout << "Nhap ma hang hoac ten hang cua may tinh ban muon tim: ";
    getline(cin, timKiem);
    
    bool found = false;
	for (int i = 0; i < n; i++) {
	    if (dsMayTinh[i].getMaHang() == timKiem || dsMayTinh[i].getTenHang() == timKiem) {
	        cout << "Thong tin may tinh vua tim la:\n";
	        dsMayTinh[i].xuat();
	        found = true;
	        break;
	    }
	}
	
	if (!found) {
	    cout << "May tinh khong ton tai.\n";
	}
	
	int maxDonGia = -1;
	for (int i = 0; i < n; i++) {
		if (dsMayTinh[i].getDonGia() > maxDonGia) {
			maxDonGia = dsMayTinh[i].getDonGia();
			found = true;
		}
	}
	
	cout << "Danh sach thong tin cac may tinh co don gia cao nhat:\n";
	for (int i = 0; i < n; i++) {
		if (dsMayTinh[i].getDonGia() == maxDonGia) {
			dsMayTinh[i].xuat();
		}
	}
	
    delete[] dsMayTinh;
    return 0;
}