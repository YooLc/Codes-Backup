#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;
int w[MAXN][MAXN], cost[MAXN];
int f[2][MAXN][MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1070.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, m, p;
    n = rd(); m = rd(); p = rd();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            w[i][j] = rd();
    for (int i = 1; i <= n; ++i) cost[i] = rd();
    /*
        令 f[T][i][j] 表示第 T 个单位时间，走到 i 号城市还剩 j 步时的最大收益
        时间 O(n^3)
        空间 O(n^2)
        开了 o2 后, n^3 过 1e9......
        待优化算法，联赛又没有 o2
    */
    int cur = 0, ans = 0;
    memset(f[cur], -0x3f, sizeof(f[cur]));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= p; ++j)
            f[cur][i][j] = -cost[i];
    for (int i = 1; i <= m; ++i) // 阶段： 第 i 秒
    {
        int mx = -INF; cur ^= 1;
        memset(f[cur], -0x3f, sizeof(f[cur]));
        for (int j = 1; j <= n; ++j) // 状态： 机器人经过了 j 号道路
        {
            int to = (j == n) ? 1 : j + 1;
            for (int t = 0; t < p; ++t) // 决策：正常走一步
                f[cur][to][t] = max(f[cur][to][t], f[cur ^ 1][j][t + 1] + w[j][i]);
            mx = max(mx, f[cur][to][0]);
        }
        for (int j = 1; j <= n; ++j) // 状态： 机器人经过了 j 号道路
            for (int t = 1; t <= p; ++t) // 决策： 购买机器人
                f[cur][j][t] = max(f[cur][j][t], mx - cost[j]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= p; ++j)
            ans = max(ans, f[cur][i][j]);
    printf("%d", ans);
    return 0;
}