#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const static int MAXN = 2e2 + 5;
int head[MAXN], _next[MAXN << 1], ver[MAXN << 1], tot;
int cost[MAXN], val[MAXN], dp[MAXN][MAXN], n, m;
void add(int u, int v)
{
    ver[++tot] = v;
    _next[tot] = head[u];
    head[u] = tot;
}
void init()
{
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(_next, 0, sizeof(_next));
    memset(dp, 0, sizeof(dp));
}
void dfs(int cur, int father)
{
    for (int v = cost[cur]; v <= m; ++v) // 打掉本节点的价值
        dp[cur][v] = val[cur];
    for (int k = head[cur]; k; k = _next[k])
    {
        int to = ver[k];
        if(to == father) continue;
        dfs(to, cur);
        for(int v = m; v >= cost[cur]; --v) // 用于该路的总容量
            for (int c = 1; c <= v - cost[cur]; ++c) // 用于打子节点的容量（必须先打掉本节点）
                dp[cur][v] = max(dp[cur][v], dp[cur][v - c] + dp[to][c]);
    }
}
int main()
{
    // 树形DP （有先决条件的背包问题）
    // Same with hdu1011
    while(~scanf("%d %d", &n, &m))
    {
        init();
        if(n + m == 0) break;
        for (int i = 1; i <= n; ++i)
        {
            int fa;
            scanf("%d %d", &fa, &val[i]);
            cost[i] = 1;
            add(fa, i);
        }
        dfs(0, 0);
        printf("%d\n", dp[0][m]);
    }
    return 0;
}