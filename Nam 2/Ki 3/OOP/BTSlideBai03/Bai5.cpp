#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

ull fibonacci(int n, ull* memo) {
    if (memo[n] != 0) {
        return memo[n];
    }

    if (n <= 1) {
        memo[n] = n;
    } else {
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }

    return memo[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 50;
    ull* memo = new ull[n]();  

    for (int i = 0; i < n; i++) {
        cout << "F[" << i << "] = " << fibonacci(i, memo) << endl;
    }

    delete[] memo;  

    return 0;
}
