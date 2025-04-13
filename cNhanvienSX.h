#include <iostream>
#include "NgayThangNam.h"
#include <limits> 
using namespace std;

class cNhanVienSX {
private:
    string MaNV;
    string HoTenNV;
    NgayThangNam NgaysinhNV;
    float SoSanPhamGiaCong;
    float DonGia;
    float Luong;

public:
    cNhanVienSX(string maNV = "", string hoTenNV = "", NgayThangNam ngaysinhNV = NgayThangNam(), float soSanPhamGiaCong = 0, float donGia = 0)
        : MaNV(maNV), HoTenNV(hoTenNV), NgaysinhNV(ngaysinhNV), SoSanPhamGiaCong(soSanPhamGiaCong), DonGia(donGia) {
        Luong = 0;
    }

    void Nhap() {
        cout << "Nhap ma nhan vien: ";
        cin >> MaNV;
        cin.ignore(); // Xóa ký tự newline

        do {
            cout << "Nhap ho ten nhan vien: ";
            getline(cin, HoTenNV);
            if (HoTenNV.empty()) {
                cout << "Ho ten khong duoc de trong. Vui long nhap lai!\n";
            }
        } while (HoTenNV.empty());

        cout << "Nhap ngay sinh:\n";
        NgaysinhNV.Nhap();

        cout << "Nhap so san pham gia cong: ";
        cin >> SoSanPhamGiaCong;
        cout << "Nhap don gia: ";
        cin >> DonGia;
    }

    void Xuat() {
        cout << "Ma nhan vien: " << MaNV << endl;
        cout << "Ho ten nhan vien: " << HoTenNV << endl;
        cout << "Ngay sinh: ";
        NgaysinhNV.Xuat();
        cout << "So san pham gia cong: " << SoSanPhamGiaCong << endl;
        // Nhập số sản phẩm
        do {
            cout << "Nhap so san pham gia cong: ";
            cin >> SoSanPhamGiaCong;
        
            if (cin.fail() || SoSanPhamGiaCong < 0) {
                cout << "Gia tri khong hop le. Vui long nhap mot so lon hon hoac bang 0!\n";
                cin.clear(); // Xóa trạng thái lỗi
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa dữ liệu sai trong bộ đệm
            }
        } while (cin.fail() || SoSanPhamGiaCong < 0);
        
        // Nhập đơn giá
        do {
            cout << "Nhap don gia: ";
            cin >> DonGia;
        
            if (cin.fail() || DonGia < 0) {
                cout << "Gia tri khong hop le. Vui long nhap mot so lon hon hoac bang 0!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail() || DonGia < 0);
    }

    float TinhLuong() {
        Luong = SoSanPhamGiaCong * DonGia;
        return Luong;
    }

    // Getters
    string GetMaNV() const { return MaNV; }
    string GetHoTenNV() const { return HoTenNV; }
    NgayThangNam GetNgaysinhNV() const { return NgaysinhNV; }
    float GetSoSanPhamGiaCong() const { return SoSanPhamGiaCong; }
    float GetDonGia() const { return DonGia; }
    float GetLuong() const { return Luong; }

    // Setters
    void SetMaNV(string maNV) { MaNV = maNV; }
    void SetHoTenNV(string hoTenNV) { HoTenNV = hoTenNV; }
    void SetNgaysinhNV(NgayThangNam ngaysinhNV) { NgaysinhNV = ngaysinhNV; }
    void SetSoSanPhamGiaCong(float soSanPhamGiaCong) { SoSanPhamGiaCong = soSanPhamGiaCong; }
    void SetDonGia(float donGia) { DonGia = donGia; }
    void SetLuong(float luong) { Luong = luong; }
};
