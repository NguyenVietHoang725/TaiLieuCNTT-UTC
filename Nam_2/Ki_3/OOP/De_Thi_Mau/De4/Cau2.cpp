#include <iostream>
#include <string>
using namespace std;

class NGUOI {
private:
	string hoTen;
	int tuoi;
public:
	NGUOI() {
		hoTen = "Empty";
		tuoi = 0;
	}
	NGUOI(string ht, int t) {
		hoTen = ht;
		tuoi = t;
	}
	
	void nhap() {
		cin.ignore();
		cout << "Nhap ho va ten: ";
		getline(cin, hoTen);
		cout << "Nhap tuoi: ";
		cin >> tuoi;
	}
	
	void xuat() {
		cout << "Ho ten: " << hoTen << endl;
		cout << "Tuoi: " << tuoi << endl;
	}
};

class QLNV : public NGUOI {
private:
	int snct;
	int luong;
public:
	QLNV() : NGUOI() {
		snct = 0;
		luong = 0;
	}
	QLNV(string ht, int t, int sn, int l) : NGUOI(ht, t) {
		snct = sn;
		luong = l;
	}
	
	void nhap() {
		NGUOI::nhap();
		cout << "Nhap so nam cong tac: ";
		cin >> snct;
		cout << "Nhap luong: ";
		cin >> luong;
	}
	
	void xuat() {
		NGUOI::xuat();
		cout << "So nam cong tac: " << snct << endl;
		cout << "Luong: " << luong << endl;
	}
	
	int getLuong() {
        return luong;
    }

    int getSNCT() {
        return snct;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    QLNV* danhSachNhanVien = new QLNV[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        danhSachNhanVien[i].nhap();
    }

    double tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += danhSachNhanVien[i].getLuong();
    }
    double luongTrungBinh = tongLuong / n;
    cout << "\nLuong trung binh cua cac nhan vien: " << luongTrungBinh << endl;

    int maxSNCT = 0;
    for (int i = 0; i < n; i++) {
        if (danhSachNhanVien[i].getSNCT() > maxSNCT) {
            maxSNCT = danhSachNhanVien[i].getSNCT();
        }
    }

    cout << "\nNhan vien co so nam cong tac nhieu nhat (" << maxSNCT << " nam):" << endl;
    for (int i = 0; i < n; i++) {
        if (danhSachNhanVien[i].getSNCT() == maxSNCT) {
            danhSachNhanVien[i].xuat();
        }
    }

    delete[] danhSachNhanVien;

    return 0;
}