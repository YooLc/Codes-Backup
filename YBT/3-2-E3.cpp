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
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5, MOD = 1e5 + 3;
int head[MAXN], nxt[MAXM << 1], ver[MAXM << 1], dist[MAXN], f[MAXN], tot = 0;
bool vis[MAXN];
inline void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int> > q;
    dist[1] = 0; // 对于 1，不走就是最短路
    f[1] = 1;
    q.push(make_pair(0, 1));
    while (q.size())
    {
        int u = q.top().second; 
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int k = head[u]; k; k = nxt[k])
        {
            if (dist[u] + 1 < dist[ver[k]])
            {
                dist[ver[k]] = dist[u] + 1;
                f[ver[k]] = f[u]; // 最短路数量顺延下来
                q.push(make_pair(-dist[ver[k]], ver[k]));
            }
            else if (dist[u] + 1 == dist[ver[k]]) f[ver[k]] = (f[ver[k]] + f[u]) % MOD; // 对于同样是最短路的，求和
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-2-E3.in", "r", stdin);
    freopen("3-2-E3.out", "w", stdout);
#endif
    int n, m;
    n = rd(); m = rd();
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        u = rd(); v = rd();
        add(u, v);
        add(v, u);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) printf("%d\n", f[i]);
    return 0;
}