#include <iostream>
using namespace std;

class CTime {
private:
	int nHours, nMinutes, nSeconds;
public:
	CTime(); // Ham tao mac dinh
	CTime(int h, int m, int s); // Ham tao co 3 doi so
	void Display();
	void AddIt(CTime Time1, CTime Time2);
	~CTime(); // Ham huy
};

CTime::CTime() {
	cout << "Ham tao mac dinh\n";
	nHours = nMinutes = nSeconds = 0;
}

CTime::CTime(int h, int m, int s) {
	cout << "Ham tao voi 3 doi so\n";
	nHours = h;
	nMinutes = m;
	nSeconds = s;
}

void CTime::Display() {
	cout << nHours << ':' << nMinutes << ':' << nSeconds << "\n";
}

void CTime::AddIt(CTime Time1, CTime Time2) {
	nHours = Time1.nHours + Time2.nHours;
	nMinutes = Time1.nMinutes + Time2.nMinutes;
	nSeconds = Time1.nSeconds + Time2.nSeconds;
	while(nSeconds >= 60) {
		nSeconds -= 60;
		nMinutes++;
	}
	while(nMinutes >= 60) {
		nMinutes -= 60;
		nHours++;
	}
}
CTime::~CTime() {
	cout << "Ham huy\n";
}

int main() {
	CTime Result;
	CTime T1(1, 49, 50);
	CTime T2(3, 40, 30);
	Result.AddIt(T1, T2);
	cout << "Ket qua la: ";
	Result.Display();
}

/* Ket qua sau khi thuc hien chuong trinh:

Ham tao mac dinh
Ham tao voi 3 doi so
Ham tao voi 3 doi so
Ham huy
Ham huy
Ket qua la: 5:30:20
Ham huy
Ham huy
Ham huy

*/