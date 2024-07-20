#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void themMoi(MatHang *danhSach, int *soLuong);
void sua(MatHang *danhSach, int soLuong);
void xoa(MatHang *danhSach, int *soLuong);
void timKiem(MatHang *danhSach, int soLuong);
void sapXep(MatHang *danhSach, int soLuong);
void luuFile(MatHang *danhSach, int soLuong, char *fileName);
void thongKe(MatHang *danhSach, int soLuong);

struct MatHang {
    string maHang;     // Mã hàng
    string tenHang;    // Tên hàng
    float gia;         // Giá hàng
    int soLuong;       // Số lượng hàng
};

void themMoi(MatHang *danhSach, int *soLuong) {
    // Hàm thêm mới mặt hàng vào danh sách
    cout << "Nhap ma hang: ";
    cin >> danhSach[*soLuong].maHang;
    cout << "Nhap ten hang: ";
    cin.ignore();
    getline(cin, danhSach[*soLuong].tenHang);
    cout << "Nhap gia: ";
    cin >> danhSach[*soLuong].gia;
    cout << "Nhap so luong: ";
    cin >> danhSach[*soLuong].soLuong;
    (*soLuong)++;
}

void sua(MatHang *danhSach, int soLuong) {
    // Hàm sửa thông tin mặt hàng
    string maHang;
    cout << "Nhap ma hang can sua: ";
    cin >> maHang;
    for(int i = 0; i < soLuong; i++) {
        if(maHang == danhSach[i].maHang) {
            cout << "Nhap ten hang moi: ";
            cin.ignore();
            getline(cin, danhSach[i].tenHang);
            cout << "Nhap gia moi: ";
            cin >> danhSach[i].gia;
            cout << "Nhap so luong moi: ";
            cin >> danhSach[i].soLuong;
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void xoa(MatHang *danhSach, int *soLuong) {
    // Hàm xóa mặt hàng khỏii danh sách
    string maHang;
    cout << "Nhap ma hang can xoa: ";
    cin >> maHang;
    for(int i = 0; i < *soLuong; i++) {
        if(maHang == danhSach[i].maHang) {
            for(int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            (*soLuong)--;
            cout << "Da xoa mat hang co ma " << maHang << endl;
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void timKiem(MatHang *danhSach, int soLuong) {
    // Hàm tìm kiếm mặt hàng theo mã hàng
    string maHang;
    cout << "Nhap ma hang can tim: ";
    cin >> maHang;
    for(int i = 0; i < soLuong; i++) {
        if(maHang == danhSach[i].maHang) {
            cout << "Ma hang: " << danhSach[i].maHang << endl;
            cout << "Ten hang: " << danhSach[i].tenHang << endl;
            cout << "Gia: " << danhSach[i].gia << endl;
            cout << "So luong: " << danhSach[i].soLuong << endl;
            return;
        }
    }
    cout << "Khong tim thay mat hang co ma " << maHang << endl;
}

void sapXep(MatHang *danhSach, int soLuong) {
    // Hàm s?p x?p m?t hàng theo giá t?ng d?n
    for(int i = 0; i < soLuong - 1; i++) {
        for(int j = i + 1; j < soLuong; j++) {
            if(danhSach[i].gia > danhSach[j].gia) {
                MatHang temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    cout << "Da sap xep xong." << endl;
}

void luuFile(MatHang *danhSach, int soLuong, char *fileName) {
    // Hàm l?u danh sách m?t hàng vào file
    ofstream file(fileName);
    if (file.is_open()) {
        for(int i = 0; i < soLuong; i++) {
            file << danhSach[i].maHang << " "
                 << danhSach[i].tenHang << " "
                 << danhSach[i].gia << " "
                 << danhSach[i].soLuong << endl;
        }
        file.close();
        cout << "Da luu du lieu vao file " << fileName << endl;
    } else {
        cout << "Khong the mo file " << fileName << endl;
    }
}

void thongKe(MatHang *danhSach, int soLuong) {
    // Hàm thống kê tổng giá trị hàng hóa trong kho
    float tongGiaTri = 0;
    for(int i = 0; i < soLuong; i++) {
        tongGiaTri += danhSach[i].gia * danhSach[i].soLuong;
    }
    cout << "Tong gia tri hang hoa trong kho: " << tongGiaTri << endl;
}

int main() {
    MatHang danhSach[100];
    int soLuong = 0;
    int luaChon;
    char fileName[] = "danhSachMatHang.txt";
    do {
        // Menu người dùng
        cout << "1. Them moi mat hang\n";
        cout << "2. Sua thong tin mat hang\n";
        cout << "3. Xoa mat hang\n";
        cout << "4. Tim kiem mat hang\n";
        cout << "5. Sap xep mat hang\n";
        cout << "6. Luu danh sach vao file\n";
        cout << "7. Thong ke gia tri hang hoa\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch(luaChon) {
            case 1:
                themMoi(danhSach, &soLuong);
                break;
            case 2:
                sua(danhSach, soLuong);
                break;
            case 3:
                xoa(danhSach, &soLuong);
                break;
            case 4:
                timKiem(danhSach, soLuong);
                break;
            case 5:
                sapXep(danhSach, soLuong);
                break;
            case 6:
                luuFile(danhSach, soLuong, fileName);
                break;
            case 7:
                thongKe(danhSach, soLuong);
                break;
            case 0:
                cout << "Thoat chuong trinh\n";
                break;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while(luaChon != 0);
    return 0;
}

