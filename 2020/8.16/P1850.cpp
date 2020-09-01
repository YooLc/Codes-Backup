#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 2e3 + 5, MAXV = 305;
int c[MAXN], d[MAXN], road[MAXV][MAXV], delta[MAXN];
double p[MAXN], f[MAXN][MAXN][2];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1850.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, v, m, e;
    scanf("%d %d %d %d", &n, &m, &v, &e);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
    for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
    memset(road, 0x3f, sizeof(road));
    for (int i = 1; i <= v; ++i) road[i][i] = 0;
    for (int i = 1; i <= e; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        road[u][v] = road[v][u] = min(road[v][u], w); // 有重边和自环....
    }
    for (int k = 1; k <= v; ++k)
        for (int i = 1; i <= v; ++i)
            for (int j = 1; j <= v; ++j)
                road[i][j] = min(road[i][k] + road[k][j], road[i][j]);
    /*
        期望 dp
        f[i][j][0/1] 表示前 i 个教室申请了换 j 个教室，且第 i 个教室申请/没申请的最小期望。
        探索进度： 设计出来了状态，但是实在想不出来怎么转移了 TAT，想借鉴一下题目给的表格，但发现那个表格是暴力 = =
        解法： 看了题解之后发现，对于道路的长度，应该是一点一点累加上去（期望），而不是想着我当前状态直接算出来从 1 到 n 要走多远
        那么分情况讨论（见注释）
        Reference: https://www.luogu.com.cn/blog/user50971/solution-p1850
    */
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            f[i][j][0] = f[i][j][1] = 1e16;
    f[1][0][0] = f[1][1][1] = 0; // 从第一个教室开始走
    for (int i = 2; i <= n; ++i)
    {
        // j = 0 的转移
        f[i][0][0] = f[i - 1][0][0] + road[c[i - 1]][c[i]];
        for (int j = 1; j <= m && j <= i; ++j)
        {
            f[i][j][0] = min(f[i - 1][j][0] + road[c[i - 1]][c[i]], // 上一个没换，这一个也没换
                             f[i - 1][j][1] + (1 - p[i - 1]) * road[c[i - 1]][c[i]] + p[i - 1] * road[d[i - 1]][c[i]]); // 上一个换了，这次没换
            f[i][j][1] = min(f[i - 1][j - 1][0] + (1 - p[i]) * road[c[i - 1]][c[i]] + p[i] * road[c[i - 1]][d[i]], // 上一个没换，这一次换了 
                             f[i - 1][j - 1][1] + (1 - p[i - 1]) * p[i] * road[c[i - 1]][d[i]] + (1 - p[i - 1]) * (1 - p[i]) * road[c[i - 1]][c[i]] // 连着都换，有四种情况
                                                + p[i - 1] * p[i] * road[d[i - 1]][d[i]] + p[i - 1] * (1 - p[i]) * road[d[i - 1]][c[i]]);
        }
    }
    double ans = 1e16;
    for (int i = 0; i <= m; ++i) ans = min(ans, min(f[n][i][0], f[n][i][1]));
    printf("%.2lf", ans);
    return 0;
}