#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define THE_BEST_PONY Rainbow_Dash
using namespace std;
const int MAXN = 505, INF = 0x3f3f3f3f;
vector<int> lineOf[MAXN];
int d[MAXN][MAXN];
int main()
{
    freopen("1x1332.in", "r", stdin);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= MAXN; ++i) d[i][i] = 0;
    int m, n, t = 1, stop, ans = INF;
    scanf("%d %d", &m, &n);
    while(~scanf("%d", &stop))
    {
        lineOf[stop].push_back(t);
        char ch = getchar();
        if (ch == 10) t++; // '\n'
        else if (!~ch) break; // EOF = -1
    }
    for (int k = 1; k <= n; ++k)
    {
        int len = lineOf[k].size();
        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j)
                d[lineOf[k][i]][lineOf[k][j]] = 1;
    }
    for (int k = 1; k <= m; ++k)
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 0; i < lineOf[1].size(); ++i)
        for (int j = 0; j < lineOf[n].size(); ++j)
            ans = min(ans, d[lineOf[1][i]][lineOf[n][j]]);
    if (ans == INF) printf("NO");
    else printf("%d", ans);
    return 0;
}