#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

//Xay dung lop KhachHang
class KhachHang
{
private:
    static int MaKH_BD;
    int MaKH;
    string HoTen;
    string DiaChi;
    string SDT;
    int LoaiKH;
public:
    KhachHang()
    {
        MaKH = MaKH_BD++;
    }

    KhachHang(int makh, string hoten, string diachi, string sdt, int loaikh)
    {
        MaKH = makh;
        HoTen = hoten;
        DiaChi = diachi;
        SDT = sdt;
        LoaiKH = loaikh;
    }

    void NhapKH()
    {
        cout << "Ho ten: "; getline(cin, HoTen);
        cout << "Dia chi: "; getline(cin, DiaChi);
        cout << "So dien thoai: "; getline(cin, SDT);
        cout << "Cac loai khach hang" << endl;
        cout << "1.Mua le       2.Mua buon" << endl;
        cout << "Loai khach hang do la: "; cin >> LoaiKH;
        cin.ignore();
    }
    void XuatKH()
    {
        cout << setw(10) << left << MaKH;
        cout << setw(20) << left << HoTen;
        cout << setw(15) << left << DiaChi;
        cout << setw(20) << left << SDT;
        if (LoaiKH == 1)
        {
            cout << setw(20) << left << "Mua le" << endl;
        }
        else
        {
            cout << setw(20) << left << "Mua buon" << endl;
        }
    }

    void XuatDSKH()
    {
        cout << setw(10) << left << MaKH;
        cout << setw(15) << left << HoTen;
    }

    string getHoTen()
    {
        return HoTen;
    }
};

int KhachHang::MaKH_BD = 10000;

bool sapXepTenKhach(KhachHang a, KhachHang b)
{
    return a.getHoTen() < b.getHoTen();
}

//Xay dung lop MatHang
class MatHang
{
private:
    static int MaHang_BD;
    int MaHang;
    string TenHang;
    int NhomHang;
    int GiaBan;
public:
    MatHang()
    {
        MaHang = MaHang_BD++;
    }

    MatHang(int mahang, string tenhang, int nhomhang, int giaban)
    {
        MaHang = mahang;
        TenHang = tenhang;
        NhomHang = nhomhang;
        GiaBan = giaban;
    }

    void NhapHang()
    {
        cout << "Ten hang: "; getline(cin, TenHang);
        cout << "Cac loai nhom hang" << endl;
        cout << "1. Hang thoi trang     2.Hang tieu dung    3.Hang dien may     4.Hang gia dung" << endl;
        cout << "Nhom hang nay la: "; cin >> NhomHang;
        cout << "Gia ban: "; cin >> GiaBan;
        cin.ignore();
    }

    void XuatHang()
    {
        cout << setw(10) << left << MaHang;
        cout << setw(15) << left << TenHang;
        if (NhomHang == 1)
        {
            cout << setw(20) << left << "Hang thoi trang";
        }
        else if (NhomHang == 2)
        {
            cout << setw(20) << left << "Hang tieu dung";
        }
        else if (NhomHang == 3)
        {
            cout << setw(20) << left << "Hang dien may";
        }
        else
        {
            cout << setw(20) << left << "Hang gia dung";
        }
        cout << setw(30) << left << GiaBan << endl;
    }

    void XuatDSHang()
    {
        cout << setw(30) << left << TenHang;
        if (NhomHang == 1)
        {
            cout << setw(20) << left << "Hang thoi trang";
        }
        else if (NhomHang == 2)
        {
            cout << setw(20) << left << "Hang tieu dung";
        }
        else if (NhomHang == 3)
        {
            cout << setw(20) << left << "Hang dien may";
        }
        else if (NhomHang == 4)
        {
            cout << setw(20) << left << "Hang gia dung";
        }
        cout << setw(20) << left << GiaBan;
    }
    
    void HoaDonMH()
    {
        cout << setw(15) << left << TenHang;
        if (NhomHang == 1)
        {
            cout << setw(20) << left << "Hang thoi trang";
        }
        else if (NhomHang == 2)
        {
            cout << setw(20) << left << "Hang tieu dung";
        }
        else if (NhomHang == 3)
        {
            cout << setw(20) << left << "Hang dien may";
        }
        else if (NhomHang == 4)
        {
            cout << setw(20) << left << "Hang gia dung";
        }
    }

    string getTenHang()
    {
        return TenHang;
    }
};

int MatHang::MaHang_BD = 1000;

//Sap xep ten hang
bool sapXepTenHang(MatHang a, MatHang b)
{
    return a.getTenHang() < b.getTenHang();
}

class BangDSMua
{
private:
    int SoLuong;
public:
    friend class KhachHang;
    friend class MatHang;
    KhachHang DSKH;
    MatHang DSMH;

    //Ham nhap DS mua
    void NhapDSMua(KhachHang kh, MatHang mh)
    {
        cout << "So luong hang: "; cin >> SoLuong;
    }

    //Ham xuat DS mua
    void XuatDSMua()
    {
        if (SoLuong <= 10)
        {
            cout << setw(10) << left << "Ma KH";
            cout << setw(15) << left << "Ho ten";
            cout << setw(30) << left << "Ten hang";
            cout << setw(20) << left << "Loai hang";
            cout << setw(20) << left << "So luong" << endl;
            DSKH.XuatDSKH();
            DSMH.XuatDSHang();
            cout << setw(20) << left << SoLuong << endl;
        }
        else
        {
            cout << "Vuot qua so luong mat hang mua cho phep!" << endl;
        }
    }

    void DSHoaDon()
    {
        cout << setw(20) << left << SoLuong;
    }
};

void TinhTien(int SoLuong, int GiaBan)
{
    cout << setw(15) << left << SoLuong * GiaBan << endl;
}

int main()
{
    vector<KhachHang> a;
    vector<MatHang> b;

    int soKH;
    cout << "Nhap so khach hang: "; cin >> soKH;
    cin.ignore();
    a.resize(soKH);

    //Nhap thong tin khach hang
    for (int i = 0; i < soKH; i++)
    {
        cout << endl;
        cout << "Khach hang thu " << i + 1 << ":" << endl;
        a[i].NhapKH();
    }
    cout << endl;

    //Xuat thong tin khach hang
    cout << setw(10) << left << "Ma KH";
    cout << setw(20) << left << "Ten khach";
    cout << setw(15) << left << "Dia chi";
    cout << setw(20) << left << "So dien thoai";
    cout << setw(20) << left << "Loai khach" << endl;
    for (int i = 0; i < soKH; i++)
    {
        a[i].XuatKH();
    }

    int soMH;
    cout << "Nhap so mat hang: "; cin >> soMH;
    cin.ignore();
    b.resize(soMH);

    //Nhap thong tin mat hang
    for (int i = 0; i < soMH; i++)
    {
        cout << endl;
        cout << "Mat hang thu " << i + 1 << ":" << endl;
        b[i].NhapHang();
    }
    cout << endl;

    //Xuat thong tin mat hang
    cout << setw(10) << left << "Ma MH";
    cout << setw(15) << left << "Ten hang";
    cout << setw(20) << left << "Nhom hang";
    cout << setw(30) << left << "Gia ban" << endl;
    for (int i = 0; i < soMH; i++)
    {
        b[i].XuatHang();
    }

    vector<BangDSMua> c(soKH * soMH);
    cout << "In ra bang danh sach mua hang" << endl;
    cout << "Bam phim 1. In" << endl;
    cout << "Bam phim 0. Huy" << endl;
    int run = 0, lc;

    //Xuat danh sach khach mua hang
    for (int i = 0; i < soKH; i++)
    {
        for (int j = 0; j < soMH; j++)
        {
            cout << "Lua chon cua ban: "; cin >> lc;
            if (lc == 1)
            {
                cout << endl;
                cout << "Khach hang thu " << i + 1 << ": " << endl;
                cout << setw(10) << left << "Ma KH";
                cout << setw(20) << left << "Ten khach";
                cout << setw(15) << left << "Dia chi";
                cout << setw(20) << left << "So dien thoai";
                cout << setw(20) << left << "Loai khach" << endl;
                a[i].XuatKH();
                cout << "Mat hang khach do mua " << endl;
                cout << setw(10) << left << "Ma MH";
                cout << setw(15) << left << "Ten hang";
                cout << setw(20) << left << "Nhom hang";
                cout << setw(30) << left << "Gia ban" << endl;
                b[j].XuatHang();
                c[run].NhapDSMua(a[i], b[j]);
                c[run].XuatDSMua();
                run++;
            }
        }
    }

    //Sap xep ho ten khach hang
    sort(a.begin(), a.end(), sapXepTenKhach);
    cout << "\nSau khi sap xep ten khach hang: " << endl;
    cout << setw(10) << left << "Ma KH";
    cout << setw(20) << left << "Ten khach";
    cout << setw(15) << left << "Dia chi";
    cout << setw(20) << left << "So dien thoai";
    cout << setw(20) << left << "Loai khach" << endl;
    for (int i = 0; i < soKH; i++)
    {
        a[i].XuatKH();
    }

    //Sap xep ten mat hang
    sort(b.begin(), b.end(), sapXepTenHang);
    cout << "\nSau khi sap xep ten hang: " << endl;
    cout << setw(10) << left << "Ma MH";
    cout << setw(15) << left << "Ten hang";
    cout << setw(20) << left << "Nhom hang";
    cout << setw(30) << left << "Gia ban" << endl;
    for (int i = 0; i < soMH; i++)
    {
        b[i].XuatHang();
    }

    /*for (int i = 0; i < soKH; i++)
    {
        for (int j = 0; j < soMH; j++)
        {

        }
    }
    /*for (int i = 0; i<soKH; i++)
        Lap hoc don
            - Ma khach
            - Ten khach
            - Ten hang
            - Nhom hang
            - Gia ban
    }*/

    return 0;
}