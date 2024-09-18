#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'



int main() {
	// Su dung hieu
//	B1:
//	int a, b;
//	cin >> a >> b;
//	
//	B2:
//	if (a != b) {
//		a > b ? a -= b : b -= a;
//		goto B2;
//	}
//	B3:
//		cout << a;

	// Su dung phep chia lay du
	int a, b;
	cin >> a >> b;
	
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	cout << a;

    return(0);
}
