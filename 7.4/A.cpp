#include <iostream>
#include <cstdio>
#include <cstring>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
const int MAXN = 1055;
int a[MAXN];
inline void solve()
{
    int n, cnt = 0;
    n = rd();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rd();
        if (i > 1 && a[i] - a[i - 1] >= 0) cnt++;
    }
    if (cnt > (n - 1) / 2)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] >= a[i - 1] && -a[i] <= a[i - 1])
                a[i] = -a[i], cnt--;
            if (cnt == (n - 1) / 2) break;
        }
    }
    else if (cnt < (n - 1) / 2)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] <= a[i - 1] && -a[i] >= a[i - 1])
                a[i] = -a[i], cnt++;
            if (cnt == (n - 1) / 2) break;
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n');
}
int main() 
{
    // Why life is soooo hard? :/
    int T;
    T = rd();
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}