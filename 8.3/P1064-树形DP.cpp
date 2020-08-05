#include <iostream>
#include <cstdio>
using namespace std;
const static int MAXN = 3.2e3 + 5, MAXM = 61;
int head[MAXM], _next[MAXM], ver[MAXM], tot;
int cost[MAXM], val[MAXM], dp[MAXM][MAXN], n, volume;
void add(int u, int v)
{
    ver[++tot] = v;
    _next[tot] = head[u];
    head[u] = tot;
}
void dfs(int cur, int father)
{
    for (int v = cost[cur]; v <= volume; ++v) // 选取本节点的贡献
        dp[cur][v] = val[cur];
    for (int k = head[cur]; k; k = _next[k])
    {
        int to = ver[k];
        if(to == father) continue;
        dfs(to, cur);
        for(int v = volume; v >= cost[cur]; --v) // 用于该路的总容量
            for (int c = 1; c <= v - cost[cur]; ++c) // 用于选取子节点的容量（必须先选取本节点）
                dp[cur][v] = max(dp[cur][v], dp[cur][v - c] + dp[to][c]);
    }
}
int main()
{
    // 开 O2 能过，快了很多，不开不行
    // 树形DP （有先决条件的背包问题）参考 hdu1011
    scanf("%d %d", &volume, &n);
    volume /= 10; // 10 的整数倍，Designed for TLE
    for (int i = 1; i <= n; ++i)
    {
        int fa;
        scanf("%d %d %d", &cost[i], &val[i], &fa);
        val[i] *= cost[i];
        cost[i] /= 10;
        add(fa, i);
    }
    dfs(0, 0);
    printf("%d\n", dp[0][volume]);
    return 0;
}