/* ___LINKED LIST___
1. Khai niem: Danh sach lien ket la cach to chuc luu tru du lieu roi rac, lien ket (ket noi) voi nhau
thong qua dia chi cac phan tu tao thanh mot danh sach "tuyen tinh, truu tuong, co the them bot o ca 2 dau"

2. Hinh anh
	* Loai 1: Danh sach lien ket don
		
		 head                                       trail
		   │                                          │
		┌────┐    ┌────┐    ┌────┐          ┌────┐    ┌────┐                  
		│data│    │data│    │data│          │data│    │data│
		├────┤    ├────┤    ├────┤     ...  ├────┤    ├────┤
		│ptr-│--> │ptr-│--> │ptr-│-->       │ptr-│--> │ptr-│--> NULL
		└────┘    └────┘    └────┘          └────┘    └────┘ 

	* Loai 2: Danh sach lien ket kep
	
		 head                                       trail
		   │                                          │
		┌─────┐    ┌─────┐    ┌─────┐            ┌─────┐    ┌─────┐                  
		│data │    │data │    │data │            │data │    │data │
		├─────┤    ├─────┤    ├─────┤     ...    ├─────┤    ├─────┤
NULL <--│-    │ <--│-    │ <--│-    │         <--│-    │ <--│-    │ 
        │ ptr-│--> │ ptr-│--> │ ptr-│-->         │ ptr-│--> │ ptr-│--> NULL
		└─────┘    └─────┘    └─────┘            └─────┘    └─────┘ 
	
3. Thao tac
	+ empty: kiem tra rong
	+ size: so phan tu
	+ front: xem va sua phan tu dau
	+ back: xem va sua phan tu cuoi
	+ push_front: them vao dau
	+ push_back: them vao cuoi	
	+ pop_front: bo phan tu dau
	+ pop_back: bo phan tu cuoi
	+ insert: chen phan tu
	+ erase: xoa phan tu
	
4. Duyet
	* Bo lap xuoi iterator (dung de duyet xuoi): begin, end
	* Bo lap nguoc reverse_iterator (dung de duyet nguoc): rbegin, rend
*/

#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> L0; // tao list rong	
	list<int> L(3, 5); // tao list rong	
	
	// Them phan tu vao danh sach lien ket
	for (int i = 1; i <= 10; i++) {
		if (i%2 != 0) {
			L.push_front(i);
		} else {
			L.push_back(i);
		}
	}	
	/* Cach khac tuong tu: 
		for (int i = 1; i <= 10; i++) i%2?L.push_front(i):L.push_back(i);
	*/
	
	cout << "L (iterator): ";
	for (list<int>::iterator it=L.begin(); it!=L.end(); it++) cout << *it << " ";
	//for (auto it=L.begin(); it!=L.end(); it++) cout << *it << " ";
	
	cout << "\nL (reverse_iterator): ";
	for (list<int>::reverse_iterator it=L.rbegin(); it!=L.rend(); it++) cout << *it << " ";
	
	L.pop_front();
	L.pop_back();
	L.front() = 30;
	L.back() = 20;
	
	cout << "\nL : ";
	for (auto x:L) cout << x << " ";
	
	L.sort();
	cout << "\nL (sort): ";
	for (auto x:L) cout << x << " ";
	
	auto it=L.begin(); it++; it++; it++; 
	L.erase(it);
	cout << "\nL (erase): ";
	for (auto x:L) cout << x << " ";
	
	it=L.begin(); it++; it++; it++; 
	L.insert(it, -2);
	cout << "\nL (insert): ";
	for (auto x:L) cout << x << " ";
}