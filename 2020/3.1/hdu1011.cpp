#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const static int MAXN = 1e2 + 5;
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
    while(~scanf("%d %d", &n, &m))
    {
        init();
        if(n == -1 && m == -1) break;
        for (int i = 1; i <= n; ++i)
        {
            int c, v;
            scanf("%d %d", &c, &v);
            cost[i] = ceil(c / 20.0);
            val[i] = v;
        }
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }
        if(m <= 0)
        {
            puts("0");
            continue;
        }
        dfs(1, 1);
        printf("%d\n", dp[1][m]);
    }
    return 0;
}