#include <iostream>
#include <stdexcept>

using namespace std;

#define ll long long
#define endl '\n'

#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class Vector {
    private:
        T *V;
        int cap, num;

        // Ham mo rong kha nang cua vector
        void extend(int newCap) {
            if(newCap <= cap) {
                return;
            }

            cap = newCap;
            T *tmp = new T[cap];
            for (int i = 0; i < num; i++) {
                tmp[i] = V[i];
            }
            if(V) delete[] V;
            V = tmp;
        }

    public:
        // Ham tao mac dinh
        Vector() : cap(1), num(0) {
            V = new T[cap];
        }
        
        // Ham tao voi so luong va gia tri mac dinh
        Vector(int n, T value) : cap(n), num(n) {
            V = new T[cap];
            for(int i = 0; i < n; i++) {
                V[i] = value;
            }
        }

        // Ham tao sao chep
        Vector(const Vector<T>& other) : cap(other.cap), num(other.num) {
            V = new T[cap];
            for (int i = 0; i < num; i++) {
                V[i] = other.V[i];
            }
        }

        // Ham huy
        ~Vector() {
            if(V != nullptr) {
                delete[] V;
                V = nullptr;
            }
        }

        // Ham tra ve so luong phan tu hien co
        int size() const {
            return num;
        }

        // Ham kiem tra vector co rong hay khong
        bool empty() const {
            return num == 0;
        }

        // Ham tra ve so luong o nho hien co
        int capacity() const {
            return cap;
        }

        // Ham xoa phan tu cuoi cung
        void pop_back() {
            if(num > 0) {
                num--;
            } else {
                cout << "Khong co phan tu nao!" << endl;
            }
        }

        // Ham tra ve gia tri phan tu cuoi cung
        T& back() {
            if (num > 0) {
                return V[num - 1];
            } else {
                throw std::out_of_range("Thong bao loi!");
            }
        }

        // Ham tra ve gia tri phan tu dau tien
        T& front() {
            if (num > 0) {
                return V[0];
            } else {
                throw std::out_of_range("Thong bao loi!");
            }
        }

        // Ham them phan tu vao cuoi vector
        void push_back(T value) {
            if(num == cap) {
                extend(cap == 0 ? 1 : cap * 2);
            }
            V[num] = value;
            ++num;
        }

        // Ham them phan tu vao vi tri xac dinh
        void insert(int pos, T x) {
            if (pos < 0 || pos > num) {
                cout << "Chi so khong hop le!" << endl;
                return;
            }

            if(num == cap) {
                extend(cap == 0 ? 1 : cap * 2);
            }
            for (int i = num - 1; i >= pos; i--) {
                V[i + 1] = V[i];
            }
            V[pos] = x;
            ++num;
        }

        // Ham xoa phan tu o vi tri xac dinh
        void erase(int pos) {
            if (pos < 0 || pos >= num) {
                cout << "Chi so khong hop le!" << endl;
                return;
            }
            for (int i = pos; i < num - 1; i++) {
                V[i] = V[i + 1];
            }
            num--;
        }

        // Ham tra ve tham chieu cua phan tu thu i
        T& operator[] (int i) {
            if (i >= num || i < 0) {
                cout << "Chi so khong hop le!" << endl;
                throw std::out_of_range("Chi so khong hop le!");
            }
            return V[i];
        }

        // Ham gan vector moi cho vector hien tai
        Vector& operator= (const Vector<T>& b) {
            if (this == &b) {
                return *this;
            }

            if (cap != 0) {
                delete[] V;
            }

            num = b.num;
            cap = b.cap;
            if(cap != 0) {
                V = new T[cap];
                for (int i = 0; i < num; i++) {
                    V[i] = b.V[i];
                }
            } else {
                V = nullptr;
            }

            return *this;
        }

        // Ham gan gia tri cho vector
        void assign(int newSize, T value) {
            if (newSize > cap) {
                extend(newSize);
            }
            for (int i = 0; i < newSize; i++) {
                V[i] = value;
            }
            num = newSize;
        }

        // Ham xoa tat ca cac phan tu
        void clear() {
            num = 0;
        }

        // Ham thay doi kich thuoc vector
        void resize(int newSize, T value = T()) {
            if (newSize > cap) {
                extend(newSize);
            }
            for (int i = num; i < newSize; i++) {
                V[i] = value;
            }
            num = newSize;
        }

        // Ham dat kich thuoc toi da
        void reserve(int newCap) {
            if (newCap > cap) {
                extend(newCap);
            }
        }

        typedef T *iterator;
        iterator begin() {
            return V;
        }
        iterator end() {
            return V + num;
        }
};

#endif
