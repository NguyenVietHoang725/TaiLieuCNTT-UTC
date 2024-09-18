#include <iostream>
using namespace std;

class CRectangle {
private:
	int nHeight; // Chieu dai hinh chu nhat
	int nWidth; // Chieu rong hinh chu nhat
	
public:
	CRectangle(); // Ham tao mac dinh
	int Area(); // Ham tinh dien tich hinh chu nhat
	void Init(int, int);
	~CRectangle(); // Ham huy
};

CRectangle::CRectangle() {
	cout << "Khoi tao cac thuoc tinh bang ham tao mac dinh\n";
	nHeight = 6;
	nWidth = 8;
}

int CRectangle::Area() {
	return nHeight * nWidth;
}

void CRectangle::Init(int Rong, int Dai) {
	cout << "Khoi tao lai hcn voi cac bien duoc dua vao\n";
	nWidth = Rong;
	nHeight = Dai;
}

CRectangle::~CRectangle() {
	cout << "Ham huy dang duoc goi\n";
}

int main() {
	CRectangle Box, Square;
	cout << "Dien tich cua Box la: " << Box.Area() << "\n";
	cout << "Dien tich cua Square la: " << Square.Area() << "\n";
	Box.Init(12, 8);
	Square.Init(8, 8);
	cout << "Dien tich cua Box la: " << Box.Area() << "\n";
	cout << "Dien tich cua Square la: " << Square.Area() << "\n";
}

/* Khi chay chuong trinh cho ket qua sau:

Khoi tao cac thuoc tinh bang ham tao mac dinh
Khoi tao cac thuoc tinh bang ham tao mac dinh
Dien tich cua Box la: 48
Dien tich cua Square la: 48
Khoi tao lai hcn voi cac bien duoc dua vao
Khoi tao lai hcn voi cac bien duoc dua vao
Dien tich cua Box la: 96
Dien tich cua Square la: 64
Ham huy dang duoc goi
Ham huy dang duoc goi

*/
