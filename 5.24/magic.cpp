#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
inline LL rd()
{
    LL t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e2 + 5, MAXM = 1e4 + 5;
int head[MAXN], ver[MAXM], nxt[MAXM], tot;
LL n, m, q, cur = 0, flag = 0;
vector<LL> f[MAXM];
map<vector<LL>, int> h;
inline void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void calc()
{
    cur++;
    for (int i = 1; i <= n; ++i)
        for (int k = head[i]; k; k = nxt[k])
            f[cur][i] ^= f[cur - 1][ver[k]];
    if (h.count(f[cur]) || cur == MAXM - 4) flag = true;
    else h[f[cur]] = cur;
}
int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    for (int i = 0; i < MAXM; ++i) f[i].resize(MAXN);
    n = rd(); m = rd(); q = rd();
    for (int i = 1; i <= n; ++i) f[cur][i] = rd();
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        u = rd(); v = rd();
        add(u, v); add(v, u);
    }
    while (!flag) calc();
    cur--;
    for (int i = 1; i <= q; ++i) 
    {
        LL a; a = rd();
        printf("%lld\n", f[a % cur ? a % cur : cur][1]);
    }
    return 0;
}
