#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1.5e3 + 10, dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char mapp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int galaxy[MAXN * MAXN], r, c;
inline void add(int sx, int sy)
{
    int size = 1; vis[sx][sy] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    while (q.size())
    {
        int prex = q.front().first, prey = q.front().second; q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nx = prex + dx[i];
            int ny = prey + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || vis[nx][ny] || mapp[nx][ny] != '*') continue;
            size++; vis[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    galaxy[size]++;
}
int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) scanf("%s", mapp[i]); 
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (mapp[i][j] == '*' && !vis[i][j]) add(i, j);
    int ans = 0, mx = 0;
    for (int i = 1; i < MAXN * MAXN; ++i) if (galaxy[i]) ans++, mx = max(mx, galaxy[i] * i);
    printf("%d %d", ans, mx);
    return 0;
}