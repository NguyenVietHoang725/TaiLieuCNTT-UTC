#include <bits/stdc++.h>
using namespace std;

struct node {
	int elem;
	node *left, *right;
	node (int n) {
		elem = n;
		if (n % 2 == 0 && n > 4) {
			left = new node(n/2-2);
			right = new node(n/2+2);
		} 
		else left=right=NULL;
	}	
};

void preorder(node *T) {
	if(!T) return;
	cout << T->elem << " ";
	preorder(T->left);
	preorder(T->right);
}

void inorder(node *T) {
	if(T == 0) return;
	inorder(T->left);
	cout << T->elem << " ";
	inorder(T->right);
}

void postorder(node *T) {
	if (T == 0) return;
	postorder(T->left);	
	postorder(T->right);
	cout << T->elem << " ";		
}

void draw(node *T, string prompt="\n") {
	if (T == 0) return;
	draw(T->left, prompt+"\t");
	cout << prompt << T->elem;
	draw(T->right, prompt+"\t");
}

int main() {
	node *T = new node(60);
	cout << "\npre : "; preorder(T);
	cout << "\nin : "; inorder(T);
	cout << "\npost : "; postorder(T);
	cout << "\n\nVe : \n\n"; draw(T);
}

