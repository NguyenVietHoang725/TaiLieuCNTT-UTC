#include <iostream>
#include <cstring>
#define SIZE 80
using namespace std;

class CPhrase {
private:
	char str[SIZE];
public:
	CPhrase() {
		strcpy(str, "");
	}
	CPhrase(const char *s) {
		strcpy(str, s);
	}
	void display() { cout << str << endl; }
	CPhrase operator+=(CPhrase aa) {
		if(strlen(str) + strlen(aa.str) < SIZE) {
			strcat(str, aa.str);
			return (*this);
		} else {
			cout << "string is too long";
			return (*this);
		}
	}
};

int main() {
	CPhrase s1;
	CPhrase s2 = "Chao cac ban ";
	s1 += s2;
	s1.display();
	s1 = "Chuc suc khoe ";
	CPhrase s3;
	s3 = s1 += s2;
	s3.display();
	CPhrase s4;
	CPhrase s5 = "Xin moi vao ";
	s4 = s2 += s5 += s5;
	s4.display();
}

/* Ket qua sau khi chuong trinh thuc hien

	Chao cac ban
	Chuc suc khoe Chao cac ban
	Chao cac ban Xin moi vao Xin moi vao
	
*/

/*
	Neu ban chi su dung lenh don gian la s1 += s2 thi trong ham khong can tra ve gia tri.
	Tuy nhien de co duoc lenh phuc tap hon nhu s3 = s1 += s2, s4 = s2 += s5 += s5 phai co kieu tra ve
*/