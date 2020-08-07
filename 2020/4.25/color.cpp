#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline bool solve()
{
    int p1, p2, k;
    p1 = rd(); p2 = rd(); k = rd();
    if (p1 > p2) swap(p1, p2);
    // p1 <= p2
    if (k == 1) return false; // k = 1 时不存在 
    // if(p2 % p1 == 0) cout <<"%%%" <<endl;
    int t = __gcd(p1, p2);
    p1 /= t; p2 /= t;
    if (p2 % p1 == 0) return (p2 / p1) <= k;
    else 
    {
        return ((p2 - 2) / p1) + 1 < k;
    }
}
int main()
{
    // freopen("color.in", "r", stdin);
    // freopen("color.out", "w", stdout);
    int T;
    T = rd();
    for (int i = 1; i <= T; ++i) puts(solve() ? "OBEY" : "REBEL");
    return 0;
}