#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
const int MAXN = 5e3 + 5, MAXM = 1e5 + 5, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM << 1], start[MAXM << 1], ver[MAXM << 1], edge[MAXM << 1], tot = 0;
int dist[2][MAXN];
bool vis[MAXN];
inline void add(int u, int v, int w)
{
    start[++tot] = u;
    ver[tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void dijkstra(int from, int id)
{
    memset(dist[id], 0x3f, sizeof(dist[id]));
    memset(vis, false, sizeof(vis));
    priority_queue<pair<int, int> > q;
    dist[id][from] = 0;
    q.push(make_pair(0, from));
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int k = head[u]; k; k = nxt[k])
        {
            if (dist[id][u] + edge[k] < dist[id][ver[k]])
            {
                dist[id][ver[k]] = dist[id][u] + edge[k];
                q.push(make_pair(-dist[id][ver[k]], ver[k]));
            }
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-2-E2.in", "r", stdin);
#endif
    /*
        (我还没想明白呢就 A 了....，希望能被 hack)
        严格次短路有两种可能：（吧）
        1. 在原来的最短路上折返一个来回
        2. 某一段绕到另一个点上
        这两种可以合并成一种情况，
        设 dist0 是 1 为起点的最短路, dist1 是 n 为起点的最短路
        枚举每一条边，那么可能的次短路权值是 dist0[start[i]] + dist1[ver[i]] + edge[i]
        代表一定要经过这一条边的 1..n 的最短路
    */
    int n, R;
    n = rd(); R = rd();
    for (int i = 1; i <= R; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    int ans = INF;
    for (int i = 1; i <= tot; ++i)
    {
        // 次短路并不是不能到了终点再绕吧 = = 比如测试点 #4
        int res = dist[0][start[i]] + dist[1][ver[i]] + edge[i];
        if (res > dist[0][n]) ans = min(ans, res);
    }
    printf("%d", ans);
    return 0;
}