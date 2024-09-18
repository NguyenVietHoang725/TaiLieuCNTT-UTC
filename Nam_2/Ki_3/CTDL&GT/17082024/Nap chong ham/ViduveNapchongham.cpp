#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

int bp(int x) {
	return x*x;
}

double bp(double x) {
	return x+x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cout << bp(7) << "\n";
	cout << bp(7.0) << "\n";

    return(0);
}
