#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

void hv(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

// Hoan doi khong can bien trung gian
void hv1(int &a, int &b) {
	a = a^b; // a = 10, b = 7; Tat: a^=b
	b = a^b; // a = 10, b = 3; Tat: b^=a
	a = a^b; // a = 7, b = 3; Tat: a^=b
}
// Su dung phep xor de tranh tran so

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int a=3, b=7;
	cout << "Truoc khi hoan vi: a = " << a << ", b = " << b << "\n";
	hv(a, b);
	cout << "Sau khi hoan vi: a = " << a << ", b = " << b << "\n";

    return(0);
}
