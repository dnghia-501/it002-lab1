#include <iostream>
#include <string>
#include <cmath>

using namespace std;
struct ngay {
    int d, m, y;
};
bool namnhuan(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
int songaytrongnam(int m, int y)
{
    switch (m)
    { 
    case 4 : case 6 : case 9 : case 11 :
        return 30;
    case 2 :
        return namnhuan(y) ? 29 : 28;
    default : return 31;
    }
}
ngay ngayketiep(ngay ht)
{
    ngay kt = ht;
    kt.d++;
    if(kt.d > songaytrongnam(ht.m, ht.y))
    { 
        kt.d = 1;
        kt.m++;
        if(kt.m>12)
        {
            kt.m = 1;
            kt.y++;
        }
    }
    return kt;
}
int main()
{
    ngay ht;
    cin >> ht.d >> ht.m >> ht.y;
    ngay ngaykt = ngayketiep(ht);
    cout << "ngay ke tiep : " << ngaykt.d << "/" << ngaykt.m << "/" << ngaykt.y << endl;

}

