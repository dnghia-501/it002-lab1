#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct hs {
    string hoten;
    double toan;
    double van;
    double dtb;
};
void input(hs &hs)
{
    cout << "nhaphoten" << endl;
    getline(cin, hs.hoten);
    cin >> hs.toan;
    cin >> hs.van;
}
void diemtrungbinh(hs& hs) 
{
    hs.dtb = (hs.toan + hs.van) / 2.0;
}
int main()
{
    hs hs;
    input(hs);
    diemtrungbinh(hs);
    cout << "Hoc sinh: " << hs.hoten << " | Diem TB: " << hs.dtb << endl;

    return 0;
}

