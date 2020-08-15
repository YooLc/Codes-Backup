#include <iostream>
#include <cstdio>
using namespace std;
typedef __int128 LL;
inline LL rd()
{
    LL t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline void print(__int128 x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar((x % 10) + '0');
}
const int MAXN = 1e6 + 5;
LL n, MOD, arr[MAXN], tzz[MAXN], pts[MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1982.in", "r", stdin);
#endif
    n = rd(); MOD = rd();
    for (int i = 1; i <= n; ++i) 
    {
        arr[i] = rd();
        tzz[i] = max(arr[i], tzz[i - 1] + arr[i]); 
        // 特征值是最大连续子段和，可惜此时 tzz 求的是必须以当前为结尾的字段和，是状态量
    }
    for (int i = 2; i <= n; ++i) tzz[i] = max(tzz[i], tzz[i - 1]);
    pts[1] = tzz[1]; // 第一个小朋友的分数是他的特征值
    LL mx = pts[1] + tzz[1];
    for (int i = 2; i <= n; ++i)
    {
        mx = max(mx, pts[i - 1] + tzz[i - 1]);
        pts[i] = mx; 
        // 其它小朋友的分数为排在他前面的所有小朋友中（不包括他本人），小朋友分数加上其特征值的最大值
    }
    mx = max(mx, pts[1]);
    if (mx >= 0) print(mx % MOD);
    else putchar('-'), print((-mx % MOD));
    return 0;
}