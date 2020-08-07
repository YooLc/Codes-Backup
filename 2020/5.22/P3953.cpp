#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 50, MAXM = 2e5 + 50, INF = 0x3f3f3f3f;
struct E
{
    int head[MAXN], nxt[MAXM], edge[MAXM], ver[MAXM], tot;
    int dis[MAXN];
} e[2];
int f[MAXN][51], in[MAXN];
int n, m, k, dis[MAXN], MOD;
bool vis[MAXN];
inline int plus(int a, int b) { return (a % MOD + b % MOD) % MOD; }
inline void add(int u, int v, int w, int t)
{
    if (!t) in[v]++;
    e[t].ver[++e[t].tot] = v;
    e[t].edge[e[t].tot] = w;
    e[t].nxt[e[t].tot] = e[t].head[u];
    e[t].head[u] = e[t].tot;
}
inline void dijkstra(int start, int t)
{
    memset(e[t].dis, 0x3f, sizeof(e[t].dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int> > q;
    e[t].dis[start] = 0;
    q.push(make_pair(0, start));
    while(q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int k = e[t].head[u]; k; k = e[t].nxt[k])
        {
            int to = e[t].ver[k];
            if (e[t].dis[u] + e[t].edge[k] < e[t].dis[to])
            {
                e[t].dis[to] = e[t].edge[k] + e[t].dis[u];
                q.push(make_pair(-e[t].dis[to], to));
            }
        }
    }
}
inline void topo()
{
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int u = q.front(); q.pop();
        for (int k = e[0].head[u]; k; k = e[0].nxt[k])
        {
            int to = e[0].ver[k], w = e[0].edge[k];
            for (int t = 0; t <= 50; ++t)
            {
                int fdis = e[0].dis[u] + t + w - e[0].dis[to];
                if (fdis < 0) continue;
                f[to][fdis] = plus(f[to][fdis], f[u][t]);
            }
        }
    }
}
inline int solve()
{
    // 初始化
    memset(e, 0, sizeof(e)); 
    memset(in, 0, sizeof(in));
    // 建立正反图
    scanf("%d %d %d %d", &n, &m, &k, &MOD);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w, 0);
        add(v, u, w, 1);
    }
    // 求出双向最短路
    dijkstra(1, 0); dijkstra(n, 1);
    // 从起点开始拓扑
    topo();
    printf("%d", f[n][k] % MOD);
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("P3953.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) 
        printf("%d\n", solve());
    return 0;
}