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
	//H�m t?o m?c ??nh
	SanPham() {}

	//H�m t?o 2 tham s?
	SanPham(string ten, string nhasx)
	{
		Ten = ten;
		NhaSX = nhasx;
	}

	//H�m nh?p th�ng tin s?n ph?m
	void NhapSP()
	{
		cout << "Ten san pham: "; getline(cin, Ten);
		cout << "Nha san xuat: "; getline(cin, NhaSX);
	}

	//H�m xu?t th�ng tin s?n ph?m
	void XuatSP()
	{
		cout << "Ten san pham: " << Ten << endl;
		cout << "Nha san xuat: " << NhaSX << endl;
	}

	//H�m bi?n ??i bi?n T�n
	void setTen(string ten)
	{
		this->Ten = ten;
	}

	//H�m bi?n ??i bi?n NhaSX
	void setNhaSX(string nhasx)
	{
		this->NhaSX = nhasx;
	}

	//H�m truy c?p bi?n Ten
	string getTen()
	{
		return Ten;
	}

	//H�m truy c?p bi?n NhaSX
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
	//H�m t?o m?c ??nh
	BanLe() {}

	//H�m t?p 4 th�nh vi�n
	BanLe(int giaban, int soluong, string ten, string nhasx)
		: SanPham(ten, nhasx)
	{
		GiaBan = giaban;
		SoLuong = soluong;
	}

	//H�m nh?p th�ng tin b�n l?
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

	//H�m xu?t th�ng tin b�n l?
	void XuatBL()
	{
		SanPham::XuatSP();
		cout << "Gia ban: " << GiaBan << endl;
		cout << "So luong: " << SoLuong << endl;
	}

	//h�m thanh toan
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