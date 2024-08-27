#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define endl '\n'

class PhanSo {
	private:
		int tuSo;
		int mauSo;
	public:
		PhanSo (int tu = 0, int mau = 1) : tuSo(tu), mauSo(mau) {
			if (mauSo == 0) {
				cout << "Mau so phai khac 0. Dat mau so mac dinh la 1" << endl;
				mauSo = 1;
			}		
		}
		
		void nhapPhanSo() {
			cout << "Nhap tu so: ";
			cin >> tuSo;
			cout << "Nhap mau so: ";
			cin >> mauSo;
			if (mauSo == 0) {
				cout << "Mau so phai khac 0. Dat mau so mac dinh la 1" << endl;
				mauSo = 1;
			}
		}
		
		void xuatPhanSo() {
			cout << tuSo << " / " << mauSo << endl;
		}
		
		void rutGonPhanSo() {
			int gcd = __gcd(tuSo, mauSo);
			tuSo /= gcd;
			mauSo /= gcd;
		}
		
		PhanSo tongPhanSo(const PhanSo ps) {
			int tu = tuSo * ps.mauSo + ps.tuSo * mauSo;
			int mau = mauSo * ps.mauSo;
			PhanSo res(tu, mau);
			res.rutGonPhanSo();
			return res;
		}
		
		PhanSo hieuPhanSo(const PhanSo ps) {
			int tu = tuSo * ps.mauSo - ps.tuSo * mauSo;
			int mau = mauSo * ps.mauSo;
			PhanSo res(tu, mau);
			res.rutGonPhanSo();
			return res;
		}
		
		PhanSo tichPhanSo(const PhanSo ps) {
			int tu = tuSo * ps.tuSo;
			int mau = mauSo * ps.mauSo;
			PhanSo res(tu, mau);
			res.rutGonPhanSo();
			return res;
		}
		
		PhanSo thuongPhanSo(const PhanSo ps) {
			int tu = tuSo * ps.mauSo;
			int mau = mauSo * ps.tuSo;
			PhanSo res(tu, mau);
			res.rutGonPhanSo();
			return res;
		}
};

int main() {
	PhanSo a, b;
	
	cout << "Nhap phan so thu nhat:" << endl;
	a.nhapPhanSo();
	
	cout << "Nhap phan so thu hai:" << endl;
	b.nhapPhanSo();
	
	cout << "Phan so thu nhat la: ";
	a.xuatPhanSo();
	
	cout << "Phan so thu hai la: ";
	b.xuatPhanSo();
	
	PhanSo tong = a.tongPhanSo(b);
	cout << "Tong hai phan so bang: ";
	tong.xuatPhanSo();
	
	PhanSo hieu = a.hieuPhanSo(b);
	cout << "Hieu hai phan so bang: ";
	hieu.xuatPhanSo();
	
	PhanSo tich = a.tichPhanSo(b);
	cout << "Tich hai phan so bang: ";
	tich.xuatPhanSo();
	
	PhanSo thuong = a.thuongPhanSo(b);
	cout << "Thuong hai phan so bang: ";
	thuong.xuatPhanSo();
	
    return(0);
}
