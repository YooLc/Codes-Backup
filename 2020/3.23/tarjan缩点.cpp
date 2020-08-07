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
const static int MAXN = 1e4 + 50, MAXM = 1e5 + 50;
int head[MAXN], _next[MAXM << 1], ver[MAXM << 1], tot;
int low[MAXN], dfn[MAXN], index;
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
        if(!dfn[to])
        {
            tarjan(to, cur);
            low[cur] = min(low[cur], low[to]);
            if(low[to] >= dfn[cur] && cur != fa) isAP[cur] = true;
            if(cur == fa) child++;
        }
        else low[cur] = min(low[cur], dfn[to]);
    }
    if(cur == fa && child >= 2) // 如果子树超过两个，搜索树根节点是割点（否则就会因搜索到不会增加子树数量）
        isAP[cur] = true;
}
int main()
{
    
    return 0;
}
