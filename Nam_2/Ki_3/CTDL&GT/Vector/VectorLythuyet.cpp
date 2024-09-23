/* ___VECTOR___
1. Khai niem: Vecto la 1 cach to chuc va luu tru du lieu. Cac phan tu duoc luu tru "tuyen tinh", "triu tuong",
"bo sung va them bot o cuoi", "co bo lap (loop) xuoi va nguoc".

2. Hinh anh:

		  front                  back
		  |	                      |
		[0][1][2][3][4][5][6][7][8] <- push_back
									-> pop_back
		+-------------------------+
					size				empty
									
	
3. Thao tac
	+ front: xem va sua phan tu dau
	+ back: xem va sua phan tu cuoi
	+ push_back: them phan tu vao cuoi
	+ pop_back: bot phan tu o cuoi
	+ size: so phan tu dang co
	+ empty: kiem tra rong
	+ insert: chen
	+ erase: xoa
	
4. Duyet
	+ Theo chi so: A[3], A[7], ...
	+ Bo lap xuoi: 
		- for (A.begin() -> A.end())
		- for (auto x : A)
	+ Bo lap nguoc: for (A.rbegin() -> A.rend()) 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> A; // Khai bao vecto rong
	vector<int> B(10); // Khai bao vecto co 10 phan tu, cac phan tu chua xac dinh
	vector<int> C(5, 3); // 3 3 3 3 3
	vector<int> D(B.begin(), B.end()); // D = B
	vector<int> E = C;
	int x[] = {4, 7, 2, 8, 4, 8, 3, 2};
	vector<int> F(x+2, x+5);
	
	// Duyet xuoi
	cout << "F (duyet xuoi): ";
	for(vector<int>::iterator it=F.begin(); it!=F.end(); it++) {
		cout << *it << " ";
	}
	// Duyet nguoc
	cout << "\nF (duyet nguoc): ";
	for(vector<int>::reverse_iterator it=F.rbegin(); it!=F.rend(); it++) {
		cout << *it << " ";
	}
	// Duyet theo chi so (index)
	cout << "\nF (duyet chi so): ";
	for (int i = 0; i < F.size(); i++) cout << F[i] << " ";
	// Duyet xuoi su dung iterator
	C.resize(7, 2);
	cout << "\nC (duyet xuoi iterator): "; 
	for (auto c : C) cout << c << " "; 
	
	C.pop_back();
	C.push_back(7);
	C.push_back(9);
	cout << "\nC "; 
	for (auto c : C) cout << c << " "; 
	
	cout << "\nC.size: " << C.size();
	cout << "\nC.cap: " << C.capacity();
	cout << "\nC.front: " << C.front();
	
	F.insert(F.begin() + 2, -5);
	cout << "\nF.insert(): ";
	for (auto f : F) cout << f << " ";
	
	F.erase(F.begin() + 3);
	cout << "\nF.erase(): ";
	for (auto f : F) cout << f << " ";
}