#include<iostream>
using namespace std;
#ifndef __vector__cpp__
#define __vector__cpp__

// Lop xu ly duyet nguoc cua vector
template <class T>
class vector_reverse_iterator {
    T *curr; // Con tro toi phan tu hien tai
public:
    vector_reverse_iterator(T *c = 0) { curr = c; }

    // Toan tu gan cho reverse iterator
    vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> it) {
        this->curr = it.curr;
        return *this;
    }

    // Toan tu ++ (duyet nguoc prefix)
    vector_reverse_iterator<T> operator++() {
        curr--;
        return *this;
    }

    // Toan tu ++ (duyet nguoc postfix)
    vector_reverse_iterator<T> operator++(int) {
        vector_reverse_iterator<T> tmp = curr;
        curr--;
        return tmp;
    }

    // Toan tu de lay gia tri phan tu
    T &operator*() { return *curr; }

    // Toan tu so sanh khac nhau
    bool operator!=(vector_reverse_iterator<T> t) { return curr != t.curr; }
};

// Lop xu ly vector
template<class T>
class Vector {
private:
    int cap, num; // Suc chua va so luong phan tu hien tai
    T *buff;      // Mang chua cac phan tu

public:
    Vector() { cap = num = 0; buff = 0; }

    // Ham khoi tao vector voi kich thuoc k va gia tri x
    Vector(int k, T x) { 
        cap = num = k; 
        buff = new T[k]; 
        for (int i = 0; i < k; i++) buff[i] = x; 
    }
	
	// Ham huy
    ~Vector() { if (buff) delete[] buff; }

    // Lay suc chua cua vector
    int capacity() { return cap; }

    // Lay so luong phan tu trong vector
    int size() { return num; }

    // Kiem tra vector co trong hay khong
    bool empty() { return num == 0; }

    // Xoa phan tu cuoi cung
    void pop_back() { if (num > 0) num--; }

    // Mo rong suc chua cua vector
    void extend(int newcap) {
        if (newcap < cap) return;
        cap = newcap;
        T *temp = new T[cap];
        for (int i = 0; i < num; i++) temp[i] = buff[i];
        if (buff) delete[] buff;
        buff = temp;
    }

    // Lay phan tu cuoi cung
    T &back() { return buff[num - 1]; }

    // Them phan tu vao cuoi vector
    void push_back(T x) {
        if (num == cap) extend(cap * 2 + 5);
        buff[num++] = x;
    }

    // Toan tu [] de truy cap phan tu
    T &operator[](int k) { return buff[k]; }

    // Chen phan tu vao vi tri k
    void insert(int k, T x) {
        if (cap == num) extend(cap * 2 + 5);
        for (int i = num - 1; i >= k; i--) buff[i + 1] = buff[i];
        buff[k] = x;
        num++;
    }

    // Toan tu gan cho vector
    Vector &operator=(Vector<T> V) {
        this->num = V.num;
        this->cap = V.cap;
        if (cap) {
            this->buff = new T[cap];
            for (int i = 0; i < num; i++) this->buff[i] = V.buff[i];
        } else {
            this->buff = 0;
        }
        return *this;
    }

    // Iterator cho vector
    typedef T *iterator;
    iterator begin() { return buff; }
    iterator end() { return buff + num; }

    // Reverse iterator cho vector
    typedef vector_reverse_iterator<T> reverse_iterator;
    reverse_iterator rbegin() { return reverse_iterator(buff + num - 1); }
    reverse_iterator rend() { return reverse_iterator(buff - 1); }
};

#endif

int main() {
    Vector<int> V(7, 6);
    cout << "\nVector ban dau:"; 
    for (int i = 0; i < V.size(); i++) cout << V[i] << " ";

    // Gan gia tri binh phuong cho cac phan tu
    for (int i = 0; i < V.size(); i++) V[i] = i * i;
    cout << "\nVector binh phuong:"; 
    for (int i = 0; i < V.size(); i++) cout << V[i] << " ";

    // Them cac phan tu vao vector
    V.push_back(11);
    V.push_back(13);
    V.insert(2, 20);
    cout << "\nVector :"; 
    for (int i = 0; i < V.size(); i++) cout << V[i] << " ";

    // Duyet vector bang iterator
    cout << "\nDuyet :"; 
    for (Vector<int>::iterator it = V.begin(); it != V.end(); it++) cout << *it << "\t";

    // Duyet vector bang auto
    cout << "\nDuyet auto : "; 
    for (auto x : V) cout << x << " ";

    // Duyet nguoc vector
    cout << "\nNguoc : "; 
    for (auto it = V.rbegin(); it != V.rend(); it++) cout << *it << " ";

    return 0;
}
