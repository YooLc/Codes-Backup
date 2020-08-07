#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const static int MAXN = 1e5 + 50;
int head[MAXN], _next[MAXN << 1], ver[MAXN << 1], edge[MAXN], tot;
int len[MAXN][2], cost[MAXN], dp[MAXN], val[MAXN];
void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    _next[tot] = head[u];
    head[u] = tot;
}
void init()
{
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(_next, 0, sizeof(_next));
    memset(len, 0, sizeof(len));
    memset(dp, 0, sizeof(dp));
}
void calcLenth(int cur, int fa)
{
    int len1 = 0, len2 = 0;
    for (int k = head[cur]; k; k = _next[k])
    {
        if(ver[k] == fa) continue;
        calcLenth(ver[k], cur);
        int curLen = len[ver[k]][0] + edge[k];
        if(curLen >= len1)
        {
            len2 = len1;
            len1 = curLen;
        }
        else if(curLen > len2)
        {
            len2 = curLen;
        }
    }
    len[cur][0] = len1;
    len[cur][1] = len2;
}
void _dp(int cur, int fa)
{
    for (int k = head[cur]; k; k = _next[k])
    {
        int to = ver[k];
        if(to == fa) continue;
        if(len[to][0] + edge[k] == len[cur][0]) // 在最长距离子树
            dp[to] = max(dp[cur], len[cur][1]) + edge[k];
        else
            dp[to] = max(dp[cur], len[cur][0]) + edge[k];
        _dp(to, cur);
    }
}
int main()
{
    init();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 2; i <= n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v, 1);
        add(v, u, 1);
    }
    calcLenth(1, 1);
    _dp(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, max(dp[i], len[i][0]) * val[i]);
    printf("%d", ans);
    return 0;
}