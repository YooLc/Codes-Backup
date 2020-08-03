#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
typedef long long LL;
const int MAXN = 5e2 + 5, MAXM = 1e4 + 5;
struct Edge
{
    int from, to, w, next;
    bool inMST;
    Edge() { inMST = false; }
    bool operator < (const Edge &comp) const { return w < comp.w; }
} e[MAXM << 1], e2[MAXN << 1];
struct DSU 
{
    int f[MAXN];
    DSU() { for (int i = 0; i < MAXN; ++i) f[i] = i; }
    int getFather(int v) { return f[v] == v ? f[v] : (f[v] = getFather(f[v])); }
    void _union(int u, int v) { f[v] = u; }
} dsu;

int tot = 0, head[MAXN], maxd[MAXN][MAXN];
bool vis[MAXN];
inline void add(int u, int v, int w)
{
    e2[++tot].to = v;
    e2[tot].w = w;
    e2[tot].next = head[u];
    head[u] = tot;
}
inline void dfs(int cur, int mx, int ori)
{
    vis[cur] = true;
    maxd[ori][cur] = maxd[cur][ori] = std::max(mx, maxd[ori][cur]);
    for (int k = head[cur]; k; k = e2[k].next)
    {
        int to = e2[k].to;
        if (vis[to]) continue;
        dfs(to, std::max(mx, e2[k].w), ori);
    }
}

int main() 
{
#ifndef ONLINE_JUDGE
    // freopen("3-1-E3.in", "r", stdin);
    // freopen("3-1-E3.out", "w", stdout);
#endif
    int n, m, msttot = 0;
    n = rd(); m = rd();
    for (int i = 1; i <= m; ++i)
        e[i].from = rd(), e[i].to = rd(), e[i].w = rd();
    std::sort(e + 1, e + 1 + m);
    LL sum = 0, ans = 0x3f3f3f3f3f3f3f3f;
    /*
        非严格次小生成树：
        1. 用 Prim 或 Kruskal(本代码) 求出最小生成树
        2. 在最小生成树上 n^2 获得 maxd(u, v) 一条路径上最大的边权（也可用 LCA）
        3. 枚举不在最小生成树里的边，添加进来，形成一个环，再删掉 maxd(u, v) 的最大边权，更新答案
    */
     // Kruskal
    for (int i = 1; i <= m; ++i)
    {
        int u = e[i].from, v = e[i].to;
        int fu = dsu.getFather(u);
        int fv = dsu.getFather(v);
        if (fu != fv)
        {
            dsu._union(fu, fv);
            add(u, v, e[i].w);
            add(v, u, e[i].w);
            sum += e[i].w;
            e[i].inMST = true;
            ++msttot;
            if (msttot == n - 1) break;
        }
    }
    // dfs 获得 maxd[][] O(n ^ 2)
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, false, sizeof(vis));
        dfs(i, 0, i);
    }
    // 枚举边，更新答案
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].inMST) continue;
        LL t = sum + e[i].w - maxd[e[i].from][e[i].to];
        if (ans > t)
            ans = t;
    }
    printf("%lld", ans);
    return 0;
}