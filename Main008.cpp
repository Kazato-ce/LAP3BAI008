#include "cDSNhanVienSX.h"
#include <iostream>
using namespace std;
int main()
{
    cDSNhanVienSX ds; // Tạo đối tượng danh sách nhân viên
    ds.Nhap(); // Nhập danh sách nhân viên
    ds.Xuat(); // Xuất danh sách nhân viên
    ds.TongLuong(); // Tính tổng lương của tất cả nhân viên
    ds.NhanVienCoTuoiCaoNhat(); // Tìm và xuất thông tin nhân viên có lương thấp nhất
    ds.XapXepTheoLuongTangDan(); // Sắp xếp danh sách theo lương (chưa triển khai)
    return 0;
} // Kết thúc chương trình