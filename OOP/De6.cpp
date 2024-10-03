#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class NhanVien
{
private:
	static int MaNV_BD;
	int MaNV;
	string HoTen;
	string DiaChi;
	string SDT;
	string ChuyenMon;
public:
	//Ham tao mac dinh
	NhanVien()
	{
		MaNV = MaNV_BD++;
	}

	//Ham nhap nhan vien
	void NhapNV()
	{
		cout << "Ho ten: "; getline(cin, HoTen);
		cout << "DIa chi: "; getline(cin, DiaChi);
		cout << "SDT: "; getline(cin, SDT);
		cout << "Chuyen mon: "; getline(cin, ChuyenMon);
	}

	//Ham xuat nhan vien
	void XuatNV()
	{
		cout << "Ho ten: " << HoTen << endl;
		cout << "DIa chi: " << DiaChi << endl;
		cout << "SDT: " << SDT << endl;
		cout << "Chuyen mon: " << ChuyenMon << endl;
	}

	string getHoTen()
	{
		return HoTen;
	}
};

int NhanVien::MaNV_BD = 10000;

class DuAn
{
private:
	static int MaDA_BD;
	int MaDA;
	string TenDA;
	int KieuDA;
	int TongKP;
public:
	DuAn()
	{
		MaDA = MaDA_BD++;
	}

	void NhapDA()
	{
		cout << "Ten du an: "; getline(cin, TenDA);
		cout << "Kieu"
	}
};