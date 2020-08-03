#include <iostream>
#include <algorithm>
#include <cstdio>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 3e2 + 5;
int v[MAXN], tot = 0, ans = 0;
struct Edge 
{
    int from, ver, w; bool inMST;
    Edge() { inMST = false; }
} e[MAXN * MAXN];
struct DSU // 并查集
{
    int f[MAXN];
    DSU() { for (int i = 1; i < MAXN; ++i) f[i] = i; }
    int getFather(int v)
    {
        if (f[v] != v) f[v] = getFather(f[v]);
        return f[v];
    }
    void unoin(int u, int v) { f[v] = u; }
} dsu;
inline bool cmp(Edge a, Edge b) { return a.w < b.w; }
inline void add(int u, int v, int w)
{
    e[++tot].from = u;
    e[tot].ver = v;
    e[tot].w = w;
}
std::string banner = R"( _   _               ____           ___
| \ | | _____      _| __ )  ___    / _ \ _ __   ___
|  \| |/ _ \ \ /\ / /  _ \ / _ \  | | | | '_ \ / _ \
| |\  |  __/\ V  V /| |_) |  __/  | |_| | | | |  __/
|_| \_|\___| \_/\_/ |____/ \___|___\___/|_| |_|\___|
                              |_____|)";
int main() 
{
    int n = rd();
    for (int i = 1; i <= n; ++i) v[i] = rd(), add(n + 1, i, v[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int w = rd();
            if (i == j) continue;
            add(i, j, w);
        }
    }
    std::sort(e + 1, e + 1 + tot, cmp);
    int msttot = 0;
    for (int i = 1; i <= tot; ++i)
    {
        int fu = dsu.getFather(e[i].from);
        int fv = dsu.getFather(e[i].ver);
        if (fu != fv)
        {
            e[i].inMST = true;
            dsu.unoin(fu, fv);
            ans += e[i].w;
            ++msttot;
            if (msttot == n) break;
        }
    }
    printf("%d", ans);
    std::cerr << banner;
    return 0;
}
/*
4
1
1
10
10
0 1 2000 2000
1 0 2000 2000
2000 2000 0 1
2000 2000 1 0
一道锻炼思维的题目，
一开始想的是求出最小生成树，然后再考虑割掉某条边形成两个联通支是否更好，但这样的想法是错误的。
看了题解之后恍然大悟，只需要建立一个超级源点作为发电站，以 v 作为边权，和每个节点链接，
如果一条边的代价太高，那么在生成 MST 的时候自然就不会被选到，而且由 MST 的性质，就能保证
发电站一定和每一个矿井联通。
*/