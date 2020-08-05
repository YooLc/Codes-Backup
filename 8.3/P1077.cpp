#include <iostream>
#include <cstdio>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
const int MAXN = 105, MOD = 1000007;
int a[MAXN], f[MAXN][MAXN];
// f[i][j] 表示 前 i 种花，一共摆 j 盆的方案数
int main() 
{
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, m;
    n = rd(); m = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    for (int i = 1; i <= n; ++i) f[i][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // 新增一盆 1. 第 i 类花多种 1 盆， 2. 前 i 类花已经种了这么多
            f[i][j] = f[i - 1][j];
            if (j )
        }
    }
    printf("%d", f[n][m]);
    return 0;
}