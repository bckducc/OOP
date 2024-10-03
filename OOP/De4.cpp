#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class NhanVien
{
private:
	static int MaNV_BD;
	int MaNV;
	string HoTen;
	string DiaChi;
	string SDT;
	string NgayKy;
public:
	//Ham tang ma nhan vien
	NhanVien()
	{
		MaNV = MaNV_BD++;
	}

	//Ham nhap thong tin nhan vien
	void NhapNV()
	{
		cout << "Ho ten: "; getline(cin, HoTen);
		cout << "Dia chi: "; getline(cin, DiaChi);
		cout << "So dien thoai: "; getline(cin, SDT);
		cout << "Ngay ky: "; getline(cin, NgayKy);
	}

	//Ham xuat thong tin nhan vien
	void XuatNV()
	{
		cout << "Ma nhan vien: " << MaNV << endl;
		cout << "Ho ten: " << HoTen << endl;
		cout << "Dia chi: " << DiaChi << endl;
		cout << "So dien thoai: " << SDT << endl;
		cout << "Ngay ky hop dong: " << NgayKy << endl;
	}

	//DSNV
	void NhapDSNV()
	{
		cin.ignore();
		cout << "Ho ten: "; getline(cin, HoTen);
	}

	//DSNV
	void XuatDSNV()
	{
		cout << "\nMa nhan vien: " << MaNV << endl;
		cout << "Ho ten: " << HoTen << endl;
	}

	//Truy cap vao HoTen
	string getHoTen()
	{
		return HoTen;
	}
};

int NhanVien::MaNV_BD = 1000;

bool SapXepTheoTen(NhanVien a, NhanVien b)
{
	return a.getHoTen() < b.getHoTen();
}

class MatHang
{
private:
	static int MaMH_BD;
	int MaMH;
	string TenHang;
	int NhomHang;
	int GiaBan;
	int SoLuong;
public:
	//Ham tang ma mat hang
	MatHang()
	{
		MaMH = MaMH_BD++;
	}

	//Ham nhap thong tin mat hang
	void NhapMH()
	{
		cin.ignore();
		cout << "Ten hang: "; getline(cin, TenHang);
		cout << "Mat hang nay thuoc nhom hang" << endl;
		cout << "1.Dien tu		2.Dien lanh		3.May tinh		4.Thiet bi van phong" << endl;
		cout << "Nhom hang cua mat hang nay la: "; cin >> NhomHang;
		cout << "Gia ban: "; cin >> GiaBan;
		cout << "So luong: "; cin >> SoLuong;
	}

	//Ham xuat thong tin mat hang
	void XuatMH()
	{
		cout << "Ma mat hang: " << MaMH << endl;
		cout << "Ten hang: " << TenHang << endl;
		if (NhomHang == 1)
		{
			cout << "Nhom hang: Dien tu" << endl;
		}
		else if (NhomHang == 2)
		{
			cout << "Nhom hang: Dien lanh" << endl;
		}
		else if (NhomHang == 3)
		{
			cout << "Nhom hang: May tinh" << endl;
		}
		else if (NhomHang == 4)
		{
			cout << "Nhom hang: Thiet bi van phong" << endl;
		}
		cout << "Gia ban: " << GiaBan << endl;
		cout << "So luong: " << SoLuong << endl;
		cin.ignore();
	}

	int getNhomHang()
	{
		return NhomHang;
	}

	void XuatDSMatHang()
	{
		if (SoLuong <= 5)
		{
			cout << "Ma mat hang: " << MaMH << endl;
			cout << "Ten hang: " << TenHang << endl;
			if (NhomHang == 1)
			{
				cout << "Nhom hang: Dien tu" << endl;
			}
			else if (NhomHang == 2)
			{
				cout << "Nhom hang: Dien lanh" << endl;
			}
			else if (NhomHang == 3)
			{
				cout << "Nhom hang: May tinh" << endl;
			}
			else if (NhomHang == 4)
			{
				cout << "Nhom hang: Thiet bi van phong" << endl;
			}
			cout << "Gia ban: " << GiaBan << endl;
			cout << "So luong: " << SoLuong << endl;
		}
		else
		{
			cout << "\nVuot qua so luong cho phep." << endl;
		}
	}
};

int MatHang::MaMH_BD = 1000;

//Sap xep nhom hang
bool SapXepNhomHang(MatHang a, MatHang b)
{
	return a.getNhomHang() < b.getNhomHang();
}

class DSBanHang
{
private:
	int somhnv;
public:
	friend class NhanVien;
	friend class MatHang;
	NhanVien DSNV;
	MatHang DSMH;

	void NhapDSBH(NhanVien a, MatHang b)
	{
		DSNV = a;
		DSMH = b;
		a.NhapDSNV();
		cout << "So mat hang ma nhan vien do ban duoc: "; cin >> somhnv;
		b.NhapMH();
	}
	void XuatDSBH()
	{
		DSNV.XuatDSNV();
		DSMH.XuatDSMatHang();
	}
};

int main()
{
	vector<NhanVien> a;
	vector<MatHang> b;

	int sonv;
	cout << "Nhap so nhan vien: "; cin >> sonv;
	a.resize(sonv);
	cin.ignore();

	//Nhap thong tin nhan vien
	cout << "\n		Nhap thong tin nhan vien" << endl;
	for (int i = 0; i < sonv; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << endl;
		a[i].NhapNV();
	}

	//Xuat thong tin nhan vien
	cout << "\n__________________________________" << endl;
	cout << "		Xuat thong tin nhan vien" << endl;
	for (int i = 0; i < sonv; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << endl;
		a[i].XuatNV();
	}

	int somh;
	cout << "\nNhap so mat hang: "; cin >> somh;
	b.resize(somh);

	//Nhap thong tin mat hang
	cout << "\n		Nhap thong tin mat hang" << endl;
	for (int i = 0; i < somh; i++)
	{
		cout << "\nMat hang thu " << i + 1 << endl;
		b[i].NhapMH();
	}

	//Xuat thong tin mat hang
	cout << "\n__________________________________" << endl;
	cout << "		Xuat thong tin mat hang" << endl;
	for (int i = 0; i < somh; i++)
	{
		cout << "\nMat hang thu " << i + 1 << endl;
		b[i].XuatMH();
	}

	int somhnv;
	int run = 0;
	vector<DSBanHang> c(sonv * somh);
	
	//Nhap DS ban hang
	/*for (int i = 0; i < sonv; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << endl;
		a[i].NhapDSNV();
		cout << "So mat hang ma nhan vien do ban duoc: "; cin >> somhnv;
		for (int j = 0; j < somhnv; j++)
		{
			b[j].NhapMH();
		}
	}*/

	for (int i = 0; i < sonv; i++)
	{
		for (int j = 0; j < somh; j++)
		{
			c[run].NhapDSBH(a[i], b[j]);
			run++;
		}
	}

	//Xuat DS ban hang
	cout << "\n			Bang danh sach ban hang" << endl;
	for (int i = 0; i < sonv; i++)
	{
		a[i].XuatDSNV();
		for (int j = 0; j < somh; j++)
		{
			b[j].XuatDSMatHang();
		}
	}

	//Sap xep DS ban hang theo ten nhan vien
	sort (a.begin(), a.end(), SapXepTheoTen);
	cout << "\n			Bang danh sach ban hang sau khi sap xep theo ten nhan vien" << endl;
	for (int i = 0; i < sonv; i++)
	{
		a[i].XuatDSNV();
		for (int j = 0; j < somh; j++)
		{
			b[j].XuatDSMatHang();
		}
	}

	//Sap xep Ds ban hang theo nhom hang
	sort(b.begin(), b.end(), SapXepNhomHang);
	cout << "\n			Bang danh sach ban hang sau khi sap xep theo nhom hang" << endl;
	for (int i = 0; i < sonv; i++)
	{
		a[i].XuatDSNV();
		for (int j = 0; j < somh; j++)
		{
			b[j].XuatDSMatHang();
		}
	}

	return 0;
}