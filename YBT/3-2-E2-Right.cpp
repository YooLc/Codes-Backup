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
int head[MAXN], nxt[MAXM << 1], ver[MAXM << 1], edge[MAXM << 1], tot = 0;
int dist[MAXN][2];
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void dijkstra()
{
    // dist[i][0/1] 表示 1 到 i 的最短路/次短路
    memset(dist, 0x3f, sizeof(dist));
    dist[1][0] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, 1));
    while (q.size())
    {
        int u = q.top().second; 
        int d = -q.top().first;
        q.pop();
        if (d > dist[u][1]) continue;
        for (int k = head[u]; k; k = nxt[k])
        {
            int to = ver[k], len = d + edge[k];
            if (len < dist[to][0]) // 严格小于，防止次短路被更新后与最短路相同
            {
                dist[to][1] = dist[to][0]; // 原来的最短路顺位为次短路
                dist[to][0] = len;
                q.push(make_pair(-dist[to][0], to));
            }
            else if (len > dist[to][0] && len < dist[to][1]) 
            {
                dist[to][1] = len;
                // 一条路可以重复走多次，可以绕回去
                q.push(make_pair(-len, to));
            }
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-2-E2.in", "r", stdin);
    // freopen("3-2-E2.out", "w", stdout);
#endif
    /*
        次短路 Reference: https://blog.csdn.net/qq_40772692/article/details/82530467
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
    dijkstra();
    printf("%d", dist[n][1]);
    return 0;
}