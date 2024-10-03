#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class BanDoc
{
private:
    static int MaBanHocBD;
    int MaBanDoc;
    string HoTen;
    string DiaChi;
    string SDT;
    int LoaiBanDoc;
public:
    BanDoc()
    {
        MaBanDoc = MaBanHocBD++;
    }

    void NhapBanDoc()
    {
        cout << "Ho ten: "; getline(cin, HoTen);
        cout << "Dia chi: "; getline(cin, DiaChi);
        cout << "So dien thoai: "; getline(cin, SDT);
        cout << "Vui long chon loai ban doc:" << endl;
        cout << "1.Sinh vien    2.Hoc vien cao hoc     3.Giao vien" << endl;
        cout << "Lua chon cua toi: "; cin >> LoaiBanDoc;
        cin.ignore();
    }

    void XuatBanDoc()
    {
        cout << setw(15) << left << MaBanDoc;
        cout << setw(15) << left << HoTen;
        cout << setw(15) << left << DiaChi;
        cout << setw(20) << left << SDT;
        if (LoaiBanDoc == 1)
        {
            cout << setw(20) << left << "Sinh vien";
        }
        else if (LoaiBanDoc == 2)
        {
            cout << setw(20) << left << "Hoc vien cao hoc";
        }
        else
        {
            cout << setw(20) << left << "Giao vien";
        }
        cout << endl;
    }
};

int BanDoc::MaBanHocBD = 10000;

class Sach
{
private:
    static int MaSachBD;
    int MaSach;
    string TenSach;
    string TacGia;
    int ChuyenNganh;
    int NamXB;
public:
    Sach()
    {
        MaSach = MaSachBD++;
    }

    void NhapSach()
    {
        cout << "Ten sach: "; getline(cin, TenSach);
        cout << "Tac gia: "; getline(cin, TacGia);
        cout << "Vui long chon lua chon cua ban:" << endl;
        cout << "1.Khoa hoc tu nhien    2.Van hoc-Nghe thuat    3.Dien tu vien thong    4.Cong nghe thong tin" << endl;
        cout << "Lua chon cua toi: "; cin >> ChuyenNganh;
        cout << "Nam xuat ban: "; cin >> NamXB;
        cin.ignore();
    }

    void XuatSach()
    {
        cout << setw(15) << left << MaSach;
        cout << setw(15) << left << TenSach;
        cout << setw(20) << left << TacGia;
        if (ChuyenNganh == 1)
        {
            cout << setw(20) << left << "Khoa hoc tu nhien";
        }
        else if (ChuyenNganh == 2)
        {
            cout << setw(20) << left << "Van hoc-Nghe thuat";
        }
        else if (ChuyenNganh == 3)
        {
            cout << setw(20) << left << "Dien tu vien thong";
        }
        else
        {
            cout << setw(20) << left << "Cong nghe thong tin";
        }
        cout << setw(30) << left << NamXB << endl;
    }
};

int Sach::MaSachBD = 10000;

class BangQL
{
public:
    friend class BanDoc;
    friend class Sach;

};

int main()
{
    vector<BanDoc> a;
    vector<Sach> b;
    int sobd;
    int sosach;

    cout << "Nhap so ban doc: "; cin >> sobd;
    cin.ignore();
    a.resize(sobd);
    for (int i = 0; i < sobd; i++)
    {
        cout << endl;
        cout << "Nhap ban doc thu " << i + 1 << ": " << endl;
        a[i].NhapBanDoc();
    }
    cout << endl;
    cout << setw(15) << left << "Ma ban doc";
    cout << setw(15) << left << "Ho ten";
    cout << setw(15) << left << "Dia chi";
    cout << setw(20) << left << "So dien thoai";
    cout << setw(20) << left << "Loai ban doc" << endl;
    for (int i = 0; i < sobd; i++)
    {
        a[i].XuatBanDoc();
    }

    cout << endl << "Nhap so sach: "; cin >> sosach;
    cin.ignore();
    b.resize(sosach);
    for (int i = 0; i < sosach; i++)
    {
        cout << endl;
        cout << "Nhap sach thu " << i + 1 << ": " << endl;
        b[i].NhapSach();
    }
    cout << endl;
    cout << setw(15) << left << "Ma sach";
    cout << setw(15) << left << "Ten sach";
    cout << setw(20) << left << "Tac gia";
    cout << setw(20) << left << "Chuyen nganh";
    cout << setw(30) << left << "Nam xuat ban" << endl;
    for (int i = 0; i < sosach; i++)
    {
        b[i].XuatSach();
    }
    return 0;
}
