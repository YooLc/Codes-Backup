#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 55;
int a[MAXN][MAXN], f[MAXN][MAXN][MAXN];
int main() 
{
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            scanf("%d", &a[i][j]);
    for (int xa = 1; xa <= r; ++xa)
    {
        for (int ya = 1; ya <= c; ++ya)
        {
            for (int xb = 1; xb <= r; ++xb)
            {
                // 走的步数相同，则 xa + ya = xb + yb，否则无意义
                int yb = xa + ya - xb;
                if (yb < 1 || yb > c) continue;
                f[xa][ya][xb] += a[xa][ya] + a[xb][yb]; // 两个人位置不同，都可以取到
                if (xa == xb && ya == yb) f[xa][ya][xb] -= a[xb][yb]; // 两个人位置相同，就只能有一个人取到，这样能保证之前的路径也不会取到多次
                f[xa][ya][xb] += max(max(f[xa][ya - 1][xb], f[xa - 1][ya][xb]), // 右下到左上和左上到右下是等价的，和P1004一模一样
                                         max(f[xa - 1][ya][xb - 1], f[xa][ya - 1][xb - 1]));
            }
        }
    }
    printf("%d", f[r][c][r]);
    return 0;
}