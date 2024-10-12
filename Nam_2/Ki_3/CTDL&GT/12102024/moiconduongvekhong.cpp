#include <bits/stdc++.h>
using namespace std;

struct node {
	int elem;
	vector<node*> child;
	// Tao de quy ra cay
	node(int n) {
		elem = n;
		for (int a = 1; a*a <= n; a++) {
			if (n%a == 0) child.push_back(new node((a-1)*(n/a+1)));
		}
	}
};

void preorder(node *T) {
	cout << T->elem << " ";
	for (auto c:T->child) preorder(c);
}

void inorder(node *T) {
	if(T->child.size()) {
		inorder(T->child[0]);
	}
	cout << T->elem << " ";
	if(T->child.size() > 1) {
		for (int i = 1; i < T->child.size(); i++)
		inorder(T->child[i]);
	}
}

void postorder(node *T) {
	for (auto c:T->child) postorder(c);
	cout << T->elem << " ";
}

int sum(node *T) {
	int s = T->elem;
	for (auto c:T->child) s+=sum(c);
	return s;
}

int count(node *T, int k = 0) {
	if (T->elem == k) return 1;
	if (T->elem < k) return 0;
	int s = 0;
	for (auto c:T->child) s+=count(c, k);
	return s;
} 

int main() {
	int n;
	cin >> n;
	node *T = new node(n);
	cout << "\nTien thu tu : "; preorder(T);
	cout << "\nTrung thu tu : "; inorder(T);
	cout << "\nHau thu tu : "; postorder(T);
	cout << "\nTong cay : Sum = " << sum(T);
	cout << "\nDem so 0 : " << count(T, 0);
	cout << "\nDem so 10 : " << count(T, 10);
}