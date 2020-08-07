#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2e5 + 5;
int f[MAXN];
int main() 
{
    int v, n, vol;
    scanf("%d\n%d", &v, &n);
    /*
        f[j] 表示容量为 j 时装的物品的最大体积
        转移方程： 0-1背包
        输出答案： v - f[v]
    */
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &vol);
        for (int j = v; j >= vol; --j)
            f[j] = max(f[j], f[j - vol] + vol);
    }
    printf("%d", v - f[v]);
    return 0;
}