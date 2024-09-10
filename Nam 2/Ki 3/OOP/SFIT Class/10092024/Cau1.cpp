#include <iostream>
using namespace std;

class PS {

private:
	int tuSo;
	int mauSo;
	
public:
	PS() : tuSo(0), mauSo(1) {}
	PS(int tu, int mau) : tuSo(tu), mauSo(mau) {
		if (mauSo == 0) {
			cout << "Mau so phai khac 0. Dat mac dinh bang 1\n";
			mauSo = 1;
		}
	}
	
	void nhapPS();
	friend PS operator*(const PS &ps1, const PS &ps2);
	friend ostream& operator<<(ostream& output, const PS &ps);
	void rutGon();
	int ucln(int a, int b);
};

void PS::nhapPS() {
	cout << "Nhap lan luot tu so va mau so: ";
    cin >> tuSo >> mauSo;
    if (mauSo == 0) {
        cout << "Mau so phai khac 0. Dat mac dinh bang 1\n";
        mauSo = 1;
    }
}

int PS::ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

void PS::rutGon() {
    int gcd = ucln(tuSo, mauSo);
    tuSo /= gcd;
    mauSo /= gcd;
    if (mauSo < 0) { 
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

PS operator*(const PS &ps1, const PS &ps2) {
    PS ketQua(ps1.tuSo * ps2.tuSo, ps1.mauSo * ps2.mauSo);
    ketQua.rutGon();
    return ketQua;
}

ostream& operator<<(ostream& output, PS &ps) {
	ps.rutGon(); 
    output << ps.tuSo << "/" << ps.mauSo;
    return output;
}

int main() {
    PS ps1(1, 2);
    
    PS ps2;
    ps2.nhapPS();
    
    PS p = ps1 * ps2;
    cout << "Tich hai phan so " << ps1 << " va " << ps2 << " bang: " << p << endl;
    
    return 0;
}
