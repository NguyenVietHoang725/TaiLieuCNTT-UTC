#include <iostream>
#include <vector>
using namespace std;

// Ham tinh UCLN cua hai so nguyen
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// Ham tinh UCLN cua day so nguyen
int gcdArray(const vector<int>& arr) {
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        result = gcd(result, arr[i]);
        if (result == 1) {
            break;
        }
    }
    return result;
}

int main() {
    vector<int> numbers = {48, 36, 60, 72}; 
    int result = gcdArray(numbers);
    cout << "UCLN cua day so la: " << result << endl;
    return 0;
}
