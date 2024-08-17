#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int x;
	x = 12;
	
	// X va y co gia tri bang nhau nhung dia chi khac nhau
//	int y = x;
//	cout << "\nBien x co dia chi " << &x << " chua thong tin " << x;
//	cout << "\nBien y co dia chi " << &y << " chua thong tin " << y;

	// x va y co dia chi va gia tri giong nhau
	int &y = x; // y la bi danh cua x chung vung nho
	// Khi khai bao 1 bi danh phai gan mot bien luon, neu khong se bao loi
	// VD: int &y = 3+4 -> ERROR
	int &z = y; // z la bi danh cua y
	cout << "\nBien x co dia chi " << &x << " chua thong tin " << x;
	cout << "\nBien y co dia chi " << &y << " chua thong tin " << y;
	cout << "\nBien z co dia chi " << &z << " chua thong tin " << z;
	
    return(0);
}
