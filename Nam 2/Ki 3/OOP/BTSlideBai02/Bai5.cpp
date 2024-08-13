#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << left << setw(12) << "|Celsius (C)" << setw(15) << "  | Fahrenheit (F) |" << "\n";
    cout << "--------------------------------\n";

    for (int C = 10; C <= 40; C += 2) {
        double F = C * 9.0 / 5.0 + 32;
        cout << "| " << right << setw(12) << C << "| " << setw(15) << fixed << setprecision(1) << F << "|\n";
    }
    
    cout << "--------------------------------\n";

    return 0;
}