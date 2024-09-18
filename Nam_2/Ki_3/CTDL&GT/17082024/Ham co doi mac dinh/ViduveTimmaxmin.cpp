#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

int fun(int x, int y, bool ok = true) {
	return x > y == ok?x:y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cout << fun(3, 7, 5) << "\n"; // ok = true -> tim max
	// kieu du lieu bool: khac 0 = true, bang 0 = true
	
	cout << fun(3, 7, 0) << "\n"; // ok = false -> tim min

    return(0);
}
