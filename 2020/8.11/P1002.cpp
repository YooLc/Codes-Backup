#include <iostream>
#include <cstdio>
long long f[25][25];
int n, m, x, y;
inline int abs(int x) { return x >= 0 ? x : -x; }
inline bool check(int sx, int sy)
{
    int col = abs(sy - y);
    int row = abs(sx - x);
    return (col == 2 && row == 1) | (col == 1 && row == 2) | (!col && !row);
}
int main() 
{
    scanf("%d %d %d %d", &n, &m, &x, &y);
    ++n, ++m, ++x, ++y;
    f[1][1] = 1;
    for (int i = 1; i <= n + 1; ++i)
        for  (int j = 1; j <= m + 1; ++j)
            if (!check(i, j) && !(i == 1 && j == 1)) 
                f[i][j] = f[i - 1][j] + f[i][j - 1];
    printf("%lld", f[n][m]);
    return 0;
}