#include "Vector.cpp"

int main() {
    try {
        int n;
        cout << "Nhap so luong phan tu cua vector: ";
        cin >> n;

        // Tao vector voi n phan tu, gia tri mac dinh la 0
        Vector<int> vec(n, 0);

        cout << "Nhap gia tri cho tung phan tu:" << endl;
        for (int i = 0; i < n; i++) {
            int x;
            cout << "Nhap gia tri phan tu tai vi tri " << i << ": ";
            cin >> x;
            vec[i] = x;
        }

        // In ra cac phan tu hien co trong vector su dung iterator
        cout << "Vector hien tai:" << endl;
        for (Vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        vec.push_back(100);  // Them phan tu vao cuoi vector
        vec.insert(2, 200);  // Chen phan tu vao vi tri 2
        vec.erase(1);        // Xoa phan tu tai vi tri 1

        // In ra cac phan tu sau khi thao tac su dung iterator
        cout << "Vector sau khi thao tac:" << endl;
        for (Vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        // Kiem tra phan tu dau tien va cuoi cung
        cout << "Phan tu dau tien: " << vec.front() << endl;
        cout << "Phan tu cuoi cung: " << vec.back() << endl;

        // Kiem tra kich thuoc va kha nang
        cout << "Kich thuoc hien tai: " << vec.size() << endl;
        cout << "Kich thuoc toi da: " << vec.capacity() << endl;

        // Thay doi kich thuoc vector
        vec.resize(10, 50);

        // In ra cac phan tu sau khi thay doi kich thuoc su dung iterator
        cout << "Vector sau khi thay doi kich thuoc:" << endl;
        for (Vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

    } catch (const std::exception& e) {
        // Xu ly ngoai le
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}
