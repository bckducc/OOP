#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class SanPham
{
private:
	string Ten;
	string NhaSX;
public:
	//Hàm t?o m?c ??nh
	SanPham() {}

	//Hàm t?o 2 tham s?
	SanPham(string ten, string nhasx)
	{
		Ten = ten;
		NhaSX = nhasx;
	}

	//Hàm nh?p thông tin s?n ph?m
	void NhapSP()
	{
		cout << "Ten san pham: "; getline(cin, Ten);
		cout << "Nha san xuat: "; getline(cin, NhaSX);
	}

	//Hàm xu?t thông tin s?n ph?m
	void XuatSP()
	{
		cout << "Ten san pham: " << Ten << endl;
		cout << "Nha san xuat: " << NhaSX << endl;
	}

	//Hàm bi?n ??i bi?n Tên
	void setTen(string ten)
	{
		this->Ten = ten;
	}

	//Hàm bi?n ??i bi?n NhaSX
	void setNhaSX(string nhasx)
	{
		this->NhaSX = nhasx;
	}

	//Hàm truy c?p bi?n Ten
	string getTen()
	{
		return Ten;
	}

	//Hàm truy c?p bi?n NhaSX
	string getNhaSX()
	{
		return NhaSX;
	}
};

class BanLe: public SanPham
{
private:
	int GiaBan;
	int SoLuong;
public:
	//Hàm t?o m?c ??nh
	BanLe() {}

	//Hàm t?p 4 thành viên
	BanLe(int giaban, int soluong, string ten, string nhasx)
		: SanPham(ten, nhasx)
	{
		GiaBan = giaban;
		SoLuong = soluong;
	}

	//Hàm nh?p thông tin bán l?
	void NhapBL()
	{
		cin.ignore();
		SanPham::NhapSP();
		cout << "Gia ban: "; cin >> GiaBan;
		do
		{
			cout << "So luong: "; cin >> SoLuong;
		} while (SoLuong >= 10);
	}

	//Hàm xu?t thông tin bán l?
	void XuatBL()
	{
		SanPham::XuatSP();
		cout << "Gia ban: " << GiaBan << endl;
		cout << "So luong: " << SoLuong << endl;
	}

	//hàm thanh toan
	void ThanhToan()
	{
		cout << "Thanh toan san pham; " << GiaBan * SoLuong << endl;
	}

	void MinThanhToan()
	{
		int min = 0;
		if (GiaBan * SoLuong > min)
		{
			min = GiaBan * SoLuong;
		}
	}
};

class BanSi : public SanPham
{
private:
	int GiaBan;
	int SoLuong;
public:
	//
	BanSi() {};

	//
	BanSi(int giaban, int soluong, string ten, string nhasx)
		: SanPham(ten, nhasx)
	{
		GiaBan = giaban;
		SoLuong = soluong;
	}

	//
	void NhapBS()
	{
		SanPham::NhapSP();
		cout << "Gia ban: "; cin >> GiaBan;
		do
		{
			cout << "So luong: "; cin >> SoLuong;
		} while (SoLuong <= 100);
	}

	//
	void XuatBS()
	{
		cin.ignore();
		SanPham::XuatSP();
		cout << "Gia ban: " << GiaBan << endl;
		cout << "So luongL " << SoLuong << endl;
	}

	//
	void ThanhToan()
	{
		cout << "Thanh toan: " << GiaBan * SoLuong << endl;
	}
};

int main()
{
	vector<BanLe> BL;
	vector<BanSi> BS;

	int loaisp, sosp;
	cout << "Ban muon nhap cho loai san pham nao?" << endl;
	cout << "1. Ban le			2. Ban si" << endl;
	cout << "Lua chon cua ban la: "; cin >> loaisp;

	if (loaisp == 1)
	{
		cout << "So san pham ban muon nhap; "; cin >> sosp;
		for (int i = 0; i < sosp; i++)
		{
			cout << "San pham ban le thu " << i + 1 << endl;
			BL[i].NhapBL();
		}

		for (int i = 0; i < sosp; i++)
		{
			cout << "San pham ban le thu " << i + 1 << endl;
			BL[i].XuatBL();
			BL[i].ThanhToan();
		}

		for (int i = 0; i < sosp; i++)
		{
			BL[i].MinThanhToan();
			BL[i].XuatBL();
			BL[i].ThanhToan();
		}

		/*auto min = min_element(BL.begin(), BL.end());
		if (min != BL.end())
		{
			for (int i = 0; i < sosp; i++)
			{
				cout << endl;
				BL[i].XuatBL();
				BL[i].ThanhToan();
			}
		}

		/*for (int i = 0; i < sosp; i++)
		{
			BL[0].ThanhToan() < BL[i].ThanhToan();
		}*/
	}

	else if (loaisp == 2)
	{
		cout << "So san pham ban muon nhap; "; cin >> sosp;
		for (int i = 0; i < sosp; i++)
		{
			cout << "San pham ban si thu " << i + 1 << endl;
			BS[i].NhapBS();
		}

		for (int i = 0; i < sosp; i++)
		{
			cout << "San pham ban si thu " << i + 1 << endl;
			BS[i].XuatBS();
			BS[i].ThanhToan();
		}
	}

	else
	{
		return 0;
	}
}