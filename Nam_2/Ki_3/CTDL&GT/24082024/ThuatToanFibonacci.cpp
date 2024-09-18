#include <iostream>


using namespace std;

#define ll long long
#define endl '\n'



int main() {

	int n; 							// 1 phep toan
	cin >> n;						// 1 phep toan
	
	ll F[n+5] = {1,1}; 				// 6 phep toan: 1 (ll F); 1 (n+1); 2 (F[0] = 1); 2 (F[1] = 1)
	
	int i = 2; 						// 2 phep toan: int, =
	for (; i <= n; i++) 
		F[i] = F[i-1] + F[i-2]; 	// 9*(n + 1) + 1 phep toan
		
	cout << F[n]; 					// 2 phep toan

    return(0);
}

// Do phuc tap khong gian K(n) = sizeof(n) + sizeof(F) + sizeof(i) = 4 + 8(n+1) + 4 = 8n + 16

// Do phuc tap thoi gian T(n) = 1 + 1 + 6 + 2 + 9(n+1) + 1 + 2 + 1