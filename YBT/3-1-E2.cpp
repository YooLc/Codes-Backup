#include <iostream>
#include <cstdio>
#include <algorithm>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 50;
struct Edge 
{
    int from, to, weight;
    bool operator< (const Edge &cmp) const { return weight < cmp.weight; }
} e[MAXN];
struct DSU // 并查集
{
    int f[MAXN];
    LL cnt[MAXN];
    DSU() { for (int i = 1; i < MAXN; ++i) f[i] = i, cnt[i] = 1; } // 初始化
    int getFather(int v)
    {
        if (f[v] != v) f[v] = getFather(f[v]);
        return f[v];
    }
    LL getCnt(int u) { return cnt[f[u]]; }
    void _union(int u, int v) { f[v] = u; cnt[u] += cnt[v]; } // 维护 sum 和 cnt 的值
} dsu;
inline LL C(LL n) { return ((n - 1) * n) >> 1; } // 计算 Cn2，也就是 n 个点的完全图边数
int main() 
{
    freopen("3-1-E2.in", "r", stdin);
    int n = rd(); LL ans = 0ll;
    for (int i = 1; i <= n - 1; ++i)
        e[i].from = rd(), e[i].to = rd(), e[i].weight = rd();
    sort(e + 1, e + n);
    /*
        思路： 通过 Kruskal 算法的思路来做。
        1. 对所有边进行排序
        2. 用并查集维护联通支，
           对于一个新加入的点，为了构成完全图，需要将其和该联通支的每个点都连一条边，
           这条边的权值是当前边的权值 + 1
           这样一来，你所建立的完全图所有边排序之后，新添加的边一定排在当前边的后面，
           而新添加的边所连接的点都已经在一个并查集里了，就相当于被 Kruskal 的过程忽略了，
           我们做的就是将其补充进来。
        3. 为了知道我们需要建立多少条边，我们需要在并查集的过程中维护两个值
           cnt: 当前联通支有多少个点
           sum: 当前联通支有多少条边（包括自己建立的）
           那么每一次有新的点加入，对 ans 的贡献就是 (e[i].weight + 1) * (C(cnt) - sum)
           或者说，是两个联通支互相两两相连再减掉已经添加的边，也就是 (e[i].weight + 1) * (cnt[fu] * cnt[fv] - 1)
           此处 Reference: https://loj.ac/submission/842603
        4. 开 long long
    */
    for (int i = 1; i <= n - 1; ++i)
    {
        ans += e[i].weight; // 加上 MST 里的边
        int to = e[i].to;
        int fu = dsu.getFather(e[i].from);
        int fv = dsu.getFather(to);
        if (fu != fv)
        {
            LL cnt1 = dsu.getCnt(fu); 
            LL cnt2 = dsu.getCnt(fv);
            ans += (e[i].weight + 1) * (cnt1 * cnt2 - 1); // 建立新边
            dsu._union(fu, fv);       // 合并
        }
    }
    printf("%lld", ans);
    return 0;
}