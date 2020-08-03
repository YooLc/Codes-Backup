#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const static int MAXN = 2e4 + 50, MAXM = 1e5 + 50;
int head[MAXN], _next[MAXM << 1], ver[MAXM << 1], tot;
int vis[MAXN], isAP[MAXN], low[MAXN], dfn[MAXN], index;
inline void add(int u, int v)
{
    ver[++tot] = v;
    _next[tot] = head[u];
    head[u] = tot;
}
void tarjan(int cur, int fa)
{
    dfn[cur] = ++index;
    low[cur] = dfn[cur];
    int child = 0;
    for(int k = head[cur]; k; k = _next[k])
    {
        int to = ver[k];
        if(to == fa) continue; // 注意判断
        if(!dfn[to])
        {
            tarjan(to, cur);
            low[cur] = min(low[cur], low[to]);
            if(low[to] >= dfn[cur] && cur != fa) isAP[cur] = true;
            if(cur == fa) child++;
        }
        else low[cur] = min(low[cur], dfn[to]); // a test
    }
    if(cur == fa && child >= 2) // 如果子树超过两个，搜索树根节点是割点（否则就会因搜索到不会增加子树数量）
        isAP[cur] = true;
}
int main()
{
    // 开够空间，注意输入
    freopen("input.in", "r", stdin);
    int n, m;
    n = rd(); m = rd();
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        u = rd(); v = rd();
        add(u, v); add(v, u);
    }
    for(int i = 1; i <= n; ++i)
        if(!dfn[i]) tarjan(i, i);
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(isAP[i]) cnt++;
    printf("%d\n", cnt);
    for(int i = 1; i <= n; ++i)
        if(isAP[i]) printf("%d ", i);
    return 0;
}