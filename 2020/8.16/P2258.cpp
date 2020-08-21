#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 20, MAXM = 20, INF = 0x3f3f3f3f;
int a[MAXN][MAXM], f[MAXN][MAXN];
int n, m, r, c, ans = INF;
bool vis[MAXM];
/*
    不好想直接 dp 的方法，考虑
    用 dfs 暴力枚举选择的列（其中一维）（也可以用状态压缩，不过要排除掉不合法状态）
    然后再对行进行 dp
    这样能够比较容易地控制我选了哪行哪列
    两边都暴力枚举的话，时间复杂度会超
*/
inline int abs(int x) { return x >= 0 ? x : -x; }
inline void dfs(int cur, int s)
{
    if (s == c && cur <= m + 1)
    {
        // f[i][j] 表示前 i 行选了 j 行，而且正好选了第 i 行的最小分值
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= r; ++j)
            {
                for (int k = j - 1; k < i; ++k)
                {
                    int sum = 0;
                    for (int t = 1, last = 0; t <= m; ++t)
                    {
                        if (vis[t]) 
                        {
                            if (last) sum += abs(a[i][t] - a[i][last]);
                            if (j > 1) sum += abs(a[k][t] - a[i][t]);
                            last = t;
                        }
                    }
                    f[i][j] = std::min(f[i][j], f[k][j - 1] + sum);
                }
            }
        }
        for (int i = r; i <= n; ++i) ans = std::min(ans, f[i][r]);
        return;
    }
    else if (s > c || cur == m + 1) return;
    vis[cur] = true;
    dfs(cur + 1, s + 1);
    vis[cur] = false;
    dfs(cur + 1, s);
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P2258.in", "r", stdin);
    freopen("P2258.out", "w", stdout);
#endif
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}