#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Nguoi {
private:
	string hoTen;
	string maSo;
	float chieuCao;
	int canNang;
	int namSinh;
	string gioiTinh;
public:
	Nguoi() {
		hoTen = "temp";
		maSo = "temp";
		chieuCao = 0.00;
		canNang = 0;
		namSinh = 0;
		gioiTinh = "temp";
	}
	void nhapNguoi() {
		cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ma so: ";
        cin.ignore();
        getline(cin, maSo);
        cout << "Nhap chieu cao: ";
        cin >> chieuCao;
        cout << "Nhap can nang: ";
        cin >> canNang;
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore();
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
	}
	void xuatNguoi() {
		cout << "Ho ten: " << hoTen << endl;
        cout << "Ma so: " << maSo << endl;
        cout << "Chieu cao: " << chieuCao << "cm" << endl;
        cout << "Can nang: " << canNang << "kg" << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
	}
	
	int getChieuCao() const {
        return chieuCao;
    }
    
    int getNamSinh() const {
    	return namSinh;
	}
	
	string getGioiTinh() const {
		return gioiTinh;
	}
};

class SinhVien : public Nguoi {
private:
	int thoiGianHoc;
	int soDiemA;
public:
	SinhVien() : Nguoi() {
        thoiGianHoc = 0;
        soDiemA = 0;
    }

    void nhapSinhVien() {
        nhapNguoi();  
        cout << "Nhap thoi gian hoc: ";
        cin >> thoiGianHoc;
        cout << "Nhap so diem A: ";
        cin >> soDiemA;
    }

    void xuatSinhVien() {
        xuatNguoi();  
        cout << "Thoi gian hoc: " << thoiGianHoc << " mins" << endl;
        cout << "So diem A: " << soDiemA << endl;
    }
    
    int getThoiGianHoc() const {
        return thoiGianHoc;
    }
    
    int getSoDiemA() const {
    	return soDiemA;
	}
};

void sapXepSinhVienTheoThoiGianHoc(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].getThoiGianHoc() > sv[j].getThoiGianHoc()) {
                swap(sv[i], sv[j]);
            }
        }
    }
}

int main() {
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	
	SinhVien *sv = new SinhVien[n];
	for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho sinh vien thu " << i + 1 << ":\n";
        sv[i].nhapSinhVien();
    }

    cout << "\nDanh sach sinh vien tham gia lop hoc:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        sv[i].xuatSinhVien();
    }
    
    // Yeu cau 2
    int minTuoiIndex = -1;
    int minNamSinh = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (sv[i].getChieuCao() > 1.50) {
            if (!found || sv[i].getNamSinh() > minNamSinh) { 
                minTuoiIndex = i;
                minNamSinh = sv[i].getNamSinh();
                found = true;
            }
        }
    }

    if (minTuoiIndex != -1) {
        cout << "\nSinh vien cao hon 150cm va nho tuoi nhat:\n";
        sv[minTuoiIndex].xuatSinhVien();
    } else {
        cout << "\nKhong co sinh vien nao cao hon 150cm.\n";
    }
    
    // Yeu cau 3
    sapXepSinhVienTheoThoiGianHoc(sv, n);
    cout << "\nDanh sach sinh vien sau khi sap xep theo thoi gian hoc tang dan:\n";
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << ":\n";
        sv[i].xuatSinhVien();
    }
    
    // Yeu cau 4
    int maxCnt = 0;
    int maxAIndex = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].getGioiTinh() == "Nu") {
            if (sv[i].getSoDiemA() > maxCnt) {
                maxCnt = sv[i].getSoDiemA();
                maxAIndex = i;
            }
        }
    }
	cout << "\nSinh vien nu co so diem A nhieu nhat co thong tin la:\n";
	sv[maxAIndex].xuatSinhVien();
	
	delete[] sv;
	return 0;
}