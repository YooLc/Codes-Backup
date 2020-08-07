#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 5005, MAXM = 5005, MAXK = 1e6 + 5, INF = 0x3f3f3f3f;
int head[MAXN], ver[MAXM], nxt[MAXM], tot, n, m, k, dis[2][MAXN];
bool ans[MAXN];
struct Query { int to, s, id; };
vector<Query> qri[MAXN];
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f; 
}
inline void add(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void bfs(int s)
{
    dis[0][s] = 0; // dis[i][s][j] i -> j, s: even or odd
    queue<pair<int, int> >q;
    q.push(make_pair(0, s));
    while(q.size())
    {
        int step = q.front().first, cur = q.front().second;
        q.pop();
        for (int k = head[cur]; k; k = nxt[k])
        {
            int p = (step + 1) & 1, to = ver[k];
            if (dis[p][to] > step + 1)
            {
                dis[p][to] = step + 1;
                q.push(make_pair(step + 1, to));
            }
        }
    }
    if (!head[s]) dis[0][s] = INF;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
#endif
    int u, v;
    n = rd(); m = rd(); k = rd();
    for (int i = 1; i <= m; ++i)
    {
        u = rd(); v = rd();
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= k; ++i)
    {
        int u, v, s;
        u = rd(); v = rd(); s = rd();
        qri[u].push_back(Query{v, s, i});
    }
    for (int i = 1; i <= n; ++i)
    {
        if(qri[i].empty()) continue;
        memset(dis, 0x3f, sizeof(dis));
        bfs(i);
        for (int j = 0; j < qri[i].size(); ++j)
        {
            Query t = qri[i][j];
            int dist = dis[t.s & 1][t.to];
            if (i == t.to && t.s == 0) ans[t.id] = true;
            else if (dist < INF && dist <= t.s) ans[t.id] = true;
            else ans[t.id] = false;
        }
    }
    for (int i = 1; i <= k; ++i) puts(ans[i] ? "TAK" : "NIE");
    return 0;
}