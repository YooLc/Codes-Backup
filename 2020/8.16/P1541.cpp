#include <iostream>
#include <cstdio>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 355, MAXM = 125;
int f[MAXN][MAXN];
int val[MAXN], card[MAXM];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1541.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, m;
    n = rd(); m = rd();
    for (int i = 1; i <= n; ++i) 
    {
        val[i] = rd();
        f[i][i] = val[i];
    }
    for (int i = 1; i <= m; ++i) card[rd()]++;
    /*
        f[i][j][k] 表示前 i 种卡，从 j 到 k 的最大分数
    */
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j + i <= n; ++j)
        {
            for (int k = 1; k <= 4; ++k)
            {
                for (int t = 1; t <= card[k]; ++t)
                {
                    f[i][i + j] = max(f[i][i + j], f[i][i + j - k] + val[j]);
                }
            }   
        }
        for (int j = 1; j <= n; ++j)
            printf("%2d ", f[i][j]);
        cout << endl;
    }
    printf("%d", f[1][n]);
    return 0;
}
/*
6 16 30 32 38 40 56 43 73
0 10 24 26 34 34 52 49 67
0 0 14 16 24 32 42 39 57 
0 0 0 2 10 18 36 25 53
0 0 0 0 8 16 34 39 51
0 0 0 0 0 8 26 31 48
0 0 0 0 0 0 18 23 40
0 0 0 0 0 0 0 5 22
0 0 0 0 0 0 0 0 17 
*/