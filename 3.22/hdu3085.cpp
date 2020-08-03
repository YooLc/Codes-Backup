#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const static int MAXN = 1e3 + 5, MAXM = 2e5 + 5;
int ver[MAXM], edge[MAXM], _next[MAXM], head[MAXN], tot;
int cost[MAXN], vis[MAXN][105], ans, T, n, m;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) { t = (t * 10) + (ch ^ 48); ch = getchar(); }
    return t * f;
}
struct State
{
    int cur, gas, cost;
};
bool operator < (const State &a, const State &b) { return a.cost > b.cost; }
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    _next[tot] = head[u];
    head[u] = tot; 
}
inline bool search(int s, int t, int C)
{
    memset(vis, 0, sizeof(vis));
    std::priority_queue<State> q;
    State start;
    start.cur = s; start.gas = 0; start.cost = 0;
    q.push(start);
    while(q.size())
    {
        State pre = q.top(); q.pop();
        if(pre.cur == t)
        {
            ans = pre.cost;
            return true;
        }
        if(pre.gas + 1 <= C) // Buy gas here
        {
            State nxt;
            nxt.cur = pre.cur;
            nxt.gas = pre.gas + 1;
            nxt.cost = pre.cost + cost[pre.cur];
            q.push(nxt);
        }
        for(register int k = head[pre.cur]; k; k = _next[k])
        {
            int to = ver[k];
            if(edge[k] <= pre.gas && !vis[to][pre.gas - edge[k]]) // Able to drive
            {
                vis[to][pre.gas - edge[k]] = true;
                State nxt;
                nxt.cur = to;
                nxt.gas = pre.gas - edge[k];
                nxt.cost = pre.cost;
                q.push(nxt);
            }
        }
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("hdu3085.txt", "r", stdin);
    freopen("test.txt","w",stdout);
#endif
    n = rd(); m = rd();
    for(int i = 0; i < n; ++i) 
        cost[i] = rd();
    for(register int i = 1; i <= m; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
        add(v, u, w);
    }
    T = rd();
    while(T--)
    {
        int c, s, t;
        c = rd(); s = rd(); t = rd();
        if(search(s, t, c)) printf("%d\n", ans);
        else printf("impossible\n");
    }
    return 0;
}