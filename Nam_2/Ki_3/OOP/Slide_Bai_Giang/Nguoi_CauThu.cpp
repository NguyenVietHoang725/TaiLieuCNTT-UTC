#include <iostream>
#include <string>
using namespace std;

class Nguoi {
private:
    string hoTen;
    int tuoi;

public:
    Nguoi() : hoTen("empty"), tuoi(0) {}
    Nguoi(string ten, int tuoi) : hoTen(ten), tuoi(tuoi) {}

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(); 
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << " tuoi" << endl;
    }

    int getTuoi() const {
        return tuoi;
    }
};

class Cauthu : public Nguoi {
private:
    int sbt;  
    int sptd; 

public:
    Cauthu() : Nguoi(), sbt(0), sptd(0) {}
    Cauthu(string ten, int tuoi, int sbt, int sptd) 
        : Nguoi(ten, tuoi), sbt(sbt), sptd(sptd) {}

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap so ban thang: ";
        cin >> sbt;
        cout << "Nhap so phut thu dau: ";
        cin >> sptd;
    }

    void xuat() const {
        Nguoi::xuat();
        cout << "So ban thang: " << sbt << endl;
        cout << "So phut thi dau: " << sptd << endl;
    }

    int getSBT() const {
        return sbt;
    }

    int getSPTD() const {
        return sptd;
    }
};

int main() {
    int n;
    cout << "Nhap so cau thu: ";
    cin >> n;

    // Cấp phát bộ nhớ động cho danh sách cầu thủ
    Cauthu* dsCauthu = new Cauthu[n];

    // Nhập thông tin cho từng cầu thủ
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho cau thu thu " << i + 1 << ":\n";
        dsCauthu[i].nhap();
    }

    // Xuất thông tin danh sách cầu thủ
    cout << "\nDanh sach cau thu:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin cau thu thu " << i + 1 << ":\n";
        dsCauthu[i].xuat();
    }

    int maxTuoi = -1;
    int idx;
    for (int i = 0; i < n; i++) {
        if (maxTuoi <= dsCauthu[i].getTuoi()) {
            maxTuoi = dsCauthu[i].getTuoi();
            idx = i;
        }
    }
    cout << "\nCau thu co lon tuoi nhat la:\n";
    dsCauthu[idx].xuat();


    for (int i = 0; i < n; i++) {
        int tt = 0;
        if (dsCauthu[i].getSPTD() >= 300) {
            tt += 10;
        }
        tt += dsCauthu[i].getSBT() * 5;
        cout << "\nTong tien thuong cau thu cau thu thu " << i + 1 << " la: " << tt;  
    }

    // Giải phóng bộ nhớ động
    delete[] dsCauthu;

    return 0;
}
