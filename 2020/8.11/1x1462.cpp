#include <iostream>
#include <cstdio>
typedef long long LL;
const LL MAXN = 4e3 + 5, MOD = 2147483648;
LL f[MAXN];
int main() 
{
    int n;
    scanf("%d", &n);
    f[0] = 1;
    // 要多个正整数，因此 i 的范围 [1, n)
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n; ++j) // 可以多个组合，正着取
            f[j] = (f[j] + f[j - i]) % MOD;
    printf("%lld", f[n]);
    return 0;
}