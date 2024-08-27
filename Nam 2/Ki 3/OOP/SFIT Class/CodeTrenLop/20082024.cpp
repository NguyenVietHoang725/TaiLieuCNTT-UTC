#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'

class Human {
	private:
		// Variables
		string gender;
		int age;
	public:
		// Constructors
		Human();
		Human(string gender);
		Human(int age);
		Human(string gender, int age);
		
		// Methods
		string getGender(); 
		int getAge();        
};

Human::Human() {
	gender = "Unknown";
	age = 0;
}

Human::Human(string gender) {
	this->gender = gender;
}

Human::Human(int age) {
	this->age = age;
}

Human::Human(string gender, int age) {
	this->gender = gender;
	this->age = age;
}

string Human::getGender() {
	return gender;
}

int Human::getAge() {
	return age;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	Human p1("Male", 18);
	Human p2("Female", 20);
	Human p3("Male");
	Human p4;
	Human p5(18);
	
	cout << p1.getGender() << " " << p1.getAge() << endl;
	cout << p2.getGender() << " " << p2.getAge() << endl;
	cout << p3.getGender() << endl;
	cout << p4.getGender() << " " << p4.getAge() << endl;
	cout << p5.getAge() << endl;

    return(0);
}
