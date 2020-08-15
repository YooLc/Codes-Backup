#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 25;
int e[MAXN][MAXN], val[MAXN], f[MAXN], pre[MAXN], n;
bool vis[MAXN];
inline void printPath(int cur)
{
    if (cur == pre[cur]) { printf("%d ", cur); return; }
    printPath(pre[cur]);
    printf("%d ", cur);
}
inline void dfs(int cur, int fa, int sum)
{
    if (sum + val[cur] > f[cur])
    {
        f[cur] = sum + val[cur];
        pre[cur] = fa;
    }
    for (int to = 1; to <= n; ++to)
    {
        if (!e[cur][to] || vis[to]) continue;
        vis[to] = true;
        dfs(to, cur, sum + val[cur]);
        vis[to] = false;
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P2196.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            scanf("%d", &e[i][j]);
    for (int i = 1; i <= n; ++i) dfs(i, i, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] != ans) continue;
        printPath(i);
        break;
    }
    printf("\n%d", ans);
    return 0;
}