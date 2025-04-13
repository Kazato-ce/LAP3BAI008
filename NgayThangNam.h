#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int ngay;
    int thang;
    int nam;

    // Hàm kiểm tra năm nhuận
    bool LaNamNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    // Hàm lấy số ngày tối đa của một tháng
    int SoNgayTrongThang(int thang, int nam) {
        switch (thang) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return LaNamNhuan(nam) ? 29 : 28;
            default:
                return 0; // Tháng không hợp lệ
        }
    }

public:
    NgayThangNam(int n = 0, int t = 0, int y = 0) : ngay(n), thang(t), nam(y) {}

    void Nhap() {
        do {
            cout << "Nhap nam: ";
            cin >> nam;
            if (cin.fail() || nam <= 0) {
                cout << "Nam khong hop le. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || nam <= 0);

        do {
            cout << "Nhap thang (1-12): ";
            cin >> thang;
            if (cin.fail() || thang < 1 || thang > 12) {
                cout << "Thang khong hop le. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || thang < 1 || thang > 12);

        int maxNgay = SoNgayTrongThang(thang, nam);

        do {
            cout << "Nhap ngay (1-" << maxNgay << "): ";
            cin >> ngay;
            if (cin.fail() || ngay < 1 || ngay > maxNgay) {
                cout << "Ngay khong hop le. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || ngay < 1 || ngay > maxNgay);
    }

    void Xuat() {
        cout << "Ngay: " << (ngay < 10 ? "0" : "") << ngay << "/"
             << (thang < 10 ? "0" : "") << thang << "/"
             << nam << endl;
    }

    int GetNam() const { return nam; }
    int GetThang() const { return thang; }
    int GetNgay() const { return ngay; }
};
