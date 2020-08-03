#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 50;
int d[MAXN][MAXN];
int main()
{
    memset(d, 0x3f, sizeof(d));
    d[1][1] = 0;
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = d[v][u] = w;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << d[1][i] << endl;
    return 0;
}
/*
5 5
1 2 100
3 2 100
1 5 1
5 4 1
4 3 1
*/