#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 1, MAXM = 2e5 + 1, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM], edge[MAXM], ver[MAXM], tot;
int dis[MAXN], f[MAXN][51], n, m, lim, MOD;
bool vis[MAXN];
inline int p(int a, int b) { return (a + b) % MOD; }
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void init()
{
    tot = 0;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(f, 0, sizeof(f));
    memset(head, 0, sizeof(head));
}
inline void dijkstra()
{   
    priority_queue<pair<int, int> > q;
    dis[1] = 0;
    q.push(make_pair(0, 1));
    while(q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = true;
        for (int k = head[u]; k; k = nxt[k])
        {
            int to = ver[k];
            // printf("%d -> %d k: %d\n", u, to, k);
            if (dis[u] + edge[k] < dis[to])
            {
                dis[to] = edge[k] + dis[u];
                q.push(make_pair(-dis[to], to));
            }
        }
    }
}
inline void topo()
{
    priority_queue<pair<int, int> > q;
    f[1][0] = 1;
    for (int i = 1; i <= n; ++i) q.push(make_pair(-dis[i], i));
    while(q.size())
    {
        int u = q.top().second; q.pop();
        for (int k = head[u]; k; k = nxt[k])
        {
            // printf("%d -> %d edge No.%d\n", u, ver[k], k);
            int to = ver[k], w = edge[k];
            for (int t = 1; t <= lim; ++t) f[to][t] = f[to][t - 1];
            for (int t = 0; t <= lim; ++t)
            {
                if (dis[u] >= INF) continue;
                int nw = dis[u] + t + w - dis[to];
                if (nw < 0 || nw > lim) continue;
                f[to][nw] = p(f[to][nw], f[u][t]);
                // printf("nw(%d) = %d + %d + %d - %d\n", nw, dis[u], t, w, dis[to]);
                // printf("f[%d][%d](%d) -> f[%d][%d](%d)\n", u, t, f[u][t], to, nw, f[to][nw]);
            }
        }
    }
}
inline int solve()
{
    // Reference: https://www.luogu.com.cn/blog/Kelin/solution-p3953 70pts做法， 代码手打
    init();
    scanf("%d %d %d %d", &n, &m, &lim, &MOD);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(); topo();
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 0; j <= lim; ++j) cout << f[i][j] << " ";
    //     cout << endl;
    // }
    return f[n][lim] % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("park3.in", "r", stdin);
    freopen("park.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) 
        printf("%d\n", solve());
    return 0;
}