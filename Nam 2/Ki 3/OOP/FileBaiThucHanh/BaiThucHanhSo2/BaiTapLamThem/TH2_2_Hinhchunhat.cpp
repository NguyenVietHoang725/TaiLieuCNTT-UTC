#include <iostream>
using namespace std;

class HCN {
private:
	int nHeight;
	int nWidth;
public:
	HCN() {
		nHeight = 0;
		nWidth = 0;
	}
	
	HCN(int h, int w) {
		nHeight = h;
		nWidth = w;
	}
	
	void nhap() {
		cout << "Nhap lan luot chieu dai va chieu rong: ";
		cin >> nHeight >> nWidth;
	}
	
	int area() {
		return nHeight * nWidth;
	}
	
	bool isSquare() {
		return (nHeight == nWidth);
	}
};

int main() {
	int n;
	cout << "=> Nhap so luong hinh chu nhat: ";
	cin >> n;
	
	HCN *hcn = new HCN[n];
	for(int i = 0; i < n; i++) {
		cout << "Hinh chu nhat thu " << i+1 << ":\n";
		hcn[i].nhap();
	}
	
	int maxIndex = 0;
	bool check = false;
	for(int i = 0; i < n; i++) {
		if(hcn[i].area() > hcn[maxIndex].area() && hcn[i].isSquare()) {
			maxIndex = i;
			check = true;
		}
	}
	
	if (check) {
		cout << "=> Dien tich hinh vuong lon nhat bang: " << hcn[maxIndex].area();
	} else {
		cout << "=> Khong ton tai hinh vuong trong day hinh chu nhat!";
	}
	
	return 0;
} 