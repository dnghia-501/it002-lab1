#include <iostream>
using namespace std;

struct ngay {
    int d, m, y;
};
bool lanamnhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
int songaytrongthang(int m, int y) {
    switch (m) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return lanamnhuan(y) ? 29 : 28;
    default:
        return 31;
    }
}

bool kiemtrangayhople(ngay ng) {
    if (ng.y <= 0) return false;
    if (ng.m < 1 || ng.m > 12) return false;
    if (ng.d < 1 || ng.d > songaytrongthang(ng.m, ng.y)) return false;

    return true;
}

void nhapngay(ngay& ng) {
    do {
        cin >> ng.d >> ng.m >> ng.y;

        if (!kiemtrangayhople(ng)) {
            cout << "Loi: Ngay thang nam khong hop le! " << endl;
        }
    } while (!kiemtrangayhople(ng));
}

ngay timngayketiep(ngay ht) {
    ngay kt = ht;
    kt.d++; 
    if (kt.d > songaytrongthang(ht.m, ht.y)) {
        kt.d = 1; 
        kt.m++;  

      
        if (kt.m > 12) {
            kt.m = 1; 
            kt.y++;   
        }
    }
    return kt;
}

void xuatngay(ngay ng) {
    cout << ng.d << "/" << ng.m << "/" << ng.y;
}

int main() {
    ngay ngayhientai;
    nhapngay(ngayhientai);
    ngay ngaytiep = timngayketiep(ngayhientai);
    cout << "Ngay ke tiep la: ";
    xuatngay(ngaytiep);
    cout << endl;

    return 0;
}