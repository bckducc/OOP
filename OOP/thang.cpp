#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class HoaQua
{
protected:
	string maHoaQua;
	string tenHoaQua;
	string xuatXu;
	int gia;
	int thanhTien = 0;
public:
	HoaQua()
	{
	}

	HoaQua(string maHoaQua, string tenHoaQua, string xuatXu, int gia, int thanhTien)
	{
		this->maHoaQua = maHoaQua;
		this->tenHoaQua = tenHoaQua;
		this->xuatXu = xuatXu;
		this->gia = gia;
		this->thanhTien = thanhTien;
	}

	string getMaHoaQua()
	{
		return maHoaQua;
	}

	void setMaHoaQua(string maHoaQua)
	{
		this->maHoaQua = maHoaQua;
	}

	string getTenHoaQua()
	{
		return tenHoaQua;
	}
	void setTenHoaQua(string tenHoaQua)
	{
		this->tenHoaQua = tenHoaQua;
	}

	void nhapHQ()
	{
		cin.ignore();
		cout << "Nhap ma hoa qua: "; getline(cin, maHoaQua);
		cout << "Nhap ten hoa qua: "; getline(cin, tenHoaQua);
		cout << "Xuat xu: "; getline(cin, tenHoaQua);
		cout << "Nhap thanh tien: "; cin >> thanhTien;
	}

	void xuatHQ()
	{
		cout << "ma hoa qua la: " << maHoaQua << endl;
		cout << "Ten hoa qua la: " << tenHoaQua << endl;
		cout << "xuat xu la: " << xuatXu << endl;
		cout << "Thanh tien la: " << thanhTien << endl;
	}

	//	friend HoaQua operator *(HoaQua& a)
	//	{
	//		HoaQua result;
	//		result.thanhTien = this->gia * a.soLuong;
	//		return result;	
	//	}


	friend HoaQua operator +(HoaQua a, HoaQua b)
	{
		HoaQua c;
		c.thanhTien = a.thanhTien + b.thanhTien;
		return c;
	}
};

class DuaHau : public HoaQua
{
private:
	int khoiLuong;
public:
	DuaHau()
	{

	}

	DuaHau(int khoiLuong, string maHoaQua, string tenHoaQua, string xuatXu, int gia, int thanhTien) : HoaQua(maHoaQua, tenHoaQua, xuatXu, gia, thanhTien)
	{
		this->khoiLuong = khoiLuong;
	}

	int getThanhTien() {
		return gia * khoiLuong;
	}

	void nhapDH()
	{
		HoaQua::nhapHQ();
		cout << "Nhap khoi luong: "; cin >> khoiLuong;
	}
	void xuatDH()
	{
		HoaQua::xuatHQ();
		getThanhTien();
	}
};


class QuaDua : public HoaQua
{
private:
	int soLuong;
public:
	QuaDua() {
	}
	QuaDua(int soLuong, string maHoaQua, string tenHoaQua, string xuatXu, int gia, int thanhTien) : HoaQua(maHoaQua, tenHoaQua, xuatXu, gia, thanhTien)
	{
		this->soLuong = soLuong;
	}
	int getThanhTien()
	{
		return gia * soLuong;
	}
	void nhapDH()
	{
		HoaQua::nhapHQ();
		cout << "Nhap so luong: "; cin >> soLuong;
	}

	void xuatQD()
	{
		HoaQua::xuatHQ();
		getThanhTien();
	}
};



int main()
{
	vector<DuaHau> dh;
	vector<QuaDua> qd;
	int n, k;
	cout << "Nhap so luong: "; cin >> n;
	cout << "Nhap 1 de nhap dua hau \nNhap 2 de nhap qua dua \nNhap 0 de thoat\n";
	cout << "moi ban nha: "; cin >> k;
	qd.resize(n);
	dh.resize(n);
	if (k == 0)
	{
		cout << "ban da thoat !";
	}
	else if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "moi ban nhap dua hau thu" << i + 1 << ": \n";
			dh[i].nhapDH();
		}
		for (int i = 0; i < n; i++)
		{
			cout << "moi ban nhap dua hau thu" << i + 1 << ": ";
			dh[i].xuatDH();
		}
	}

	HoaQua c;
	c;

	return 0;
}
























