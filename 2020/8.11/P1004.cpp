#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL a[11][11], f[11][11][11][11];
int main() 
{
    int n, x, y, num;
    scanf("%d", &n);
    while (~scanf("%d %d %d", &x, &y, &num))
    {
        if (!(x + y + num)) break;
        a[x][y] = num;
    }
    for (int xa = 1; xa <= n; ++xa)
    {
        for (int ya = 1; ya <= n; ++ya)
        {
            for (int xb = 1; xb <= n; ++xb)
            {
                for (int yb = 1; yb <= n; ++yb)
                {
                    f[xa][ya][xb][yb] += a[xa][ya] + a[xb][yb]; // 两个人位置不同，都可以取到
                    if (xa == xb && ya == yb) f[xa][ya][xb][yb] -= a[xb][yb]; // 两个人位置相同，就只能有一个人取到，这样能保证之前的路径也不会取到多次
                    f[xa][ya][xb][yb] += max(max(f[xa][ya - 1][xb][yb - 1], f[xa - 1][ya][xb][yb - 1]),
                                             max(f[xa - 1][ya][xb - 1][yb], f[xa][ya - 1][xb - 1][yb]));
                }
            }
        }
    }
    printf("%d", f[n][n][n][n]);
    return 0;
}