/* ___QUEUE___
1. Khai niem: Hang doi (Queue) la mot cach to chuc luu tru du lieu,
no la mot cau truc du lieu "tuyen tinh, truu tuong, vao dau nay ra dau kia"
theo kieu "FIFO" (First In First Out) vao truoc ra truoc.
	- Giai thich:
		+ Tuyen tinh: cac phan tu co quan he "thang hang"
	 	+ Truu tuong: khi cai dat chua quan tam toi kieu cua du lieu ma no luu tru,
		khi su dung moi phai khai bao
		+ FIFO: Vao truoc ra truoc.

2. Hinh anh:
			
		  back              front
		   │                  │
		─────────────────────────
push -->  [] [] [] [] ... [] []  --> pop	
		─────────────────────────
		  +------------------+
			      size			    empty			
	
3. Thao tac
	+ push: them phan tu vao queue
	+ pop: lay phan tu ra khoi queue
	+ front: xem va sua phan tu dung dau queue
	+ back: xem va sua phan tu dung cuoi hang doi
	+ size: so phan tu hien dang co
	+ empty: kiem tra hang doi co rong khong

*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	
}