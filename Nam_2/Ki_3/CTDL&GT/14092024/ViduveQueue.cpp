#include <iostream>
#include <queue>

using namespace std;
#define int long long
#define endl '\n'

signed main() {
	queue<int> Q;
	for (int x : {7, 4, 2, 8, 3}) {
        Q.push(x);
    }
	
	cout << "\nSize: " << Q.size();
	cout << "\nFront: " << Q.front();
	cout << "\nBack: " << Q.back();
	Q.front() = 10;
	Q.back() *= 6;
	
	cout << "\nCac phan tu: ";
	while (!Q.empty()) {
		cout << Q.front() << " ";
		Q.pop();
	}
 
    return(0);
}
