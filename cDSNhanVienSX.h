#include "cNhanvienSX.h"
#include <iostream>
#include <iomanip> 
using namespace std;
class cDSNhanVienSX
{
private:
    cNhanVienSX* dsNV; // Con trỏ đến mảng động chứa danh sách nhân viên
    int n; // Số lượng nhân viên trong danh sách
public:
    cDSNhanVienSX(int n = 0) : n(n)
    {
        dsNV = new cNhanVienSX[n]; // Cấp phát bộ nhớ cho mảng động
    }
    
    ~cDSNhanVienSX()
    {
        delete[] dsNV; // Giải phóng bộ nhớ khi không còn sử dụng
    }
    
    void Nhap()
    {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        dsNV = new cNhanVienSX[n]; // Cấp phát lại bộ nhớ nếu số lượng nhân viên thay đổi
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
            dsNV[i].Nhap(); // Nhập thông tin từng nhân viên
        }
    }
    void Xuat() {
        cout << "\n================ DANH SACH NHAN VIEN ================\n";
        cout << left
             << setw(10) << "Ma NV"
             << setw(20) << "Ho Ten"
             << setw(12) << "Ngay Sinh"
             << setw(10) << "So SP"
             << setw(10) << "Don Gia"
             << setw(12) << "Luong"
             << endl;
    
        cout << string(74, '-') << endl;
    
        for (int i = 0; i < n; i++) {
            cout << left
                 << setw(10) << dsNV[i].GetMaNV()
                 << setw(20) << dsNV[i].GetHoTenNV();
    
            // In ngày sinh: lấy từ đối tượng NgayThangNam
            NgayThangNam ns = dsNV[i].GetNgaysinhNV();
            cout << setw(12)
                 << ( (ns.GetNgay() < 10 ? "0" : "") + to_string(ns.GetNgay()) + "/" +
                      (ns.GetThang() < 10 ? "0" : "") + to_string(ns.GetThang()) + "/" +
                      to_string(ns.GetNam()) );
    
            cout << setw(10) << dsNV[i].GetSoSanPhamGiaCong()
                 << setw(10) << dsNV[i].GetDonGia()
                 << setw(12) << fixed << setprecision(2) << dsNV[i].TinhLuong()
                 << endl;
        }
    }
    
    void NhanVienCoLuongThapNhat()
    {
        if (n == 0)
        {
            cout << "Khong co nhan vien trong danh sach." << endl;
            return;
        }
        cNhanVienSX nvThapNhat = dsNV[0]; // Giả định nhân viên đầu tiên có lương thấp nhất
        for (int i = 1; i < n; i++)
        {
            if (dsNV[i].GetLuong() < nvThapNhat.GetLuong())
            {
                nvThapNhat = dsNV[i]; // Cập nhật nhân viên có lương thấp nhất
            }
        }
        cout << "Nhan vien co luong thap nhat:" << endl;
        nvThapNhat.Xuat(); // Xuất thông tin nhân viên có lương thấp nhất
    }
    void TongLuong()
    {
        float tongLuong = 0;
        for (int i = 0; i < n; i++)
        {
            tongLuong += dsNV[i].GetLuong(); // Tính tổng lương của tất cả nhân viên
        }
        cout << "Tong luong cua tat ca nhan vien: " << tongLuong << endl;
    }
    void NhanVienCoTuoiCaoNhat()
    {
        if (n == 0)
        {
            cout << "Khong co nhan vien trong danh sach." << endl;
            return;
        }
        cNhanVienSX nvCaoNhat = dsNV[0]; // Giả định nhân viên đầu tiên có tuổi cao nhất
        for (int i = 1; i < n; i++)
        {
            if (dsNV[i].GetNgaysinhNV().GetNam() < nvCaoNhat.GetNgaysinhNV().GetNam())
            {
                nvCaoNhat = dsNV[i]; // Cập nhật nhân viên có tuổi cao nhất
            }
        }
        cout << "Nhan vien co tuoi cao nhat:" << endl;
        nvCaoNhat.Xuat(); // Xuất thông tin nhân viên có tuổi cao nhất
    }
    void XapXepTheoLuongTangDan()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (dsNV[i].GetLuong() > dsNV[j].GetLuong())
                {
                    cNhanVienSX temp = dsNV[i];
                    dsNV[i] = dsNV[j];
                    dsNV[j] = temp; // Hoán đổi vị trí của hai nhân viên
                }
            }
        }
        cout << "Danh sach nhan vien sau khi sap xep theo luong tang dan:" << endl;
        Xuat(); // Xuất danh sách nhân viên đã được sắp xếp
    }
};