#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 50, MAXM = 2e5 + 50;
int head[MAXN], ver[MAXM], nxt[MAXM], tot;
int in[MAXN], out[MAXN], cnt[MAXN], n, m;
bool vis[MAXN];
inline void add(int u, int v)
{
    out[u]++; in[v]++; vis[v] = true;
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!in[i]) cnt[i] = 1, q.push(i);
    while(q.size())
    {
        int u = q.front(); q.pop();
        for (int k = head[u]; k; k = nxt[k])
        {
            in[ver[k]]--; cnt[ver[k]] += cnt[u];
            if (!in[ver[k]]) q.push(ver[k]);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    topo();
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!out[i] && vis[i]) ans += cnt[i];
    printf("%d", ans);
    return 0;
}