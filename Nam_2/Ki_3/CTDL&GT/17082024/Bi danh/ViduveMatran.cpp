#include <iostream>
#include <iomanip>

using namespace std;

#define ll long long
#define endl '\n'

void nhap(int &n, int &m, int **&a) {
	cin >> n >> m;
	
	a = new int*[n]; // tao mang n con tro a[0]...a[n-1]
	for (int i = 0; i < n; i++) {
		a[i] = new int[m]; 
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}

void xuat(int n, int m, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << a[i][j];
		}
		cout << "\n";
	}
}

void free(int n, int **&a) {
	for (int i = 0; i < n; i++) {
		delete []a[i];
	}
	delete []a;
}

int main() {
	int n, m, **a;
	freopen("matran.txt", "r", stdin);
	nhap(n, m, a);
	xuat(n, m, a);
	free(n, a);

    return(0);
}
