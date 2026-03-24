#include <iostream>
#include <string>
#include <cctype> 
using namespace std;
struct HocSinh {
    string hoten;
    double toan;
    double van;
    double dtb;
};
bool kiemtrahoten(string ten) {
    if (ten.empty()) return false;

    bool cocach = false;
    for (int i = 0; i < ten.length(); i++) {
        char c = ten[i];

        if (!isalpha(c) && !isspace(c)) {
            return false;
        }

        if (isspace(c)) {
            cocach = true;
        }
        else {
            if (i == 0 || ten[i - 1] == ' ') {
                if (!isupper(c)) return false;
            }
            else {
               if (!islower(c)) return false;
            }
        }
    }
    return cocach;
}

void input(HocSinh& hs) {
    do {
        cout << "Nhap ho ten (VD: Nguyen Van A): ";
        getline(cin, hs.hoten);

        if (!kiemtrahoten(hs.hoten)) {
            cout << "Loi: Ho ten chua hop le " << endl;
        }
    } while (!kiemtrahoten(hs.hoten));

    cout << "Nhap diem Toan: ";
    cin >> hs.toan;

    cout << "Nhap diem Van: ";
    cin >> hs.van;
}
void diemtrungbinh(HocSinh& hs) {
    hs.dtb = (hs.toan + hs.van) / 2.0;
}

int main() {
    HocSinh hs; 

    input(hs);
    diemtrungbinh(hs);
    cout << "Hoc sinh: " << hs.hoten << " | Diem TB: " << hs.dtb << endl;

    return 0;
}