#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <ctime>
#include <algorithm>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
const int MAXN = 5e4 + 5, MAXM = 1e5 + 5, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM << 1], ver[MAXM << 1], edge[MAXM << 1], tot;
int n, m, rela[7], dis[MAXN];
int e[7][7];
bool vis[MAXN];
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    while(q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int k = head[u]; k; k = nxt[k])
        {
            if (dis[ver[k]] <= dis[u] + edge[k]) continue;
            dis[ver[k]] = dis[u] + edge[k];
            q.push(make_pair(-dis[ver[k]], ver[k]));
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-2-E4.in", "r", stdin);
    freopen("3-2-E4.out", "w", stdout);
#endif
    int n, m;
    n = rd(); m = rd();
    rela[1] = 1;
    for (int i = 2; i <= 6; ++i) rela[i] = rd();
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
        add(v, u, w);
    }
    // 求出亲戚两两之间的最短路
    for (int i = 1; i <= 5; ++i)
    {
        dijkstra(rela[i]);
        for (int j = 1; j <= 6; ++j)
            e[i][j] = e[j][i] = dis[rela[j]];
    }
    // 这里只需要产生一个访问顺序的全排列，暴力枚举就行了 = =
    // 因为从 1 出发，所以只需要枚举后面五个数的全排列
    int ans = INF;
    for (int i = 1; i <= 6; ++i) rela[i] = i;
    for (int i = 1; i <= 120; ++i)
    {
        int res = 0;
        for (int j = 1; j < 6; ++j) res += e[rela[j]][rela[j + 1]];
        ans = min(res, ans);
        next_permutation(rela + 2, rela + 7);
    }
    printf("%d\n", ans);
    return 0;
}