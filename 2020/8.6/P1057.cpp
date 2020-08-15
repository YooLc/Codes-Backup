#include <iostream>
#include <cstdio>
const int MAXN = 35;
int f[MAXN][MAXN];
int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    f[0][1] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j == 1) f[i][j] += f[i - 1][n] + f[i - 1][j + 1];
            else if (j == n) f[i][j] += f[i - 1][1] + f[i - 1][j - 1];
            else f[i][j] += f[i - 1][j - 1] + f[i - 1][j + 1];
        }
    }
    printf("%d", f[m][1]);
    return 0;
}