#include <stdio.h>
int n, m, a, f[105][105];
void main() 
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i) f[i][0] = 1;
    /*
        f[i][j] 表示前 i 种花摆 j 盆的方案数
        初态: f[0..n][0] = 1 表示不摆花有 1 种方案，或者在循环中把 0 带上
        递推方程:  f[i][j] = Sigma{ f[i - 1][j - (0..a[i]) ] } 表示  0..a[i] 盆该种花和前面的依次组合
        末态: f[n][m]
    */
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= a; ++k)
                if (j >= k) f[i][j] = (f[i][j] + f[i - 1][j - k]) % 1000007;
    }   
    printf("%d", f[n][m]);
}