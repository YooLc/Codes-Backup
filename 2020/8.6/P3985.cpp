#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e2 + 5, MAXM = 3e2 + 5, INF = 1e9 + 5;
int v[MAXN], p[MAXN], f[MAXN][MAXN][MAXM];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P3985.in", "r", stdin);
    freopen("P3985.out", "w", stdout);
#endif
    int n, W, mi = INF;
    scanf("%d %d", &n, &W);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &v[i], &p[i]), mi = min(mi, v[i]);
    // for (int i = 1; i <= n; ++i) v[i] -= mi - 1;
    /*
        f[i][j][k] 表示前 i 件物品中选择 j 件，一共有 k 元钱的最大重要度
        结果为 f[n][t \in Z][min(W - t * (mi - 1), MAXM - 1)]
    */
    memset(f, -1, sizeof(f));
    int uplim = MAXM - 5;
    for (int i = 0; i <= n; ++i) f[i][0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int k = uplim; k >= v; --k)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (k >= v[i]) 
                {
                    if (f[i][j - 1][k - v[i]] == -1) continue;
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - v[j]] + p[j]);
                    if (k<=10) 
                    {
                        printf("f[%d][%d][%d] f[%d][%d][%d]: %d, %d -> %d\n", i, j, k, i, j - 1, k - v[j], f[i][j - 1][k - v[j]] + p[i], f[i-1][j][k], f[i][j][k]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int w = 1; w <= W; ++w)
    {
        cout << "W = " << w << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                cout << f[i][j][w] << " ";
            cout << endl;
        }
        cout << endl;
    }
    for (int t = 1; t <= n; ++t)
        ans = max(ans, f[n][t][min(W, uplim)]);
    printf("%d", ans);
    return 0;
}
/*
5 10
2 800 -
5 400 -
5 300
3 400 -
2 200
*/