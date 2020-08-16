#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e2 + 5;
int arr[MAXN], f[2][MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
    for (int i = 1; i <= n; ++i) f[0][i] = f[1][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (arr[j] < arr[i])
                f[0][i] = max(f[0][i], f[0][j] + 1);
    for (int i = n; i >= 1; --i)
        for (int j = n; j > i; --j)
            if (arr[j] < arr[i])
                f[1][i] = max(f[1][i], f[1][j] + 1);
    /*
        f[0][i] + f[1][i + 1] 不一定是正确的
        f[0][i] + f[1][i] - 1 才能保证正确性
    */
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, f[0][i] + f[1][i] - 1);
    printf("%d", n - ans);
    return 0;
}