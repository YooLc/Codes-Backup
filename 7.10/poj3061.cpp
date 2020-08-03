#include <iostream>
#include <cstdio>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e5 + 50, INF = 1 << 30;
int a[MAXN];
using namespace std;
inline void solve()
{
    int n, s;
    n = rd(); s = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    int fpos = 1, lpos = 0, sum = 0, ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        lpos++;
        sum += a[lpos];
        if (sum >= s) ans = min(ans, lpos - fpos + 1);
        while (fpos < lpos && sum - a[fpos] >= s) 
        {
            ans = min(ans, lpos - fpos + 1);
            sum -= a[fpos], fpos++;
        }
        if (sum >= s) ans = min(ans, lpos - fpos + 1);
    }
    if (ans == INF) ans = 0;
    printf("%d\n", ans);
}
int main() 
{
    int T = rd();
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}