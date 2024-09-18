#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'

class Rect {
	
private:
    int nWidth;
    int nHeight;

public:
	// Default Constructor
    Rect() : nWidth(0), nHeight(0) {}
	// Parameterized Constructor
    Rect(int w, int h) : nWidth(w), nHeight(h) {}
	
	// Methods
    void Input();
    void Output() const;
    void Init(int w, int h);
    int Area() const;
    bool IsSquare() const;
};

// Ham nhap do dai cac chieu cua hinh chu nhat tu ban phim
void Rect::Input() {
    cout << "Nhap lan luot chieu rong va chieu dai: ";
    cin >> nWidth >> nHeight;
	// Kiem tra gia tri nhap vao co thoa man hay khong
    if (nWidth < 0 || nHeight < 0) {
        cout << "Chieu rong va chieu dai phai la so duong." << endl;
        nWidth = 0;
        nHeight = 0;
    }
}

// Ham xuat do dai cac chieu cua hinh chu nhat
void Rect::Output() const {
    cout << "Chieu rong va chieu dai cua HCN vua nhap la: ";
    cout << nWidth << ", " << nHeight << endl;
}

// Ham khoi tao do dai cac chieu cua hinh chu nhat voi cac gia tri w va h
void Rect::Init(int w, int h) {
    nWidth = w;
    nHeight = h;
}

// Ham tra ve dien tich cua hinh vuong
int Rect::Area() const {
    if (IsSquare()) {
        return nWidth * nHeight;
    } else {
        return -1; 
    }
}

// Ham kiem tra xem hinh chu nhat co phai hinh vuong hay khong
bool Rect::IsSquare() const {
    return (nWidth == nHeight);
}

int main() {
    // Yeu cau a, b
    Rect a, b;

    cout << "Nhap thong tin cho hinh chu nhat a:" << endl;
    a.Input();
    a.Output();
    int areaA = a.Area();
    if (areaA != -1) {
        cout << "Dien tich cua HCN ma la hinh vuong la: " << areaA << endl;
    } else {
        cout << "HCN a khong phai la hinh vuong." << endl;
    }

    cout << "Nhap thong tin cho hinh chu nhat b:" << endl;
    b.Init(2, 2);
    b.Output();
    int areaB = b.Area();
    if (areaB != -1) {
        cout << "Dien tich cua HCN ma la hinh vuong la: " << areaB << endl;
    } else {
        cout << "HCN b khong phai la hinh vuong." << endl;
    }

    // Yeu cau c
    int n;
    cout << "\nNhap so luong hinh chu nhat: ";
    cin >> n;
    vector<Rect> r(n);

    for (int i = 0; i < n; i++) {
        cout << "HCN " << (i + 1) << ":" << endl;
        r[i].Input();
    }

    int cnt = 0;
    int maxArea = 0;

    for (const auto& rect : r) {
        if (rect.IsSquare()) {
            cnt++;
            int area = rect.Area();
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    cout << "So luong hinh vuong: " << cnt << endl;
    if (cnt > 0) {
        cout << "Dien tich hinh vuong lon nhat: " << maxArea << endl;
    } else {
        cout << "Khong co hinh vuong trong danh sach." << endl;
    }

    return 0;
}
