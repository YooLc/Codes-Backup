#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 5, MAXM = 5e5 + 5, MAXK = 21;
// 不同层上下有连边，多开一些空间 (指 << 2)
int head[MAXN * MAXK], _next[(MAXK * MAXM) << 2], ver[(MAXK * MAXM) << 2], edge[(MAXK * MAXM) << 2], tot;
int dis[MAXN * MAXK], n, m, k;
bool vis[MAXN * MAXK];
void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    _next[tot] = head[u];
    head[u] = tot;
}
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<int, int> >q;
    dis[1] = 0;
    q.push(make_pair(-dis[1], 1));
    while(q.size())
    {
        int t = q.top().second;
        q.pop();
        if(vis[t]) continue;
        vis[t] = true;
        for(int k = head[t]; k; k = _next[k])
        {
            int to = ver[k];
            if(dis[t] + edge[k] < dis[to])
            {
                dis[to] = dis[t] + edge[k];
                q.push(make_pair(-dis[to], to));
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("P2939_2.in", "r", stdin);
#endif
    scanf("%d %d %d", &n, &m, &k);
    int u, v, w;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
        for(int j = 1; j <= k; ++j)
        {
            add(j * n + u, j * n + v, w);
            add(j * n + v, j * n + u, w);
            add((j - 1) * n + u, j * n + v, 0);
            add((j - 1) * n + v, j * n + u, 0);
        }
    }
    dijkstra();
    int ans = dis[n];
    for(int i = 1; i <= k; ++i) ans = min(ans, dis[i * n + n]);
    printf("%d", ans);
    return 0;
}