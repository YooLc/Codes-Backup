#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const static int MAXN = 1e5 + 50;
int head[MAXN], _next[MAXN << 1], ver[MAXN << 1], edge[MAXN], tot;
int len[MAXN][2], cost[MAXN], dp[MAXN];
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
void calcLenth(int cur)
{
    int len1 = 0, len2 = 0;
    for (int k = head[cur]; k; k = _next[k])
    {
        calcLenth(ver[k]);
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
void _dp(int cur)
{
    for (int k = head[cur]; k; k = _next[k])
    {
        int to = ver[k];
        if(len[to][0] + edge[k] == len[cur][0]) // 在最长距离子树
            dp[to] = max(dp[cur], len[cur][1]) + edge[k];
        else
            dp[to] = max(dp[cur], len[cur][0]) + edge[k];
        _dp(to);
    }
}
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        init();
        for (int i = 2; i <= n; ++i)
        {
            int fa, w;
            scanf("%d %d", &fa, &w);
            add(fa, i, w);
        }
        calcLenth(1);
        _dp(1);
        for (int i = 1; i <= n; ++i)
            printf("%d\n", max(dp[i], len[i][0]));
    }
    return 0;
}