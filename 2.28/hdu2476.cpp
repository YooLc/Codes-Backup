#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const static int MAXN = 1e2 + 50;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN], ans[MAXN];
void solve()
{
    int lena = strlen(a + 1);
    memset(dp, 0, sizeof(dp));
    // dp[i][j] 表示从空串转移到 b[i..j] 的最小步数
    for (int t = 1; t <= lena; ++t)
    {
        for (int s = t; s >= 1; --s)
        {
            dp[s][t] = dp[s + 1][t] + 1;
            for (int k = s + 1; k <= t; k++)
                if(b[s] == b[k])
                    dp[s][t] = min(dp[s][t], dp[s + 1][k] + dp[k + 1][t]);
        }
    }
    for (int i = 1; i <= lena; ++i) ans[i] = dp[1][i];
    for (int i = 1; i <= lena; ++i)
    {
        if(a[i] == b[i])
            ans[i] = (i == 1) ? 0 : ans[i - 1];
        else 
            for (int j = 1; j < i; ++j)
                ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
    }
    printf("%d\n", ans[lena]);
}
int main()
{
    freopen("in.txt", "r", stdin);
    while(~scanf("%s %s", a + 1, b + 1))
        solve();
    return 0;
}