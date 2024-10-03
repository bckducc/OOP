#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<fstream> //Lap chong toan tu

using namespace std;

class NhanVien
{
protected:
	string HoTen;
	int NamSinh;
	string GioiTinh;
	float Luong;
public:
	//Ham tao khong tham so
	NhanVien()
	{
		HoTen = "unknow";
		NamSinh = 0;
		GioiTinh = "unknow";
		Luong = 0;
	}

	//Ham tao 4 tham so
	NhanVien(string hoten, int namsinh, string gioitinh, int luong)
	{
		HoTen = hoten;
		NamSinh = namsinh;
		GioiTinh = gioitinh;
		Luong = luong;
	}

	friend istream& operator >> (istream& in, NhanVien& nv)
	{
		cout << "	Ho ten: "; getline(in, nv.HoTen);
		cout << "	Nam sinh: "; in >> nv.NamSinh;
		in.ignore();
		cout << "	Gioi tinh: "; in >> nv.GioiTinh;
		cout << "	Luong: "; in >> nv.Luong;
		return in;
	}

	friend ostream& operator << (ostream& out, NhanVien nv)
	{
		cout << "	Ho ten: "; out << nv.HoTen << endl;
		cout << "	Nam sinh: "; out << nv.NamSinh << endl;
		cout << "	Gioi tinh: "; out << nv.GioiTinh << endl;
		cout << "	Luong: "; out << nv.Luong << endl;
		return out;
	}

	string getHoTen()
	{
		return HoTen;
	}
}; 

class LapTrinhVien: public NhanVien
{
private:
	string NgonNguLT;
public:
	//Ham tao khong tham so
	LapTrinhVien()
	{
		NgonNguLT = "unknow";
	}

	//Ham tao 5 tham so
	LapTrinhVien(string ngonngult, string hoten, int namsinh, string gioitinh, int luong)
		: NhanVien(hoten, namsinh, gioitinh, luong)
	{
		NgonNguLT = ngonngult;
	}

	friend istream& operator >> (istream& in, LapTrinhVien& ltv)
	{
		
		cout << "	Ngon ngu lap trinh: "; getline(in, ltv.NgonNguLT);
		return in;
	}

	friend ostream& operator << (ostream& out, LapTrinhVien ltv)
	{

		cout << "	Ngon ngu lap trinh: "; out << ltv.NgonNguLT << endl;
		return out;
	}
};

class KiemThuVien: public NhanVien
{
private:
	string ChuyenMon;
public:
	//Ham tao khong tham so
	KiemThuVien()
	{
		ChuyenMon = "unknow";
	}

	//Ham tao 5 tham so
	KiemThuVien(string chuyenmon, string hoten, int namsinh, string gioitinh, int luong)
	{
		ChuyenMon = chuyenmon;
		HoTen = hoten;
		NamSinh = namsinh;
		GioiTinh = gioitinh;
		Luong = luong;
	}

	friend istream& operator >> (istream& in, KiemThuVien& ktv)
	{
		cout << "	Ho ten: "; getline(in, ktv.HoTen);
		cout << "	Nam sinh: "; in >> ktv.NamSinh;
		in.ignore();
		cout << "	Gioi tinh: "; in >> ktv.GioiTinh;
		cout << "	Luong: "; in >> ktv.Luong;
		cout << "	Chuyen mon: "; in >> ktv.ChuyenMon;
		return in;
	}

	friend ostream& operator >> (ostream& out, KiemThuVien ktv)
	{
		cout << "	Ho ten: "; out << ktv.HoTen << endl;
		cout << "	Nam sinh: "; out << ktv.NamSinh << endl;
		cout << "	Gioi tinh: "; out << ktv.GioiTinh << endl;
		cout << "	Luong: "; out << ktv.Luong << endl;
		cout << "	Chuyen mon: "; out << ktv.ChuyenMon << endl;
		return out;
	}
};

int main()
{
	vector<LapTrinhVien> a;
	vector<KiemThuVien> b;

	int sonv, lc;
	do
	{
		cout << "Nhap so nhan vien: "; cin >> sonv;
	} while (sonv <= 0 || sonv >= 10);
	cout << "\nBan muon nhap cho lap trinh vien hay kiem thu vien";
	cout << "\n1. Lap trinh vien	2. Kiem thu vien";
	cout << "\nLua chon cua ban: "; cin >> lc;
	cin.ignore();

	/**for (int i = 0; i < n; i++)
	{
		int x;
		1.LTV    2.KTV
		if 1 --> ltv.resize(ltv.size() + 1)
		cin >> ltv[ltv.size()]

	}
	*/
	for (int i = 0; i < sonv; i++)
	{
		if (lc == 1)
		{
			LapTrinhVien a1;
			cin >> a1;
			a.push_back(a1);
		}
		if (lc == 2)
		{
			KiemThuVien b1;
			cin >> b1;
			b.push_back(b1);
		}
		else
		{
			cout << "Ket thuc chuong trinh!";
		}
	}

	for (int i = 0; i < a.size(); i++)
	{
		cout << "Lap trinh vien thu " << i + 1 << endl;
		cout << a[i] << endl;
	}
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Kiem thu vien thu " << i + 1 << endl;
		cout << b[i] << endl;
	}

	string Ten;
	cout << "Nhap ten muon tim: "; getline(cin, Ten);
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].getHoTen() == Ten)
		{
			cout << a[i] << endl;
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i].getHoTen() == Ten)
		{
			cout << b[i] << endl;
		}
	}
	return 0;
}