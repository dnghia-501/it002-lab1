#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct phanso {
    int tu;
    int mau;
};

int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void input(phanso& ps) {
    cin >> ps.tu;
    do {
        cin >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so phai khac 0. \n";
        }
    } while (ps.mau == 0);
}

void output(phanso ps) {
    if (ps.mau == 1) cout << ps.tu;
    else if (ps.tu == 0) cout << 0;
    else cout << ps.tu << "/" << ps.mau;
}


void rutgon(phanso& ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

phanso timphansolonnhat(phanso ps1, phanso ps2) {
    float giatri1 = (float)ps1.tu / ps1.mau;
    float giatri2 = (float)ps2.tu / ps2.mau;
    return (giatri1 > giatri2) ? ps1 : ps2;
}

phanso tong(phanso ps1, phanso ps2) {
    phanso kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutgon(kq);
    return kq;
}

phanso hieu(phanso ps1, phanso ps2) {
    phanso kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutgon(kq);
    return kq;
}

phanso tich(phanso ps1, phanso ps2) {
    phanso kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutgon(kq);
    return kq;
}

phanso thuong(phanso ps1, phanso ps2) {
    phanso kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    rutgon(kq);
    return kq;
}
int main()
{
    phanso ps1, ps2;
    input (ps1);
    input(ps1);
    rutgon(ps1);
    rutgon(ps2);
    cout << "phan so rut gon" << endl;
    output(ps1); cout << endl;
    output(ps2); cout << endl;
    cout << "phan so lon nhat" << endl;
    output(timphansolonnhat(ps1, ps2)); cout << endl;
    cout << "tong, hieu, tich, thuong hai phan so" << endl;
    output(tong(ps1, ps2)); cout << endl;
    output(hieu(ps1, ps2)); cout << endl;
    output(tich(ps1, ps2)); cout << endl;
    output(thuong(ps1, ps2)); cout << endl;
    return 0;
}

