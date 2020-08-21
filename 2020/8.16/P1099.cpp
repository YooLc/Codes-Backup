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
const int MAXN = 305, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXN << 1], ver[MAXN << 1], edge[MAXN << 1], tot;
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
int mxsum = 0, deepest = 0, n, s;
bool vis[MAXN], book[MAXN];
void findDeepest(int cur, int sum)
{
    if (sum > mxsum)
    {
        sum = mxsum;
        deepest = cur;
    }
    for (int k = head[cur]; k; k = nxt[k])
    {
        if (vis[ver[k]]) continue;
        vis[ver[k]] = true;
        findDeepest(ver[k], sum + edge[k]);
    }
}
int diam = 0;
void dfs(int cur, int sum)
{
    diam = max(sum, diam);
    for (int k = head[cur]; k; k = nxt[k])
    {
        if (vis[ver[k]]) continue;
        vis[ver[k]] = true;
        dfs(ver[k], sum + edge[k]);
    }
}
int stN[MAXN], stE[MAXN], top = 0, ans = INF, diambak;
void calcDiam(int cur, int sum)
{
    if (sum == diambak)
    {
        // cout << "Diam found:" << endl;
        // for (int i = 1; i <= top; ++i)
        //     cout << stN[i] << " ";
        // cout << endl;
        // for (int i = 1; i <= top; ++i)
        //     cout << stE[i] << " ";
        // cout << endl;
        for (int l = 1; l <= top; ++l)
        {
            for (int r = l; r <= top; ++r)
            {
                int sum = 0, mx = 0;
                memset(vis, false, sizeof(vis));
                vis[stN[l]] = true;
                for (int k = l + 1; k <= r; ++k)
                    sum += stE[k], vis[stN[k]] = true;
                if (sum > s) break;
                for (int k = l; k <= r; ++k)
                {
                    diam = 0;
                    dfs(stN[k], 0);
                    mx = max(mx, diam);
                }
                ans = min(ans, mx);
            }
        }
        return;
    }
    for (int k = head[cur]; k; k = nxt[k])
    {
        if (book[ver[k]]) continue;
        book[ver[k]] = true;
        stN[++top] = ver[k];
        stE[top] = edge[k];
        calcDiam(ver[k], sum + edge[k]);
        --top;
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1099.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    n = rd(); s = rd();
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
        add(v, u, w);
    }
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    findDeepest(1, 0);
    memset(vis, false, sizeof(vis));
    vis[deepest] = true;
    dfs(deepest, 0);
    memset(book, false, sizeof(book));
    stN[++top] = deepest;
    stE[top] = 0;
    diambak = diam;
    calcDiam(deepest, 0);
    printf("%d", ans);
    return 0;
}