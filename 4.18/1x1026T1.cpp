#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int MAXN = 150, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int r, c, sx, sy, tx, ty, minpath, cnt;
char mapp[MAXN][MAXN];
bool vis[MAXN][MAXN];
double t, ans;
struct State
{
    int cx, cy, ud, rl;
    State() { ud = rl = 0; }
};
void bfs()
{
    memset(vis, false, sizeof(vis));
    minpath = -1; cnt = 0;
    State s;
    s.cx = sx; s.cy = sy;
    queue<State> q;
    q.push(s);
    while (q.size())
    {
        State pre = q.front();
        q.pop();
        if (pre.cx == tx && pre.cy == ty)
        {
            if (minpath != -1 && pre.ud + pre.rl - minpath > 100) return;
            minpath = pre.ud + pre.rl;
            if (pre.ud) ans = max(ans, (t - pre.rl) / (double)pre.ud);
            continue;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = pre.cx + dx[i];
            int ny = pre.cy + dy[i];
            if (!(nx == tx && ny == ty) && vis[nx][ny]) continue;
            if (mapp[nx][ny] == '#' || nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            vis[nx][ny] = true;
            State nxt;
            nxt.cx = nx; nxt.cy = ny;
            if (dx[i]) nxt.ud = pre.ud + 1, nxt.rl = pre.rl;
            if (dy[i]) nxt.ud = pre.ud, nxt.rl = pre.rl + 1;
            q.push(nxt);
        }
    }
}
void solve()
{
    memset(mapp, 0, sizeof(mapp));
    cin >> t >> r >> c;
    ans = 0;
    getchar();
    for (int i = 0; i < r; ++i)
    {
        gets(mapp[i]);
        for (int j = 0; j < c; ++j)
        {
            if (mapp[i][j] == 'S') { sx = i; sy = j; }
            if (mapp[i][j] == 'E') { tx = i; ty = j; }
        }
    }
    bfs();
    printf("%.5f\n", ans);
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}