#include <stdio.h>
#include <string.h>

typedef struct {
    char maHang[10];     // M� h�ng
    char tenHang[50];    // T�n h�ng
    float gia;           // Gi� h�ng
    int soLuong;         // S? l??ng h�ng
} MatHang;

void themMoi(MatHang *danhSach, int *soLuong) {
    // H�m th�m m?i m?t m?t h�ng v�o danh s�ch
    printf("Nhap ma hang: ");
    scanf("%s", danhSach[*soLuong].maHang);
    printf("Nhap ten hang: ");
    scanf(" %[^\n]", danhSach[*soLuong].tenHang);
    printf("Nhap gia: ");
    scanf("%f", &danhSach[*soLuong].gia);
    printf("Nhap so luong: ");
    scanf("%d", &danhSach[*soLuong].soLuong);
    (*soLuong)++;
}

void sua(MatHang *danhSach, int soLuong) {
    // H�m s?a th�ng tin m?t m?t h�ng
    char maHang[10];
    printf("Nhap ma hang can sua: ");
    scanf("%s", maHang);
    for(int i = 0; i < soLuong; i++) {
        if(strcmp(danhSach[i].maHang, maHang) == 0) {
            printf("Nhap ten hang moi: ");
            scanf(" %[^\n]", danhSach[i].tenHang);
            printf("Nhap gia moi: ");
            scanf("%f", &danhSach[i].gia);
            printf("Nhap so luong moi: ");
            scanf("%d", &danhSach[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay mat hang co ma %s\n", maHang);
}

void xoa(MatHang *danhSach, int *soLuong) {
    // H�m x�a m?t m?t h�ng kh?i danh s�ch
    char maHang[10];
    printf("Nhap ma hang can xoa: ");
    scanf("%s", maHang);
    for(int i = 0; i < *soLuong; i++) {
        if(strcmp(danhSach[i].maHang, maHang) == 0) {
            for(int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            (*soLuong)--;
            printf("Da xoa mat hang co ma %s\n", maHang);
            return;
        }
    }
    printf("Khong tim thay mat hang co ma %s\n", maHang);
}

void timKiem(MatHang *danhSach, int soLuong) {
    // H�m t�m ki?m m?t h�ng theo m� h�ng
    char maHang[10];
    printf("Nhap ma hang can tim: ");
    scanf("%s", maHang);
    for(int i = 0; i < soLuong; i++) {
        if(strcmp(danhSach[i].maHang, maHang) == 0) {
            printf("Ma hang: %s\n", danhSach[i].maHang);
            printf("Ten hang: %s\n", danhSach[i].tenHang);
            printf("Gia: %.2f\n", danhSach[i].gia);
            printf("So luong: %d\n", danhSach[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay mat hang co ma %s\n", maHang);
}

void sapXep(MatHang *danhSach, int soLuong) {
    // H�m s?p x?p m?t h�ng theo gi� t?ng d?n
    for(int i = 0; i < soLuong - 1; i++) {
        for(int j = i + 1; j < soLuong; j++) {
            if(danhSach[i].gia > danhSach[j].gia) {
                MatHang temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Da sap xep xong.\n");
}

void luuFile(MatHang *danhSach, int soLuong, char *fileName) {
    // H�m l?u danh s�ch m?t h�ng v�o file
    FILE *file = fopen(fileName, "w");
    if (file != NULL) {
        for(int i = 0; i < soLuong; i++) {
            fprintf(file, "%s %s %.2f %d\n", danhSach[i].maHang, danhSach[i].tenHang, danhSach[i].gia, danhSach[i].soLuong);
        }
        fclose(file);
        printf("Da luu du lieu vao file %s\n", fileName);
    } else {
        printf("Khong the mo file %s\n", fileName);
    }
}

void thongKe(MatHang *danhSach, int soLuong) {
    // H�m th?ng k� t?ng gi� tr? h�ng h�a trong kho
    float tongGiaTri = 0;
    for(int i = 0; i < soLuong; i++) {
        tongGiaTri += danhSach[i].gia * danhSach[i].soLuong;
    }
    printf("Tong gia tri hang hoa trong kho: %.2f\n", tongGiaTri);
}

int main() {
    MatHang danhSach[100];
    int soLuong = 0;
    int luaChon;
    char fileName[] = "danhSachMatHang.txt";

    do {
        // Menu ?? ng??i d�ng ?i?u khi?n ch??ng tr�nh
        printf("1. Them moi mat hang\n");
        printf("2. Sua thong tin mat hang\n");
        printf("3. Xoa mat hang\n");
        printf("4. Tim kiem mat hang\n");
        printf("5. Sap xep mat hang\n");
        printf("6. Luu danh sach vao file\n");
        printf("7. Thong ke gia tri hang hoa\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

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
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while(luaChon != 0);

    return 0;
}

