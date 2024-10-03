#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

class HoaQua
{
private:
	string MaHQ;
	string TenHQ;
	string XuatXu;
	int Gia;
	int ThanhTien = 0;
public:
	//Ham tao mac dinh
	HoaQua()
	{
		MaHQ = "unknow";
		TenHQ = "unknow";
		XuatXu = "unknow";
		Gia = 0;
		ThanhTien = 0;
	}

	//Ham tao tuong minh
	HoaQua(string a, string b, string c, int gia, int e)
	{
		MaHQ = a;
		TenHQ = b;
		XuatXu = c;
		Gia = gia;
		ThanhTien = e;
	}

	//Ham huy
	~HoaQua()
	{
		cout << "Ham huy duoc goi" << endl;
	}

	//Ham truy cap ten
	string getTenHQ()
	{
		return TenHQ;
	}

	//Ham bien doi ten
	void setTenHQ(string a)
	{
		TenHQ = a;
	}

	//Ham nhap
	void NhapHQ()
	{
		cout << "	Ma hoa qua: "; getline(cin, MaHQ);
		cout << "	Ten hoa qua: "; getline(cin, TenHQ);
		cout << "	Xuat xu: "; getline(cin, XuatXu);
		cout << "	Gia: "; cin >> Gia;
		cin.ignore();
	}

	//Ham xuat
	void XuatHQ()
	{
		cout << "	Ma hoa qua: " << MaHQ << endl;
		cout << "	Ten hoa qua: " << TenHQ << endl;
		cout << "	Xuat xu: " << XuatXu << endl;
		cout << "	Gia: " << Gia << endl;
	}

	friend HoaQua operator +(HoaQua a, HoaQua b)
	{
		HoaQua c;
		c.ThanhTien = a.ThanhTien + b.ThanhTien;
		return c;
	}
};

class DuaHau : public HoaQua
{
private:
	float KhoiLuong;
public:
	//Ham tao mac dinh
	DuaHau()
	{
		KhoiLuong = 0;
	}

	//Ham tao tuong minh
	DuaHau(float a, string b, string c, string d, int gia, int f)
		: HoaQua(b, c, d, gia, f)
	{
		KhoiLuong = a;
	}

	//Ham truy cap
	float getKhoiLuong()
	{
		return KhoiLuong;
	}

	//Ham bien doi
	void setKhoiLuong(float a)
	{
		KhoiLuong = a;
	}

	//Ham nhap 
	void NhapDH()
	{
		HoaQua::NhapHQ();
		cout << "	Khoi luong: "; cin >> KhoiLuong;
		cin.ignore();
	}

	//Ham xuat
	void XuatDH()
	{
		HoaQua::XuatHQ();
		cout << "	Khoi luong: " << KhoiLuong << endl;
	}

	//int getThanhTien()
	//{
		//return gia*KhoiLuong;
	//23}
};

class QuaDua : public HoaQua
{
private:
	int SoLuong;
public:
	//Ham tao mac dinh
	QuaDua()
	{
		SoLuong = 0;
	}

	//Ham tao tuong minh
	QuaDua(int a, string b, string c, string d, int e, int f)
		: HoaQua(b, c, d, e, f)
	{
		SoLuong = a;
	}

	//Ham truy cap
	//int getSoLuong()
	//{
		//return SoLuong;
	//}

	//Ham bien doi
	void setSoLuong(int a)
	{
		SoLuong = a;
	}

	//ham nhap
	void NhapQD()
	{
		HoaQua::NhapHQ();
		cout << "	So luong: "; cin >> SoLuong;
	}

	//Ham xuat
	void XuatQD()
	{
		HoaQua::XuatHQ();
		cout << "	So luong: " << SoLuong << endl;
	}


};

int main()
{
	//vector<DuaHau> DH;
	//vector<QuaDua> QD;

	DuaHau DH1;
	QuaDua QD1;
	int soqua;
	cout << "Nhap so luong qua: "; cin >> soqua;
	for (int i = 0; i < soqua; i++)
	{
		int lc;
		cout << "\nQua thu " << i + 1 << endl;
		cout << "Qua nay la qua" << endl;
		cout << "1.Dua hau		2.Qua dua" << endl;
		cout << "Lua chon cua ban: "; cin >> lc;
		cin.ignore();
		if (lc == 1)
		{
			DH1.NhapDH();
		}
		else if (lc == 2)
		{
			QD1.NhapQD();
		}
	}
	for (int i = 0; i < soqua; i++)
	{
		cout << "\n			Danh sach hoa qua" << endl;
		cout << "\nDanh sach dua hau" << endl;
		DH1.XuatDH();
		cout << "\nDanh sach qua dua" << endl;
		QD1.XuatQD();
	}
	return 0;
}