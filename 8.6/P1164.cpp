#include <cstdio>
int f[10005];
int main() 
{
    f[0] = 1;
    int n, m, a;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        // 不愿意被覆盖？试试倒序 ->
        for (int j = m; j >= a; --j)
            f[j] += f[j - a];
    }
    printf("%d", f[m]);
    return 0;
}