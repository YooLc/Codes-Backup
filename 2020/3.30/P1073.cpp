#pragma GCC optimize("O3")
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 10, MAXM = 5e5 + 10, INF = 0x3f3f3f3f;
int head[MAXN], _next[MAXM << 1], ver[MAXM << 1], tot;
int val[MAXN], mi[MAXN], n, m, f[MAXN];
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline void add(int &u, int &v)
{
    ver[++tot] = v;
    _next[tot] = head[u];
    head[u] = tot;
}
void dfs(int cur, int fa , int minn)
{
    bool updated = false; // 一个点就两个用途：交易，或者更新，如果都没用到，那么我们抛弃这个点（待证明）
    if(minn > val[cur]) minn = val[cur];
    if(mi[cur] > minn) mi[cur] = minn, updated = true;
    int maxx = f[fa] > val[cur] - minn ? f[fa] : val[cur] - minn;
    if(f[cur] < maxx) f[cur] = maxx, updated = true;
    if(!updated) return;
    for(int k = head[cur]; k; k = _next[k]) dfs(ver[k], cur, minn);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("trade9.in","r",stdin);
    // % CJX % 大佬题解：LGID41537
#endif
    n = rd(); m = rd();
    for(int i = 1; i <= n; ++i) val[i] = rd(), mi[i] = INF;
    for(int i = 0; i + 3 < m; i += 3)
    {
        int u, v, opt;
        u = rd(); v = rd(); opt = rd();
        if(opt == 2) add(v ,u);
        add(u, v);
        u = rd(); v = rd(); opt = rd();
        if(opt == 2) add(v ,u);
        add(u, v);
        u = rd(); v = rd(); opt = rd();
        if(opt == 2) add(v ,u);
        add(u, v);
    }
    for(int i = 0; i < m % 3; ++i)
    {
        int u, v, opt;
        u = rd(); v = rd(); opt = rd();
        if(opt == 2) add(v ,u);
        add(u, v);
    }
    dfs(1, 0, INF);
    printf("%d", f[n]);
    return 0;
}
