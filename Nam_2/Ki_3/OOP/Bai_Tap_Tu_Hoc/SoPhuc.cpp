#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define endl '\n'

class SoPhuc {
	private:
		double phanThuc;
		double phanAo;
	public:
		SoPhuc(double thuc = 0, double ao = 0) : phanThuc(thuc), phanAo(ao) {}
		
		void nhapSoPhuc() {
			cout << "Nhap phan thuc: ";
			cin >> phanThuc;
			cout << "Nhap phan ao: ";
			cin >> phanAo;
		}
		
		void xuatSoPhuc() {
			cout << "(" << phanThuc << ") + (" << phanAo << "i)" << endl;
		}
		
		SoPhuc tongSoPhuc(const SoPhuc sp) {
			double thuc = phanThuc + sp.phanThuc;
			double ao = phanAo + sp.phanAo;
			SoPhuc res(thuc, ao);
			return res;
		}
		
		SoPhuc hieuSoPhuc(const SoPhuc sp) {
			double thuc = phanThuc - sp.phanThuc;
			double ao = phanAo - sp.phanAo;
			SoPhuc res(thuc, ao);
			return res;
		}
		
		SoPhuc tichSoPhuc(const SoPhuc sp) {
			double thuc = phanThuc * sp.phanThuc - phanAo * sp.phanAo;
			double ao = phanThuc * sp.phanAo + phanAo * sp.phanThuc;
			SoPhuc res(thuc, ao);
			return res;
		}
		
		SoPhuc thuongSoPhuc(const SoPhuc sp) {
			double thuc = (phanThuc * sp.phanThuc + phanAo * sp.phanAo) / (pow(sp.phanThuc, 2) + pow(sp.phanAo, 2));
			double ao = (sp.phanThuc * phanAo - phanThuc * sp.phanAo) / (pow(sp.phanThuc, 2) + pow(sp.phanAo, 2));
			SoPhuc res(thuc, ao);
			return res;
		}
};

int main() {
	SoPhuc a, b;
	
	cout << "Nhap so phuc a:" << endl;
	a.nhapSoPhuc();
	
	cout << "Nhap so phuc b:" << endl;
	b.nhapSoPhuc();
	
	cout << "So phuc a la: "; 
	a.xuatSoPhuc();
	
	cout << "So phuc b la: ";
	b.xuatSoPhuc();

	cout << "Tong hai so phuc a va b bang: ";
	SoPhuc tong = a.tongSoPhuc(b);
	tong.xuatSoPhuc();
	
	cout << "Hieu hai so phuc a va b bang: ";
	SoPhuc hieu = a.hieuSoPhuc(b);
	hieu.xuatSoPhuc();
	
	cout << "Tich hai so phuc a va b bang: ";
	SoPhuc tich = a.tichSoPhuc(b);
	tich.xuatSoPhuc();
	
	cout << "Thuong hai so phuc a va b bang: ";
	SoPhuc thuong = a.thuongSoPhuc(b);
	thuong.xuatSoPhuc();
	
    return(0);
}
