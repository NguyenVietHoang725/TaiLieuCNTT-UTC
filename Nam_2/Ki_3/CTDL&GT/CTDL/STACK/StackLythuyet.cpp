/* ___STACK___
1. Khai niem: Ngan xep la mot cach to chuc du lieu trong KHMT va CNTT
No la "cau truc du lieu tuyen tinh, truu tuong, vao ra cung mot dau
theo kieu LIFO (Last in First out) vao sau ra truoc.

_Giai thich:
	+ Tuyen tinh: quan he don gian, moi phan tu xac dinh toi da
quan he 1 phan tu truoc va 1 phan tu sau.
	+ Truu tuong: khi cai dat chua quan tam toi kieu cac doi tuong
luu tru, khi su dung moi khai bao kieu cua chung.
	+ LIFO: vao sau ra truoc.
	
2. Hinh anh:

		push ╗	 ╔ pop
	 
			│     │             ╗ : vao    
			│     │             ╔ : ra
			│<top>│  ┐
			│ ... │  │
			│ ... │  │ size
			│ ... │  │
			│<   >│  ┘
			└─────┘
			 empty

3. Thao tac:
	+ push: them phan tu vao ngan xep.
	+ pop: lay phan tu ra khoi ngan xep.
	+ top: xem hoac sua phan tu dinh cua ngan xep.
	+ size: xac dinh so phan tu dang co trong ngan xep.
	+ empty: kiem tra ngan xep co rong khong.
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> S;
	if (S.empty()) cout << "Stack rong!";
	
	cout << "\nThem cac phan tu {4, 7, 2, 8} vao stack!";
	for(int x:{4, 7, 2, 8}) S.push(x);
	cout << "\nSo phan tu hien tai la: " << S.size() << "\n";
	for (int i = 0; i < 2; i++) {
		int x; 
		cout << "Them phan tu: ";
		cin >> x;
		S.push(x);
	}
	cout << "\nSo phan tu hien tai la: " << S.size();
	
	cout << "\nDinh cua stack la: " << S.top();
	int x;
	cout << "\nNhap mot so nguyen de sua dinh cua stack: ";
	cin >> x;
	S.top() = x;
	cout << "\nDinh cua stack la: " << S.top();
	cout << "\nSo phan tu hien tai la: " << S.size();
	
	cout << "\nCac phan tu trong stack la: ";
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}