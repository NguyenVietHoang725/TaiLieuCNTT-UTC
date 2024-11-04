#include <iostream>


using namespace std;
#define int long long
#define endl '\n'

class A {
	int a;
	public:
		A() {a = 5;}
		void xuat() {cout<<a;}
};

class B: public A {
	int a;
	public:
		B() {a = 1;}
		void xuat() {cout<<a;}
};

signed main() {
	A *ob, x;
	B y;
	ob = &x; ob->xuat();
	ob = &y; ob->xuat();

    return(0);
}
