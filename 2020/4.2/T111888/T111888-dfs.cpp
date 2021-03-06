#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 150;
struct Comp
{
    int x, y, id;
} v[MAXN];
int n, tx, ty, ans[MAXN], tot, flag, depthLim;

// 优化搜索顺序
inline int dist(Comp &t) { return abs(tx - t.x) + abs(ty - t.y); }
bool cmp(Comp &a, Comp &b) { return dist(a) < dist(b); }

void dfs(int cur, int sx, int sy)
{
    if(sx == tx && sy == ty) { flag = 1; return; }
    if(cur == depthLim + 1) { return; } 
    // Use this one
    if(!flag) 
    {
        ans[++tot] = v[cur].id;
        dfs(cur + 1, sx + v[cur].x, sy + v[cur].y);
        if(!flag) --tot;
    }
    // Skip this one
    if(!flag) dfs(cur + 1, sx, sy);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d %d", &v[i].x, &v[i].y), v[i].id = i;
    scanf("%d %d", &tx, &ty);
    sort(v + 1, v + 1 + n, cmp);
    for(int i = 1; i <= n; ++i)
    {
        depthLim = i;
        dfs(1, 0, 0);
        if(flag) break;
    }
    if(tot) { cout << tot << endl; for(int i = 1; i <= tot; ++i) printf("%d ", ans[i]); }
    else printf("impossible\n");
    return 0;
}