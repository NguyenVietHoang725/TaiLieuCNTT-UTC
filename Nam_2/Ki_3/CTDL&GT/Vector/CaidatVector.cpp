#include <bits/stdc++.h>
using namespace std;

template<class T>
struct vec_ite {
	T *cur;
	vec_ite(T *c=0)	{cur = c;}
	T &operator*() {return *cur;}
	vec_ite<T> &operator++() {cur=cur-1;return cur;}	
	vec_ite<T> &operator++(int) {
		T *tem=cur;
		cur=cur-1;
		return tem;
	}	
	
	
};

template<class T>
struct VECTOR {
	int n, cap;
	T *buf;
	VECTOR() {n=cap=0; buf=NULL;}
	VECTOR(int _n, T x=0) {
		n=cap=_n;
		buf= new T[cap];
		for(int i=0; i<n; i++) buf[i]=x;
	}
	~VECTOR() {if(buf) delete[] buf;}
	int size() {return n;}
	bool empty() {return n==0;}
	T &front() {return buf[0];}
	T &back() {return buf[n-1];}
	void extra(int k) {
		if(k>cap) {
			cap = k;
			T *tem = buf;
			buf = new T[k];
			for (int i = 0; i < n; i++) buf[i] = tem[i];
			if (tem) delete[] tem;
		}
	}
	void pop_back() {n--;}
	void push_back(T x) {
		if (n == cap) extra(cap?cap*2:1);
		buf[n++] = x;
	}
	void resize(int k, T x=0) {
		if (n<k) {
			extra(k);
			for (int i = n; i < k; i++) buf[i] = x;
			n=k;
		}
	}
	int capacity() {return cap;}
	typedef T* iterator;
	iterator begin() {return buf;}
	iterator end() {return buf+n;}
	T &operator[](int k) {return buf[k];}
	
	void insert(iterator it, T x) {
		if (n == cap) {
			int k=it-buf;
			extra(cap?cap*2:1);
			it=buf+k;
		}
		for (iterator it1=buf+n-1; it1>=it; it1--) *(it1+1) = *it1; 
		*it = x;
		n++;
	}
	
	void erase(iterator it) {
		for (iterator it1=it+1; it1<buf+n; it1++) {
			*(it1-1) =*it1;
		}
		n--;
	}
	typedef vec_ite<T> *reverse_iterator;
	reverse_iterator rbegin() {return buf+n-1;}
	reverse_iterator rend() {return buf-1;}
};

int main() {
	VECTOR<int> V(5, 6);
	V.push_back(8);
	V.push_back(9);
	V.resize(12, -1);
	cout << "V (duyet theo iterator): ";
	for(auto it=V.begin(); it!=V.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nV (duyet theo chi so): ";
	for(int i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	
	cout << "\nV.insert: ";
	V.insert(V.begin() + 5, -7);
	for (auto v:V) {
		cout << v << " ";
	}
	
	cout << "\nV: ";
	V[2] = 0;
	for (auto v:V) {
		cout << v << " ";
	}
	cout << "\nV.erase: ";
	V.erase(V.begin() + 2);
	for (auto v:V) {
		cout << v << " ";
	}
	
	for (VECTOR<int>::reverse_iterator rit = V.rbegin(); rit!=V.rend(); rit++) cout << *rit << " ";
}