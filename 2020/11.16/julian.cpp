#include <iostream>
#include <cstdio>
using namespace std;
const int daysOfMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int magicJ = 1461; // four years in Julian calender
const int base = 2299161; // Gregorian calendar began here
const int magicG = 146097; // four hundred years in Gregorian calender
typedef long long LL;
inline bool isLeap(int year)
{
    if (year <= 1582) // Julian calendar
    {
        if (year < 0 && year % 4 == -1) return true; // BC
        else if (year > 0 && year % 4 == 0) return true;
        else return false;
    }
    else // Gregorian calendar
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
        else return false;
    }
}
inline void calcJulian(int julianDate)
{
    // starts from 4713.1.1 BC, 4713 is a leap year.
    int year = -4713;
    while (julianDate > magicJ)
    {
        julianDate -= magicJ;
        year += 4;
    }
    if (year >= 0) year++;
    while (julianDate > (isLeap(year) ? 366 : 365))
    {
        julianDate -= isLeap(year) ? 366 : 365;
        year++;
        if (year == 0) year++;
    }
    bool leap = isLeap(year);
    for (int i = 1; i <= 12; ++i)
    {
        if (julianDate > daysOfMonth[leap][i])
            julianDate -= daysOfMonth[leap][i];
        else 
        {
            if (year < 0) printf("%d %d %d BC\n", julianDate, i, -year);
            else printf("%d %d %d\n", julianDate, i, year);
            break;
        }
    }
    return;
}
inline void calcGregorian(LL gregorianDate)
{
    // starts from 1582.10.15
    int remain = 17 + 30 + 31;
    if (gregorianDate <= remain)
    {
        gregorianDate += 14;
        for (int i = 10; i <= 12; ++i)
        {
            if (gregorianDate > daysOfMonth[0][i])
                gregorianDate -= daysOfMonth[0][i];
            else { printf("%lld %d %d\n", gregorianDate, i, 1582); return; }
        }
    }
    gregorianDate -= remain;
    LL year = 1583; LL rMagic = magicG, power = 400; // realMagic!
    while (gregorianDate > rMagic * 10) rMagic *= 10, power *= 10;
    while (gregorianDate > rMagic)
    {
        gregorianDate -= rMagic;
        year += power;
        while (gregorianDate < rMagic && rMagic > magicG)
            rMagic /= 10, power /= 10;
    }
    while (gregorianDate > (isLeap(year) ? 366 : 365))
    {
        gregorianDate -= isLeap(year) ? 366 : 365;
        year++;
    }
    bool leap = isLeap(year);
    for (int i = 1; i <= 12; ++i)
    {
        if (gregorianDate > daysOfMonth[leap][i])
            gregorianDate -= daysOfMonth[leap][i];
        else
        {
            printf("%lld %d %lld\n", gregorianDate, i, year);
            break;
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("julian10.in", "r", stdin);
    freopen("P7075_2.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        LL day;
        scanf("%lld", &day);
        day++;
        if (day <= base) calcJulian(day);
        else calcGregorian(day - base);
    }
    return 0;
}