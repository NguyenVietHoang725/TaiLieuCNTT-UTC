#include <iostream>
using namespace std;

class B;
class A {
private:
	float X;
public:
	A() { X = 5.0; }
	friend float Init(A, B);
};

class B {
private:
	float Y;
public:
	B() { Y = 1.0; }
	friend float Init(A, B);
};

float Init(A a, B b) { return a.X + b.Y; }

int main() {
	A a;
	B b;
	cout << Init(a, b) << " la ket qua cua hai lop\n";
}

/* Ket qua sau khi thuc hien chuong trinh:
	
	6 la ket qua cua hai lop
	
*/