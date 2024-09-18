#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

int fun(int a=4, int b=6);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cout << fun(3,7) << "\n"; // Output: 21
	cout << fun() << "\n"; // Output: 24 -> Su dung tham so mac dinh
	cout << fun(5) << "\n"; // Output: 30 -> 5 se thay cho a, con b la tham so mac dinh

    return(0);
}

int fun(int a, int b) {
	return a*b;
}
