#include <iostream>

using namespace std;

bool IsPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	cout << "Nhap so nguyen n: ";
	cin >> n;
	
	cout << "\nCac so nguyen to nam trong doan tu 1 den n la: ";
	for (int i = 2; i < n; i++) {
		if (IsPrime(i)) cout << i << " ";
	}
	
	return 0;
}