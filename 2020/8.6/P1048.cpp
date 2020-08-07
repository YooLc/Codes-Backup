#include <iostream>
#include <cstdio>
const int MAXN = 1e3 + 5;
int f[MAXN];
int main() 
{
    int t, m, time, val;
    scanf("%d %d", &t, &m);
    /*
        f[j] 表示时间为 t 时装的采来草药的最大价值
        转移方程： 0-1背包
        输出答案： f[t]
    */
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &time, &val);
        for (int j = t; j >= time; --j)
            f[j] = std::max(f[j], f[j - time] + val);
    }
    printf("%d", f[t]);
    return 0;
}