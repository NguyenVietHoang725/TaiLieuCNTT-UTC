#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

#define ll long long
#define endl '\n'

template <class T>

T bp(T x) {
	return x*x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	// Se tu tim ra kieu du lieu phu hop
	cout << bp(3) << "\n"; // Kieu nguyen
	cout << fixed << setprecision(3) << bp<float>(3) << "\n"; // Kieu thuc -> Boi vi ep kieu dau ra
	cout << fixed << setprecision(3) << bp(3.5) << "\n"; // Kieu thuc
	complex<double> C(3, -2); // Kieu so phuc
	cout << bp(C);

    return(0);
}
