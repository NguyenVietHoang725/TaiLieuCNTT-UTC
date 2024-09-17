#include <iostream>
using namespace std;

class HCN {
private:
	// Variables
	int nHeight;
	int nWidth;
public:
	// Default Constructor
	HCN() {
		nHeight = 0;
		nWidth = 0;
	}
	// Parameterize Constructor
	HCN(int h, int w) {
		nHeight = h;
		nWidth = w;
	}
	
	// Methods
	void nhap() {
		cout << "Nhap lan luot chieu dai va chieu rong: ";
		cin >> nHeight >> nWidth;
	}
	
	int area() {
		return nHeight * nWidth;
	}
};

int main() {
	int n;
	cout << "=> Nhap so luong hinh chu nhat: ";
	cin >> n;
	
	HCN *hcn = new HCN[n];
	for(int i = 0; i < n; i++) {
		cout << "Hinh chu nhat thu " << i + 1 << ":\n";
		hcn[i].nhap();
	}
	
	int maxIndex = 0;
	for(int i = 0; i < n; i++) {
		if(hcn[i].area() > hcn[maxIndex].area()) {
			maxIndex = i;
		}
	}
	
	cout << "=> Hinh chu nhat co dien tich lon nhat bang: " << hcn[maxIndex].area();
	
	delete[] hcn;
	
	return 0;
}