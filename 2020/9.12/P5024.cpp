#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
typedef long long LL;
const LL MAXN = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int head[MAXN], nxt[MAXN << 1], ver[MAXN << 1], tot;
inline void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
int a, x, b, y;
LL p[MAXN], f[MAXN][2];
int mark[MAXN];
inline void dfs(int cur, int fa)
{
    LL withThis = 0, withOutThis = 0;
    for (int k = head[cur]; k; k = nxt[k])
    {
        int to = ver[k];
        if (to == fa) continue;
        dfs(to, cur);
        withThis += min(f[to][0], f[to][1]);
        withOutThis += f[to][1];
    }
    if (mark[cur] != 1) f[cur][0] = withOutThis;
    if (mark[cur] != 0) f[cur][1] = withThis + p[cur];
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P5024.txt", "r", stdin);
    freopen("P5024.out", "w", stdout);
#endif
    int n, m;
    char type[3];
    scanf("%d %d %s", &n, &m, type);
    for (int i = 1; i <= n; ++i) p[i] = rd();
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        u = rd(); v = rd();
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= m; ++i)
    {
        a = rd(); x = rd();
        b = rd(); y = rd();
        memset(f, 0x3f, sizeof(f));
        memset(mark, -1, sizeof(mark));
        mark[a] = x; mark[b] = y;
    dfs(1, 1);
        LL ans = min(f[1][0], f[1][1]);
        if (ans < INF) printf("%lld\n", ans);
        else puts("-1");
    }
    return 0;
}