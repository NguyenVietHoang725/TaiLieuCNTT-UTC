#include <iostream>
#include <cstring>
using namespace std;

class CWords {
private:
	int nNum;
	char strTitle[20];
public:
	CWords() {
		nNum = 0;
		strcpy(strTitle, " ");
	}
	
	void Display(int i) {
		nNum = i;
		cout << "Tham so la: " << nNum << endl;
		cout << "Day khong phai la chuoi" << endl;
	} 
	
	void Display(char c) {
		strTitle[0] = c;
		cout << "Tham so la " << strTitle[0] << endl;
		cout << "Day laf mot ky tu" << endl;
	}
	
	void Display(const char* str) {
		strcpy(strTitle, str);
		cout << "Tham so la " << strTitle << endl;
		cout << "Day la mot chuoi" << endl;
	}
	
	void Display(const char* str, int i) {
		strcpy(strTitle, str);
		nNum = i;
		cout << "Tham so la " << strTitle << " va " << nNum << endl;
		cout << "Day la mot chuoi" << endl;
	}
};

int main() {
	CWords X;
	X.Display(120);
	X.Display('A');
	X.Display("String");
	X.Display("String", 10);
}

/* Ket qua sau khi thuc hien chuong trinh

Tham so la: 120
Day khong phai la chuoi
Tham so la A
Day laf mot ky tu
Tham so la String
Day la mot chuoi
Tham so la String va 10
Day la mot chuoi

*/