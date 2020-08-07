#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e4 + 5, MAXM = 2e3 + 5, INF = 0x3f3f3f3f;
int x[MAXN], y[MAXN];
struct Tube 
{
    int l, h;
    bool lim;
} tube[MAXN];
int f[2][MAXM], cur = 0;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int main() 
{
    int n, m, k, pos, mx = 0;
    n = rd(); m = rd(); k = rd();
    for (int i = 1; i <= n; ++i) 
    { 
        x[i] = rd(); y[i] = rd(); 
        tube[i] = {0, m + 1, false}; 
    }
    tube[n] = {0, m + 1, false};
    for (int i = 1; i <= k; ++i) 
    { 
        pos = rd();
        tube[pos].l = rd();
        tube[pos].h = rd(); 
        tube[pos].lim = true;
    }
    /*
        f[x][y] 表示到达 (x, y) 的最小点击数
        想法:
        f[i][j] 可以从 f[i - 1][j + y[i]] 和 f[i - 1][j - t * x[i]] (t \in N*) 转移而来
        然而枚举 t * x[i] 这一部分为本就 1e7 的循环增加了复杂度，
        这时候想到把地图看成背包，上升的过程就相当于装物品，那么我想装多件物品（按多次屏幕），
        就可以从已经计算好的 f[i][j - x[i]] 转移，这样使子问题重叠程度更大，时间复杂度就降下来了。
        这道题一开始没有想到背包问题，
        然而参考题解之后发现这题综合了两种背包模型，实属好题。
        Reference: https://www.luogu.com.cn/blog/Tomato-0518/solution-p1941
    */
    using namespace std;
    for (int i = 1; i <= n; ++i)
    {
        cur ^= 1; bool updated = false;
        memset(f[cur], 0x3f, sizeof(f[cur]));
        // 上升阶段: 完全背包，可以装多个 "容量为 x[i]，价值为 1" 的物品
        for (int j = x[i] + 1; j <= m + x[i]; ++j)
            f[cur][j] = min(f[cur][j], min(f[cur][j - x[i]] + 1, f[cur ^ 1][j - x[i]] + 1));
        // 超过了 m 不能继续飞，但是答案还得更新
        for (int j = m + 1; j <= m + x[i]; ++j)
            f[cur][m] = min(f[cur][m], f[cur][j]);
        // 下降阶段: 0-1背包，只能装一个 "容量为 -y[i]，价值为 0" 的物品
        for (int j = m - y[i]; j >= 1; --j)
            f[cur][j] = min(f[cur][j], f[cur ^ 1][j + y[i]]);
        // 作为背包再把柱子挡上的补回来
        for (int j = 0; j <= tube[i].l; ++j) f[cur][j] = INF;
        for (int j = tube[i].l + 1; j < tube[i].h; ++j) if (f[cur][j] < INF) { updated = true; break; }
        for (int j = tube[i].h; j <= m; ++j) f[cur][j] = INF;
        if (!updated) { printf("0\n%d", mx); return 0; }
        if (tube[i].lim) mx++;
    }
    int ans = INF;
    for (int i = 1; i <= m; ++i) ans = min(ans, f[cur][i]);
    printf("1\n%d", ans);
    return 0;
}