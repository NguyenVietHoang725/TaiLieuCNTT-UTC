#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define endl '\n'

class SoPhuc {
    private:
        double phanThuc; // Phan thuc cua so phuc
        double phanAo;   // Phan ao cua so phuc

    public:
        // Constructor mac dinh
        SoPhuc() : phanThuc(0), phanAo(0) {}

        // Constructor co tham so
        SoPhuc(double thuc, double ao) : phanThuc(thuc), phanAo(ao) {}

        // Toan tu nhap
        friend istream& operator>>(istream& is, SoPhuc& sp) {
            cout << "Phan thuc: ";
            is >> sp.phanThuc;
            cout << "Phan ao: ";
            is >> sp.phanAo;

            return is;
        }

        // Toan tu xuat
        friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
            os << sp.phanThuc; // In phan thuc

            // In phan ao voi dinh dang dung
            if (sp.phanAo >= 0) 
                os << " + " << sp.phanAo << "i";
            else 
                os << " - " << abs(sp.phanAo) << "i";

            os << endl;
            return os;
        }
        
        friend SoPhuc operator+(const SoPhuc& sp1, const SoPhuc& sp2) {
        	double thuc = sp1.phanThuc + sp2.phanThuc;
        	double ao = sp1.phanAo + sp2.phanAo;
        	return SoPhuc(thuc, ao);
		}
		
		friend SoPhuc operator-(const SoPhuc& sp1, const SoPhuc sp2) {
			double thuc = sp1.phanThuc - sp2.phanThuc;
			double ao = sp1.phanAo - sp2.phanAo;
			return SoPhuc(thuc, ao); 
		}
		
		friend SoPhuc operator*(const SoPhuc& sp1, const SoPhuc sp2) {
			double thuc = sp1.phanThuc * sp2.phanThuc - sp1.phanAo * sp2.phanAo;
			double ao = sp1.phanThuc * sp2.phanAo + sp1.phanAo * sp2.phanThuc;
			return SoPhuc(thuc, ao);
		}
		
		friend SoPhuc operator/(const SoPhuc& sp1, const SoPhuc sp2) {
			double thuc = (sp1.phanThuc * sp2.phanThuc + sp1.phanAo * sp2.phanAo) / (pow(sp2.phanThuc, 2) + pow(sp2.phanAo, 2));
			double ao = (sp2.phanThuc * sp1.phanAo - sp1.phanThuc * sp2.phanAo) / (pow(sp2.phanThuc, 2) + pow(sp2.phanAo, 2));
			return SoPhuc(thuc, ao);
		}
};

int main() {
    SoPhuc a, b; // Khai bao hai so phuc

    cout << "Nhap so phuc a: " << endl;
    cin >> a; // Nhap so phuc a
    cout << "Nhap so phuc b: " << endl;
    cin >> b; // Nhap so phuc b

    cout << "So phuc a la: " << a; // Xuat so phuc a
    cout << "So phuc b la: " << b; // Xuat so phuc b
	
	SoPhuc tong = a + b;
	cout << "Tong cua hai so phuc a va b bang: " << tong;
	
	SoPhuc hieu = a - b;
	cout << "Hieu cua hai so phuc a va b bang: " << hieu;
	
	SoPhuc tich = a * b;
	cout << "Tich cua hai so phuc a va b bang: " << tich;
	
	SoPhuc thuong = a / b;
	cout << "Thuong cua hai so phuc a va b bang: " << thuong;
	
    return 0;
}
