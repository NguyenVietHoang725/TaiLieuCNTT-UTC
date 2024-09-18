#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> findFactors(int n) {
    vector<pair<int, int>> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back({i, n / i});
        }
    }
    return factors;
}

void dfs(int n) {
    stack<int> s; // Luu tru cac so can xet
    set<int> visited; // Luu tru cac so da duoc xet

	// Bat dau voi so n
    s.push(n);
    visited.insert(n);
	
    while (!s.empty()) {
        int current = s.top(); // Lay so hien tai tu dinh stack
        s.pop();

        cout << current << " "; // In so do ra
		
		// Tim cac cap so (a, b) cua so hien tai
        vector<pair<int, int>> factors = findFactors(current);
        for (auto factor : factors) {
            int a = factor.first;
            int b = factor.second;
            // Moi cap (a, b) -> m
            int m = (a - 1) * (b + 1);
			
			// Neu m > 0 va m chua duoc xet -> cho vao stack va set
            if (m > 0 && visited.find(m) == visited.end()) {
                s.push(m);
                visited.insert(m);
            }
        }
        sort(factors.begin(), factors.end());
    }
}

int main() {
    int n;
    cin >> n;
    dfs(n);

    return 0;
}