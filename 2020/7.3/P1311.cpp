#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 2e5 + 5, MAXK = 55;
int a[MAXN], b[MAXN];
int sum[MAXN], last[MAXN][MAXK], cnt[MAXN], dp[MAXN];
int main() 
{
    memset(last, -1, sizeof(last));
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &a[i], &b[i]);
        sum[i] = sum[i - 1] + int(b[i] <= p);
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
            last[i][j] = last[i - 1][j];
        last[i][a[i - 1]] = i - 1;
        if (last[i][a[i]] != -1) cnt[i] = cnt[last[i][a[i]]] + 1;
        else cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (last[i][a[i]] != -1)
            dp[i] = dp[i - 1] + cnt[i];
    }
    printf("%d", dp[n]);
    return 0;
}