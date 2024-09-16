#include <iostream>
#include <cstring>  // Use <cstring> for C-style string functions
#define SIZE 80     // Correct the macro definition

using namespace std;

class CString {
    char str[SIZE];  // Fixed size character array
public:
    // Default constructor
    CString() {
        strcpy(str, "");  // Initialize with an empty string
    }

    // Parameterized constructor
    CString(const char *s) {
        strncpy(str, s, SIZE - 1);  // Copy up to SIZE-1 chars
        str[SIZE - 1] = '\0';       // Ensure null termination
    }

    // Method to get string from user input
    void getstr() {
        cout << "Nhap vao chuoi: ";
        cin.getline(str, SIZE);  // Safely read the string with size limit
    }

    // Method to display the string
    void display() const {
        cout << str << endl;
    }

    // Overload conversion operator to return char* type
    operator char*() {
        return str;
    }

    // Overload assignment operator to handle char* to CString assignment
    CString& operator=(const char* s) {
        strncpy(str, s, SIZE - 1);  // Copy up to SIZE-1 chars
        str[SIZE - 1] = '\0';       // Ensure null termination
        return *this;
    }
};

int main() {
    CString s1;
    char* p;

    s1.getstr();   // Get string input from the user
    s1.display();  // Display the string

    p = s1;  // Use the conversion operator to assign CString to char*
    cout << "Chuoi p = " << p << endl;

    char n[15] = "Chuoi moi";
    s1 = n;  // Assign a new string to CString object using the overloaded assignment operator
    s1.display();  // Display the modified string

    return 0;
}
