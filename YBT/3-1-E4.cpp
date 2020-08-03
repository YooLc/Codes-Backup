#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
const int MAXN = 5e4 + 50, MAXM = 1e5 + 50;
int n, m, cnt, ret;
struct Edge
{
    int u, v, w; bool isWhite;
} e[MAXM];
struct DSU 
{
    int f[MAXN];
    void init(int &size) { for (int i = 0; i <= size; ++i) f[i] = i; }
    int getFather(int v) { return f[v] == v ? f[v] : (f[v] = getFather(f[v])); }
    void _union(int u, int v) { f[v] = u; }
} dsu;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline bool cmp(Edge a, Edge b)
{
    if (a.w == b.w) return a.isWhite > b.isWhite; // 先选白边，Black Lives Matter!
    return a.w < b.w; 
}
inline void kruskal(int delta)
{
    cnt = ret = 0; int msttot = 0; 
    dsu.init(n);
    for (int i = 0; i < m; ++i) if (e[i].isWhite) e[i].w += delta;
    sort(e, e + m, cmp);
    for (int i = 0; i < m; ++i)
    {
        int fu = dsu.getFather(e[i].u);
        int fv = dsu.getFather(e[i].v);
        if (fu == fv) continue;
        if (e[i].isWhite) cnt++;
        msttot++; ret += e[i].w;
        dsu._union(fu, fv);
        if (msttot == n - 1) break;
    }
    for (int i = 0; i < m; ++i) if (e[i].isWhite) e[i].w -= delta;
} 
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-1-E4.in", "r", stdin);
#endif
    int need, ans = 0;
    n = rd(); m = rd(); need = rd();
    for (int i = 0; i < m; ++i)
    {
        e[i].u = rd(); e[i].v = rd();
        e[i].w = rd(); e[i].isWhite = rd() ^ 1;
    }
    /*
        一开始想的是先把 need 条白边先选上，再去选黑边。但这肯定是错的。
        看到题解后，再次针对 Kruskal 的运行过程进行思考，发现给白边增加 / 减少权值，
        可以控制在 MST 中白边被选择的数量，而且被选择的数量是单调不增加的。
        这就很容易进行二分搜索了，算完的 MST 总权值再减去 cnt * mid 就是了。
        然而如果增量为 x，选了不到 need 条，
         而增量为 x + 1，选了超过 need 条，
        该怎么办呢，这时会发现其实是有一些和白边权值相等的黑边恰好在排序的时候排在了前面，
        那么排序的时候我们尽可能多的选白边，这样 cnt < need 是真的少，而 cnt >= need 会符合条件，
        因此只需要选 cnt >= need 时更新答案就行了。
        Reference: https://loj.ac/article/872
                   https://blog.csdn.net/qq_37759040/article/details/77149274
    */
    int l = -101, r = 101; // [-100, 100] 两端要能取到
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        kruskal(mid);
        if (cnt >= need) ans = ret - need * mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}