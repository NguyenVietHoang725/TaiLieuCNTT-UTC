#include <iostream>
#include <cstring>
using namespace std;

class CString {
private:
	char* strName;
public:
	CString(const char* str) {
		int size = strlen(str);
		strName = new char[size + 1];
		strcpy(strName, str);
	}
	
	void Display() {
		cout << strName << endl;
		cout << "Chieu dai cua chuoi = " << strlen(strName) << "\n";
	}
	~CString() { delete[] strName; }
};

int main() {
	CString strFirst("Chao cac ban");
	CString strSecond("Chao tam biet");
	strFirst.Display();
	strSecond.Display();
}

/* Ket qua sau khi thuc hien chuong trinh:

Chao cac ban
Chieu dai cua chuoi = 12
Chao tam biet
Chieu dai cua chuoi = 13

*/