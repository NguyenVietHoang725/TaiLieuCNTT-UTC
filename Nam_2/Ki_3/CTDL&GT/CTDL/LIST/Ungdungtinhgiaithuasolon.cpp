// Ung dung list de tinh n! (1 <= n <= 1000)
// Submit bai tren LTOL: https://laptrinhonline.club/problem/tichpxgiaithuasolon
#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;
//	list<long long> L(1, 1);
	deque<long long> L(1, 1); // Hang doi hai dau
	
	while(n > 1) {
		long long memo = 0;
		for (auto it=L.rbegin(); it!=L.rend(); it++) {
			memo += *it * n;
			*it = memo % 10;
			memo /= 10;
		}
		
		while (memo) {
			L.push_front(memo%10);
			memo /= 10;
		}
		
		n--;
	}
	
	for (auto x:L) cout << x;
}