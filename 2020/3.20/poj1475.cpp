#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const static int MAXN = 30, MAXM = 30, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
const char dops[2][6] = {"ewsn","EWSN"};
char mapp[MAXN][MAXM];
int vis[MAXN][MAXN][4];
bool v[MAXN][MAXN];
int r, c, tx, ty; 
string ans;
struct State
{
    State() {x = y = mx = my = -1; ops = "";}
    int x, y, mx, my;
    string ops;
}start;
inline State getDis(int sx, int sy, int tx, int ty, int bx, int by)
{
    // sx, sy -> start x, start y
    // tx, ty -> target x, target y
    // bx, by -> box x, box y
    memset(v, 0, sizeof(v));
    State s, none;
    if(tx < 0 || ty < 0 || tx >= r || ty >= c || mapp[tx][ty] == '#') return none;
    s.x = sx, s.y = sy;
    queue<State> q;
    q.push(s);
    v[sx][sy] = v[bx][by] = true;
    while(q.size())
    {
        State pre = q.front(); q.pop();
        if(pre.x == tx && pre.y == ty) return pre;
        for(int i = 0; i < 4; ++i)
        {
            int nx = pre.x + dx[i];
            int ny = pre.y + dy[i];
            if(mapp[nx][ny] == '#' || nx < 0 || ny < 0 || nx >= r || ny >= c || v[nx][ny]) continue;
            v[nx][ny] = true;
            State nxt;
            nxt.x = nx; nxt.y = ny;
            nxt.ops = pre.ops + dops[0][i];
            q.push(nxt);
        }
    }
    return none;
}
inline bool isBetter(string a, string b)
{
    // is b better than a
    int upCounta, smallCounta, lena = a.size();
    int upCountb, smallCountb, lenb = b.size();
    for(int i = 0; i < lena; ++i)
    {
        if(a[i] >= 'A' && a[i] <= 'Z') upCounta++;
        else smallCounta++;
    }
    for(int i = 0; i < lenb; ++i)
    {
        if(b[i] >= 'A' && b[i] <= 'Z') upCountb++;
        else smallCountb++;
    }
    if(upCountb < upCounta) return true;
    else if(upCounta == upCountb && smallCountb < smallCounta) return true;
    return false;
}
void bfs()
{
    queue<State> q;
    q.push(start);
    while(q.size())
    {
        State pre = q.front(); q.pop();
        //cout << pre.ops <<" " << pre.x<<" "<<pre.y<<endl;
        for(int i = 0; i < 4; ++i)
        {
            int nx = pre.x + dx[i];
            int ny = pre.y + dy[i];
            if(mapp[nx][ny] == '#' || nx < 0 || ny < 0 || nx >= r || ny >= c || vis[nx][ny][i] >= 5) continue;
            // Move man to the direction excactly the box are being pushed.
            // And connot overpass the box.
            State dis = getDis(pre.mx, pre.my, pre.x - dx[i], pre.y - dy[i], pre.x, pre.y);
           if(dis.x == -1) continue; // Cannot reach
            vis[nx][ny][i]++;
            State nxt;
            nxt.x = nx; nxt.y = ny;
            nxt.mx = pre.x; nxt.my = pre.y;
            nxt.ops = pre.ops + dis.ops + dops[1][i];
            if(nxt.x == tx && nxt.y == ty)
            {
                if(ans != "" && isBetter(ans, nxt.ops)) ans = nxt.ops;
                else if(ans == "") ans = nxt.ops;
            }
            q.push(nxt);
        }
    }
}
inline void solve()
{
    memset(vis, 0, sizeof(vis));
    ans = "";
    for(int i = 0; i < r; ++i)
    {
        scanf("%s", mapp[i]);
        for(int j = 0; j < c; ++j)
        {
            if(mapp[i][j] == 'S') start.mx = i, start.my = j;
            if(mapp[i][j] == 'B') start.x = i, start.y = j;
            if(mapp[i][j] == 'T') tx = i, ty = j;
        }
    }
    bfs();
    if(ans != "") cout << ans << endl << endl;
    else cout << "Impossible." << endl << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int Tcnt = 0;
    while(~scanf("%d %d", &r, &c))
    {
        if(r == 0 && c == 0) break;
        cout << "Maze #" << (++Tcnt) << endl;
        solve();
    }
    return 0;
}