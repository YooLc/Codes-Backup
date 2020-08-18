#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 3e2 + 5, INF = 0x3f3f3f3f;
int e[MAXN][MAXN], dis[MAXN][MAXN], deepest[MAXN];
int n, s, diam, ans = INF;
int stk[MAXN], tot = 0;
bool vis[MAXN];
void dfs(int cur, int sum)
{
    if (sum == diam)
    {
        cout << cur << " " << sum << endl;
        for (int i  = 1; i <= tot; ++i)
            cout <<stk[i] << " ";
        cout <<  endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (cur == i || vis[i] || e[cur][i] >= INF) continue;
        vis[i] = true;
        stk[++tot] = i;
        dfs(i, sum + e[cur][i]);
        --tot;
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1099.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    memset(e, 0x3f, sizeof(e));
    scanf("%d %d", &n, &s);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u][v] = e[v][u] = w;
        e[i][i] = 0;
    }
    e[n][n] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = e[i][j];
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; ++i)
    {
        deepest[i] = i;
        for (int j = 1; j <= n; ++j)
            if (dis[i][deepest[i]] < dis[i][j]) deepest[i] = j;
    }
    diam = dis[deepest[1]][deepest[deepest[1]]];
    cout << diam <<  endl;
    stk[++tot] = deepest[1];
    dfs(deepest[1], 0);
    // tot = 0;
    // stk[++tot] = deepest[deepest[1]];
    // dfs(deepest[deepest[1]], 0);
    //printf("%d", ans);
    return 0;
}