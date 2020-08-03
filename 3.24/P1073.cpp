#pragma optmize(2)
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const static int MAXN = 6e4 + 50, MAXM = 1e5 + 50, OPT = 150;
int head[MAXN], _next[MAXN << 1], ver[MAXN << 1], tot, ans;
int val[MAXN], n, m;
bool vis[MAXM << 1][300];
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
    _next[tot] = head[u];
    head[u] = tot;
}
inline void bfs()
{
    priority_queue<pii> q;
    int s = 1, t = n;
    q.push(make_pair(-val[s], s)); // 买
    while(!q.empty())
    {
        pii pre = q.top();
        q.pop();
        if(pre.second == t) { ans = max(ans, pre.first); }
        for(int k = head[pre.second]; k; k = _next[k])
        {
            int to = ver[k];
            if(-val[to] > pre.first && !vis[k][-val[to] + OPT])
            {
                vis[k][-val[to] + OPT] = true;
                q.push(make_pair(-val[to], to)); // 本地价格更低，更新
            }
            if(!vis[k][pre.first + OPT]) 
            {
                vis[k][pre.first + OPT] = true;
                q.push(make_pair(pre.first, to)); // 去了不买
            }
            if(pre.first + val[to] >= 0 && !vis[k][pre.first + val[to] + OPT] && pre.first < 0)
            {
                vis[k][pre.first + val[to] + OPT] = true;
                q.push(make_pair(pre.first + val[to], to)); // 卖掉赚差价
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("trade9.in", "r", stdin);
#endif
    n = rd(); m = rd();
    for(int i = 1; i <= n; ++i) val[i] = rd();
    for(int i = 1; i <= m; ++i)
    {
        int u, v, opt;
        u = rd(); v = rd(); opt = rd();
        if(opt == 2) add(v ,u);
        add(u, v);
    }
    bfs();
    printf("%d", max(ans, 0));
    return 0;
}