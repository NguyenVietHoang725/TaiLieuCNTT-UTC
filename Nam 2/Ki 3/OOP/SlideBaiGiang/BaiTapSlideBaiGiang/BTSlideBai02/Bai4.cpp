#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string id;
    float score;
};

// Ham so sanh de sap xep sinh vien theo diem giam dan
bool compareByScore(const Student &a, const Student &b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;

	// Doc file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Khong the mo file input.txt" << endl;
        return 1;
    }

    Student temp;
    while (getline(inputFile, temp.name) && getline(inputFile, temp.id) && inputFile >> temp.score) {
        inputFile.ignore();  // Bo qua ky tu newline con lai
        students.push_back(temp);
    }
    inputFile.close();

	// Sap xep sinh vien theo diem giam dan
    sort(students.begin(), students.end(), compareByScore);

	// Ghi file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Khong the mo file output.txt" << endl;
        return 1;
    }

    for (const auto &student : students) {
        outputFile << "Ho ten: " << student.name << endl;
        outputFile << "Ma SV: " << student.id << endl;
        outputFile << "Diem: " << student.score << endl;
        outputFile << "-------------------" << endl;
    }
    outputFile.close();

    cout << "Danh sach sinh vien da duoc sap xep va ghi vao output.txt" << endl;

    return 0;
}
