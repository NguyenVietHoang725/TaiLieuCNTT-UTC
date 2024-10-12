#include <iostream>
using namespace std;

class Vector {
private:
    int size;
    float *data;
public:
    Vector() : size(0), data(nullptr) {}

    Vector(int n) : size(n) {
        data = new float[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    Vector(const Vector& v) {
        size = v.size;
        data = new float[size];
        for (int i = 0; i < size; ++i) {
            data[i] = v.data[i];
        }
    }

    ~Vector() {
        if(data != nullptr) 
            delete[] data;
    }

    Vector& operator=(const Vector& v) { 
        if (this != &v) {
            if (data != nullptr) {
                delete[] data;
            }

            size = v.size;
            data = new float[size];
            for (int i = 0; i < size; ++i) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    float& operator[](int index) { 
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    bool operator==(const Vector& v) const {
        if (size != v.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i]!= v.data[i]) {
                return false;
            }
        }
        return true;
    }

    friend istream& operator>>(istream& is, Vector& v) {
        cout << "Nhap kich thuoc vector: ";
        is >> v.size;

        if (v.data != nullptr) {
            delete[] v.data;
        }
        v.data = new float[v.size];

        cout << "Nhap cac phan tu cua vector: ";
        for (int i = 0; i < v.size; i++) {
            is >> v.data[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "Vector: ";
        for (int i = 0; i < v.size; i++) {
            os << v.data[i] << " ";
        }
        return os;
    }
};

int main() {
    Vector v1;
    cin >> v1;
    cout << v1;

    Vector v2 = v1;
    cout << "\nVector v2 (sao chep tu v1): " << v2 << endl;

    Vector v3;
    v3 = v1;
    cout << "\nVector v3 (gan cho v1): " << v3 << endl;

    if (v1 == v2) {
        cout << "\nVector v1 va v2 giong nhau." << endl;
    }

    try {
        cout << "Phan tu thu 2 cua v1: " << v1[1] << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}