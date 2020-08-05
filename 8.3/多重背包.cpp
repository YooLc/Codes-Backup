#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXNLOGN = 2e3 + 5, MAXV = 2e3 + 5;
int n, V, tot = 0;
int vol[MAXNLOGN], val[MAXNLOGN], dp[MAXV];
void solve()
{
    memset(dp, 0, sizeof(dp));
    tot = 0;
    scanf("%d %d", &V, &n);
    for (int i = 1; i <= n; ++i)
    {
        int vo, va, lim, p = 1;
        scanf("%d %d %d", &vo, &va, &lim);
        // 二进制拆分
        // 13 个物品， 拆成 1, 2, 4, 6 个合在一起的包
        // 16 个物品， 拆成 1, 2, 4, 8, 1 个合在一起的包
        // .....
        while (lim - p > 0)
        {
            lim -= p;
            vol[++tot] = vo * p;
            val[tot] = va * p;
            p <<= 1;
        }
        // 剩下的打包成一个物品
        vol[++tot] = vo * lim;
        val[tot] = va * lim;
    }
    for (int i = 1; i <= tot; ++i)
        for (int j = V; j >= vol[i]; --j)
            dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
    printf("%d\n", dp[V]);
}
int main() 
{
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) solve();
    return 0;
}
/*
1
8 2
1 20000 1
1 1 1000
*/