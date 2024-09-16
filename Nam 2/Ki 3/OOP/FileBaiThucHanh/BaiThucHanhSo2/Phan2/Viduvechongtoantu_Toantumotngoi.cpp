// Ham strupr() chuyen chuoi ky tu thanh chuoi ky tu hoa
// Ham strlwr() chuyen chuoi ky tu thanh chuoi ky tu thuong
/* 
	De trinh bien dich phan biet duoc cac toan tu ++, -- dung truoc hay la dung sau
	chung ta su dung cu phap sau:
		operator++() -> xac dinh toan tu dung truoc (prefix operator)
		operator++(int) -> xac dinh toan tu dung sau (postfix operator)
	Tham so int chi la gia (fake) de trinh bien dich phan biet hai hinh thuc tren
*/
#include <iostream>
#include <cstring>
using namespace std;

class Converter {
private:
	char str[80];
public:
	Converter() { strcpy(str, ""); }
	Converter(const char *s) { strcpy(str, s); }
	void display() { cout << str << endl; }
	Converter operator++() {
		return (strupr(str)); 
	}
	Converter operator++(int) {
		Converter ss = str;
		char *ptr = strupr(str);
		strcpy(str, str);
		return ss;
	}
	Converter operator--() {
		return (strlwr(str));
	}
	Converter operator--(int) {
		Converter ss = str;
		char *ptr = strlwr(str);
		strcpy(str, str);
		return ss;
	}
};

int main() {
	Converter s1 = "changed to UPPERCASE";
	Converter s2 = "BACK TO LOWER CASE";
	Converter s3 = "that is all for now";
	Converter s4 = "ENDING ON A LOW NOTE";
	Converter s5;
	int i, j;
	++s1;
	cout << "++s1 = ";
	s1.display();
	--s2;
	cout << "--s2 = ";
	s2.display();
	s5 = s3++;
	cout << "Result of s5 = s3++ "<< endl << "s3 = ";
	s3.display();
	cout << "s5 = ";
	s5.display();
	s4--;
	cout << "s4-- = ";
	s4.display();
}

/* Ket qua sau khi thuc hien chuong trinh

	++s1 = CHANGED TO UPPERCASE
	--s2 = back to lower case
	Result of s5 = s3++
	s3 = THAT IS ALL FOR NOW
	s5 = that is all for now
	s4-- = ending on a low note

*/