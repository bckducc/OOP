#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>

using namespace std;

class SinhVien
{
private:
    static int MSV_BD;
    int MSV;
    string HoTen;
    string DiaChi;
    string SDT;
    string Lop;
public:
    SinhVien()
    {
        MSV = MSV_BD++;
    }
    void NhapSV()
    {
        cout << "Ho ten: "; getline(cin, HoTen);
        cout << "Dia chi: "; getline(cin, DiaChi);
        cout << "So dien thoai: "; getline(cin, SDT);
        cout << "Lop: "; getline(cin, Lop);
    }
    void XuatSV()
    {
        cout << setw(15) << left << MSV;
        cout << setw(20) << left << HoTen;
        cout << setw(15) << left << DiaChi;
        cout << setw(15) << left << SDT;
        cout << setw(20) << left << Lop << endl;
    }
    string getHoTen()
    {
        return HoTen;
    }
};

int SinhVien::MSV_BD = 10000;

class MonHoc
{
private:
    static int MMH_BD;
    int MMH;
    string TenMon;
    int TongST;
    int LoaiMonHoc;
public:
    MonHoc()
    {
        MMH = MMH_BD++;
    }
    void NhapMH()
    {
        cout << "Ten mon: "; getline(cin, TenMon);
        cout << "Tong so tiet: "; cin >> TongST;
        cout << "Vui long chon loai mon." << endl;
        cout << setw(30) << left << "1.Dai cuong    2.Co so nganh   3.Chuyen nganh bat buoc     4.Chuyen nganh tu chon" << endl;
        cout << "Loai mon do la: "; cin >> LoaiMonHoc;
    }
    void XuatMH()
    {
        cout << setw(10) << left << MMH;
        cout << setw(15) << left << TenMon;
        cout << setw(15) << left << TongST;
        if (LoaiMonHoc == 1)
        {
            cout << setw(15) << left << "Dai cuong" << endl;
        }
        else if (LoaiMonHoc == 2)
        {
            cout << setw(15) << left << "Co so nganh" << endl;
        }
        else if (LoaiMonHoc == 3)
        {
            cout << setw(15) << left << "Chuyen nganh bat buoc" << endl;
        }
        else
        {
            cout << setw(15) << left << "Chuyen nganh tu chon" << endl;
        }
    }
    string getTenMon()
    {
        return TenMon;
    }
};
int MonHoc::MMH_BD = 100;

class BangQL
{
private:
    time_t now = time(0);
    char* lap = ctime(&now);
public:
    friend class SinhVien;
    friend class MonHoc;
    SinhVien QLSV;
    MonHoc QLMH;

};

int main()
{
    vector<SinhVien> sv;
    vector<MonHoc> mh;

    int sosv;

    cout << "Nhap so sinh vien: "; cin >> sosv;
    cin.ignore();
    cout << endl;
    sv.resize(sosv);
    for (int i = 0; i < sosv; i++)
    {
        sv[i].NhapSV();
        cout << endl;
    }
    cout << setw(15) << left << "MSV";
    cout << setw(20) << left << "Ho ten";
    cout << setw(15) << left << "Dia chi";
    cout << setw(15) << left << "So dien thoai";
    cout << setw(20) << left << "Lop" << endl;
    for (int i = 0; i < sosv; i++)
    {
        sv[i].XuatSV();
    }
    cout << endl;

    int somh;

    cout << "Nhap so mon hoc: "; cin >> somh;
    cin.ignore();
    mh.resize(somh);
    for (int i = 0; i < somh; i++)
    {
        cout << "___________________" << endl;
        mh[i].NhapMH();
    }
    cout << endl;
    cout << setw(10) << left << "MMH";
    cout << setw(15) << left << "Ten mon";
    cout << setw(15) << left << "Tong so tiet";
    cout << setw(15) << left << "Loai mon hoc" << endl;
    for (int i = 0; i < somh; i++)
    {
        mh[i].XuatMH();
    }
    return 0;
}
