#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 150;
int n, tx, ty;
struct Complex
{
    int x, y, id;
} v[MAXN];
int ans[MAXN], tot;
bool flag = false;
void dfs(int cur, int sx, int sy)
{
    if(sx == tx && sy == ty) { flag = true; return; }
    if(cur == n + 1) { return; } 
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
    freopen("T111888.in", "r", stdin);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d %d", &v[i].x, &v[i].y), v[i].id = i;
    scanf("%d %d", &tx, &ty);
    dfs(1, 0, 0);
    if(tot) for(int i = 1; i <= tot; ++i) printf("%d ", ans[i]);
    else printf("impossible\n");
    return 0;
}