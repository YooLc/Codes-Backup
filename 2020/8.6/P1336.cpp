#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 205; 
typedef long long LL;
LL f[MAXN];
inline LL qpow(int a, int n)
{
    LL base = a, ret = 1;
    while(n)
    {
        if (n & 1) ret *= base;
        base *= base;
        n >>= 1;
    }
    return ret;
}
int main() 
{
    memset(f, 0x3f, sizeof(f));
    f[0] = 0; // 不肝论文不耗时间
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &a, &b);
        // 多重背包，逐个分解，每个课程最多放 n 篇论文
        // 但是论文的时间是指数递增的，不能二进制分解 (
        for (int j = n; j >= 0; --j)
            for (int k = 1; k <= j; ++k)
                f[j] = min(f[j], f[j - k] + 1LL * qpow(k, b) * a);
    }
    printf("%lld", f[n]);
    return 0;
}