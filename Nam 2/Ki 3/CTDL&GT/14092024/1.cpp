#include <iostream>
#include <set>
#include <stack>

using namespace std;
#define int long long
#define endl '\n'



signed main() {
	int n;
	stack<int> S;
	set<int> Res;
	cin >> n;
	S.push(n);
	Res.insert(n);
	while(S.size()) {
		int u = S.top();
		S.pop();
		for (int a = 1; a*a <= u; a++) {
			if(u%a==0){
			int v=(a-1)*(u/a+1);
			if(Res.find(v)==Res.end()){
			S.push(v);
				Res.insert(v);
			}
		}
		}
	}
	
	for (auto r:Res) cout << r << " ";
  
    return(0);
}
