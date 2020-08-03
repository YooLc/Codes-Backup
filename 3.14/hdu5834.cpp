#include <iostream>
#include <cstdio>
#include <cstring>
const static int MAXN = 1e6 + 50;
int head[MAXN], nxt[MAXN << 1], ver[MAXN << 1], edge[MAXN << 1], tot;
int val[MAXN];
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
    memset(head, 0, sizeof(head));
}
inline void solve()
{
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", val[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
        printf("Case #%d:\n", i), solve();
    return 0;
}