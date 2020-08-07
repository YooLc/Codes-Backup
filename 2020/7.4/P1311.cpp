#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 2e5 + 5, MAXK = 55;
int n, k, p;
int sum[MAXN];
int main() 
{
    int ans = 0;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ans += sum[a];
        if (b <= p) for (int i = 0; i < k; ++i) sum[i]++;
    }
    printf("%d", ans);
    return 0;
}