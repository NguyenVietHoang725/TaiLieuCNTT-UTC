// Ung dung vector de tinh n! (1 <= n <= 1000)
// Submit bai tren LTOL: https://laptrinhonline.club/problem/tichpxgiaithuasolon
#include <iostream>
#include <vector>
using namespace std;

int main() {
	long n, memo;
	cin >> n;
	vector<long> A(1, 1); // Vector A co mot so 1 <-> [1] 
	for (int i = 2; i <= n; i++) {
		memo = 0;
		for (auto &a:A) {
			memo = memo + a*i;
			a = memo % 10;
			memo /= 10;
		}
		while (memo) {
			A.push_back(memo % 10);
			memo /= 10;
		}
	}
	for (auto it=A.rbegin(); it!=A.rend(); it++) cout << *it;
}