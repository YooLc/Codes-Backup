#include <iostream>
#include <cstdio>
const int MAXV = 3e4 + 5, MAXN = 1e4 + 5;
int vol[MAXN], val[MAXN], dp[MAXV];
int main() 
{
    int V, n;
    scanf("%d %d", &V, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &vol[i], &val[i]), val[i] *= vol[i];
    for (int i = 1; i <= n; ++i)
        for (int j = V; j >= vol[i]; --j)
            dp[j] = std::max(dp[j], dp[j - vol[i]] + val[i]);
    printf("%d", dp[V]);
    return 0;
}