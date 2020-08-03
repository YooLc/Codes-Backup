#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 5e5 + 5;
int f[MAXN];
int main()
{
    memset(f, -1, sizeof(f)); f[0] = 0;
    int n, m, mx = 0, a, k, val;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) 
    {
        scanf("%d %d", &k, &a);
        for (int j = 0; j <= MAXN; ++j)
        {
            if (f[j] >= 0) f[j] = a;
            else if (j < k || f[j - k] <= 0) f[j] = -1;
            else f[j] = f[j - k] - 1;
        }
    }
    for (int i = 1; i <= m; ++i) scanf("%d", &val), printf("%s\n", f[val] >= 0 ? "Yes" : "No");
    return 0;
}
/*
判断背包的可行性方法之一： f[i][j] 记录前 i 种硬币凑出 j 时，i 还剩几枚
例题: POJ 1742
bool 不行是因为损失了硬币枚数的信息，你必须再多循环一层
*/