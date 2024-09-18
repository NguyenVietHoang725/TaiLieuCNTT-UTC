#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

// Khi khong su dung bien bi danh, output a = 7, b = 5
//void bp(int x, int y) {
//	y = x*x;
//}

// Su dung bien bi danh -> Truyen tham chieu
void bp(int x, int &y) {
	y = x*x;
}
// Khi su dung bien bi danh, y co cung dia chi voi b -> khi y thay doi gia tri, b cung thay doi

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int a=7, b=5;
	bp(a, b);
	
	cout << "a = " << a << "\n";
	cout << "b = " << b << "\n";

    return(0);
}
