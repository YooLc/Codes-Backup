#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 5e2 + 5, MAXM = 5e2 + 5;
int n, m, a[MAXN][MAXM], f[MAXN][MAXM], cur = 0;
int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0};
bool vis[MAXM];
void dfs(int curx, int cury, int id)
{
    f[curx][cury] = id;
    for (int i = 0; i < 4; ++i)
    {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if (curx < 1 || cury < 1 || curx > n || cury > m) continue;
        if (a[nx][ny] >= a[curx][cury]) continue;
        dfs(nx, ny, id);
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1514.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    priority_queue<pair<int, int> > q;
    n = rd(); m = rd();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = rd();
    for (int i = 1; i <= m; ++i) q.push(make_pair(a[1][i], i));
    while (q.size())
    {
        ++cur;
        dfs(1, q.top().second, cur);
        q.pop();
    } 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << f[i][j] << " ";
        cout << endl;
    }
    int ans = 0, ncnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (!f[n][i]) ncnt++;
        else if (!vis[f[n][i]]) ans++, vis[f[n][i]] = true;
    }
    if (ncnt) printf("0\n%d", ncnt);
    else printf("1\n%d", ans);
    return 0;
}