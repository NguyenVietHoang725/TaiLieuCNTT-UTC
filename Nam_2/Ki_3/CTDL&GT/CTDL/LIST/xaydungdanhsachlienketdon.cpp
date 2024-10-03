#include <bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;

template<class T>
class node {
private:
	T elem;
	node *next;
public:
	node() {}
	node(T x, node<T> *N=NULL) {
		elem = x;
		next = N;
	}	
	void setelem(T x) {
		elem = x;
	}
	void setnext(node<T> *N=NULL) {
		next = N;
	}
	T &getelem() {
		return elem;
	}
	node<T> *&getnext() {
		return next;
	}
};
#endif

int main () {
  	node<int> A, B(1), C(2,&B);
  	B.setnext(&A);
  	A.setelem(3);
  	node<int> *D = new node<int>(4,&C);
//	cout << A.getelem() << "\n";
//	cout << B.getelem() << "\n";
//	cout << C.getelem() << "\n";
//	cout << D->getelem() << "\n";
	for(node<int> *it = D; it!=NULL; it=it->getnext())
		cout<<it->getelem()<<"\t";
 
   return 0;
}