#include <iostream>
#include <string>

using namespace std;

#define ll long long
#define endl '\n'
struct NgayThangNam {
	int ngay;
	int thang;
	int nam;
};

class ThiSinh {
	private:
		string maTS;
		string tenTS;
		NgayThangNam ngaySinh;
		float diemToan, diemVan, diemAnh;
	public:
		ThiSinh() : maTS("empty"), tenTS("empty"), ngaySinh({0, 0, 0}), diemToan(0), diemVan(0), diemAnh(0) {}
		
		ThiSinh(string ma, string ten, int ngay, int thang, int nam, float diemToan, float diemVan, float diemAnh) {
			this->maTS = ma;
			this->tenTS = ten;
			this->ngaySinh.ngay = ngay;
			this->ngaySinh.thang = thang;
			this->ngaySinh.nam = nam;
			this->diemToan = diemToan;
			this->diemVan = diemVan;
			this->diemAnh = diemAnh;			
		}
};

int main() {
	
	

    return(0);
}
