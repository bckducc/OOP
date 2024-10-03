#include<iostream>
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
	int BacLuong;
public:
	NhanVien()
	{
		MaNV = MaNV_BD++;
	}

	void NhapNhanVien()
	{
		cin.ignore();
		cout << "Ho ten: "; getline(cin, HoTen);]
		cout << "Dia chi: "; getline(cin, DiaChi);
		cout << "So dien thoai: "; getline(cin, SDT);
		do
		{
			cout << "Bac luong: "; cin >> BacLuong;
		} while (BacLuong < 1 || BacLuong > 9);
	}

	void XuatNhanVien()
	{

	}
};

class
{

};

class
{

};

int main()
{
	return 0;
}