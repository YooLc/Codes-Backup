#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 25, MAXM = 10005;
int dp[MAXM], pre[MAXN][MAXM];
int vol[MAXN], val[MAXN];
inline void printPath(int cur, int v)
{
    if (cur <= 0 || v <= 0) return;
    if (pre[cur][v]) 
    {
        printPath(cur - 1, v - vol[cur]); 
        printf("%d ", vol[cur]);
    }
    else printPath(cur - 1, v);
}
int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("uva624.in", "r", stdin);
    //freopen("uva624.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d %d", &m, &n))
    {
        memset(pre, 0, sizeof(pre));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &vol[i]);
            val[i] = vol[i];
            for (int j = m; j >= vol[i]; --j)
            {
                if (dp[j] > dp[j - vol[i]] + val[i]) continue;
                dp[j] = dp[j - vol[i]] + val[i];
                pre[i][j] = i;
            }
        }
        printPath(n, m);
        printf("sum:%d\n", dp[m]);
    }
    return 0;
}