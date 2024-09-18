#include <iostream>
#include <cstring>
using namespace std;

class CString {
private:
    char* str;
public:
    // Constructor
    CString(const char* s = "") {
        int size = strlen(s);
        str = new char[size + 1];
        strcpy(str, s);
    }

    // Copy constructor
    CString(const CString &ss) {
        str = new char[strlen(ss.str) + 1];
        strcpy(str, ss.str);
    }

    // Destructor
    ~CString() {
        delete[] str; // Use delete[] for arrays
    }

    // Assignment operator
    CString& operator=(const CString& ss) {
        if (this != &ss) {  // Check for self-assignment
            delete[] str;   // Clean up old memory
            str = new char[strlen(ss.str) + 1];
            strcpy(str, ss.str);
        }
        return *this;
    }

    // Method to display the string
    void showstring() const {
        cout << str << endl;
    }
};

int main() {
    // Create CString object with string "Chao cac ban"
    CString s1 = "Chao cac ban";
    cout << "s1 = ";
    s1.showstring();

    // Copy constructor
    CString s2(s1), s3;

    // Assignment operator
    s3 = s1;
    cout << "s2 = ";
    s2.showstring();

    cout << "s3 = ";
    s3.showstring();

    // Another instance using copy constructor
    CString s4 = s1;
    cout << "s4 = ";
    s4.showstring();

    return 0;
}

/* Ket qua sau khi chuong trinh thuc hien

	s1 = Chao cac ban
	s2 = Chao cac ban
	s3 = Chao cac ban
	s4 = Chao cac ban

*/
