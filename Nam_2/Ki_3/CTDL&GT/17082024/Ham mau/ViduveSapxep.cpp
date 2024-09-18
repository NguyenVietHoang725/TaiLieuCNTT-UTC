#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define endl '\n'

template <class T>
void sx(int n, T *a, bool ok=1) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j] == ok) {
				swap(a[i], a[j]);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int a[] = {4, 7, 2, 8};
	float b[] = {2.1, 6.8, 2.9, 5.1, 1.5};
	int n = sizeof(a)/sizeof(a[0]);
	int m = sizeof(b)/sizeof(b[0]);
	
	sx(n, a); for (auto x:a) cout << x << " "; cout << "\n";
	sx(m, b); for (auto x:b) cout << x << " "; cout << "\n";

    return(0);
}
