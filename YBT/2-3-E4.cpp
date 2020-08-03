#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
const int MAXN = 5.2e5 + 5, Z = 26;
typedef long long LL;
using namespace std;
LL n, cost = 0, hsize[MAXN], ans = 0, p = 0; 
vector<int> e[MAXN];
LL nxt[MAXN][Z], tot, dfn[MAXN];
char str[MAXN];
bool eostr[MAXN];
void insert()
{
    int len = strlen(str), cur = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        int to = str[i] - 'a';
        if (!nxt[cur][to]) nxt[cur][to] = ++tot;
        cur = nxt[cur][to];
    }
    eostr[cur] = true;
}
void rebuild(int cur, int fa)
{
    for (int i = 0; i < Z; ++i)
    {
        int son = nxt[cur][i];
        if (!son) continue;
        if (eostr[son]) 
        {
            e[fa].push_back(son);
            rebuild(son, son);
        }
        else rebuild(son, fa);
    }
}
int calchsize(int cur)
{
    for (auto i: e[cur])
        hsize[cur] += calchsize(i) + 1;
    return hsize[cur];
}
void dfs(int cur)
{
    dfn[cur] = ++p;
    priority_queue<pair<int, int> > q;
    for (auto i: e[cur]) q.push(make_pair(-hsize[i], i)); // 优先走子树小的， 在子树之间转换不会减少答案的贡献
    while(q.size())
    {
        int to = q.top().second; q.pop();
        dfs(to);
        ans += dfn[to] - dfn[cur];
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-3-E4.in", "r", stdin);
#endif
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) 
    {
        scanf("%s", str);
        insert();
    }
    rebuild(0, 0); calchsize(0);
    dfs(0);
    printf("%lld", ans);
    return 0;
}