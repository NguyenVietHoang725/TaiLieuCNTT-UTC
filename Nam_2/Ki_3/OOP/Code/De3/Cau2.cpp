#include <iostream>
using namespace std;

class QLH {
private:
	string maHang;
	string tenHang;
	string xuatXu;
	int loaiHang;
	int soLuong;
public:
	QLH() {
		maHang = tenHang = xuatXu = "Empty";
	}
	
	QLH(string mh, string th, string xx, int lh, int sl) {
		maHang = mh;
		tenHang = th;
		xuatXu = xx;
		loaiHang = lh;
		soLuong = sl;
	}
	
	void nhap() {
		cout << "Nhap ma hang: ";
		getline(cin, maHang);
		cout << "Nhap ten hang: ";
		getline(cin, tenHang);
		cout << "Nhap xuat xu: ";
		getline(cin, xuatXu);
		cout << "Nhap loai hang (1/2/3): ";
		cin >> loaiHang;
		cout << "Nhap so luong: ";
		cin >> soLuong;
	}
	
	void xuat() {
		cout << "Ma hang: " << maHang << "\n";
		cout << "Ten hang: " << tenHang << "\n";
		cout << "Xuat xu: " << xuatXu << "\n";
		cout << "Loai hang: " << loaiHang << "\n";
		cout << "So luong: " << soLuong << "\n";
	}
};

class DIENTU : public QLH {
private:
	int tgbh;
public:
	DIENTU() : QLH() {
		tgbh = 0;
	}
	
	DIENTU(string mh, string th, string xx, int lh, int sl, int tg) 
        : QLH(mh, th, xx, lh, sl) {
        tgbh = tg;
    }
    
    void nhap() {
        QLH::nhap(); 
        cout << "Nhap thoi gian bao hanh (thang): ";
        cin >> tgbh;
    }

    void xuat() {
        QLH::xuat(); 
        cout << "Thoi gian bao hanh: " << tgbh << " thang\n";
    }
};

int main() {
	
}