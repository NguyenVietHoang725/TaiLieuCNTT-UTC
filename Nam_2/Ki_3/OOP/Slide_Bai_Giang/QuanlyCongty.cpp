#include <iostream>
#include <vector>
using namespace std;

class CTY {
protected:
    string ten;
    int ntl; 

public:
    CTY() : ten(""), ntl(0) {}

    CTY(string tenCty, int namTl) : ten(tenCty), ntl(namTl) {}

    string getTen() {
        return ten;
    }

    int getNtl() {
        return ntl;
    }

    void setTen(string tenCty) {
        ten = tenCty;
    }

    void setNtl(int namTl) {
        ntl = namTl;
    }
};

class CTYPM : public CTY {
private:
    int sltv; 

public:
    CTYPM() : sltv(0) {}

    CTYPM(string tenCty, int namTl, int soLapTrinhVien) : CTY(tenCty, namTl), sltv(soLapTrinhVien) {}

    int getSltv() {
        return sltv;
    }

    void setSltv(int soLapTrinhVien) {
        sltv = soLapTrinhVien;
    }

    bool kiemTra() {
        return (ntl > 2000 && sltv > 20);
    }
};

class CTYVT : public CTY {
private:
    int soto; 

public:
    CTYVT() : soto(0) {}

    CTYVT(string tenCty, int namTl, int soTo) : CTY(tenCty, namTl), soto(soTo) {}

    int getSoto() {
        return soto;
    }

    void setSoto(int soTo) {
        soto = soTo;
    }

    bool kiemTra() {
        return (ntl < 2000 && soto <= 10);
    }
};

int main() {
    int n, m;

    cout << "Nhap so luong cong ty phan mem: ";
    cin >> n;

    cout << "Nhap so luong cong ty van tai: ";
    cin >> m;

    vector<CTYPM> dsCTYPM(n);  
    vector<CTYVT> dsCTYVT(m);  

    for (int i = 0; i < n; i++) {
        string ten;
        int namTl, sltv;

        cout << "Nhap ten cong ty phan mem thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, ten);

        cout << "Nhap nam thanh lap: ";
        cin >> namTl;

        cout << "Nhap so luong lap trinh vien: ";
        cin >> sltv;

        dsCTYPM[i] = CTYPM(ten, namTl, sltv);
    }

    for (int i = 0; i < m; i++) {
        string ten;
        int namTl, soto;

        cout << "Nhap ten cong ty van tai thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, ten);

        cout << "Nhap nam thanh lap: ";
        cin >> namTl;

        cout << "Nhap so luong oto: ";
        cin >> soto;

        dsCTYVT[i] = CTYVT(ten, namTl, soto);
    }

    cout << "\nDanh sach cong ty phan mem thanh lap sau nam 2000 va co tren 20 lap trinh vien:\n";
    for (int i = 0; i < n; i++) {
        if (dsCTYPM[i].kiemTra()) {
            cout << dsCTYPM[i].getTen() << endl;
        }
    }

    cout << "\nDanh sach cong ty van tai thanh lap truoc nam 2000 va co khong qua 10 oto:\n";
    for (int i = 0; i < m; i++) {
        if (dsCTYVT[i].kiemTra()) {
            cout << dsCTYVT[i].getTen() << endl;
        }
    }

    return 0;
}
