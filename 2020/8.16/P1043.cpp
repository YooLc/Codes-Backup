#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MAXN = 55, MAXM = 11, MOD = 10, INF = 0x3f3f3f3f3f3f3f3f;
LL val[MAXN << 1];
LL f[MAXN << 1][MAXM], g[MAXN << 1][MAXM], p[MAXN][MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1043.txt", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) 
    {
        scanf("%lld", &val[i]);
        val[n + i] = val[i];
    }
    /*
        f[i][j] 表示前 i 个数切成 j 个部分的最大值
    */
    LL mi = INF, mx = 0;
    for (int base = 0; base <= n; ++base)
    {
        memset(g, 0x3f, sizeof(g));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
        {
            p[i][i] = (val[base + i] % MOD + MOD) % MOD;
            for (int j = i + 1; j <= n; ++j)
                p[i][j] = ((p[i][j - 1] + val[base + j]) % MOD + MOD) % MOD;
        }
        for (int i = 1; i <= n; ++i) f[i][1] = g[i][1] = p[1][i];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 2; j <= m; ++j)
            {
                for (int k = j - 1; k < i; ++k) // 切 j 份
                {
                    f[i][j] = max(f[i][j], f[k][j - 1] * p[k + 1][i]);
                    g[i][j] = min(g[i][j], g[k][j - 1] * p[k + 1][i]);
                }
            }
        }
        mi = min(mi, g[n][m]);
        mx = max(mx, f[n][m]);
    }
    printf("%lld\n%lld", mi, mx);
    return 0;
}