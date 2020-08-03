#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e2 + 50, MAXM = 1e3 + 50, MOD = 31011;
using namespace std;
map<int, int> c;
struct Edge
{
    int from, to, w;
    bool inMST;
    Edge() { inMST = false; }
    bool operator < (const Edge &comp) const { return w < comp.w; }
} e[MAXM << 1];
struct DSU 
{
    int f[MAXN];
    DSU() { for (int i = 0; i < MAXN; ++i) f[i] = i; }
    int getFather(int v) { return f[v] == v ? f[v] : (f[v] = getFather(f[v])); }
    void _union(int u, int v) { f[v] = u; }
} dsu;
int n, m, tot = 0, msttot = 0, ans = 0;
bool vis[MAXN];
inline void dfs(int cur, int cnt)
{
    cout << cur << " with: " << cnt << endl;
    if (cur == m + 1) { ans++; return; }
    int wcur = e[cur].w, wnxt = e[cur + 1].w; 
    if (wcur == wnxt)
    {
        if (cnt < c[wcur])
            dfs(cur + 1, cnt + 1); // 选这条边
        dfs(cur + 1, cnt);         // 不选这条边
    }
    else if(cnt == c[wcur])
    {
        dfs(cur + 1, 0);
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-1-E5.in", "r", stdin);
    // freopen("3-1-E3.out", "w", stdout);
    // reference: 
#endif
    n = rd(); m = rd(); 
    for (int i = 1; i <= m; ++i)
        e[i].from = rd(), e[i].to = rd(), e[i].w = rd();
    std::sort(e + 1, e + 1 + m);
    // Kruskal
    for (int i = 1; i <= m; ++i)
    {
        int u = e[i].from, v = e[i].to;
        int fu = dsu.getFather(u);
        int fv = dsu.getFather(v);
        if (fu != fv)
        {
            dsu._union(fu, fv);
            e[i].inMST = true;
            ++msttot; c[e[i].w]++;
            if (msttot == n - 1) break;
        }
    }
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}