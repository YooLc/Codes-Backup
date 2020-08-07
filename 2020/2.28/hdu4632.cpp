#include <iostream>
#include <cstring>
using namespace std;
const static int MAXN = 1e3 + 5, MOD = 10007;
char str[MAXN];
int dp[MAXN][MAXN];
void solve()
{
    memset(dp, 0, sizeof(dp));
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        dp[i][i] = 1;
    for (int l = 2; l <= len; ++l)
    {
        for(int i = 0; i + l - 1 < len; ++i)
        {
            int j = i + l - 1;
            if(str[i] == str[j])
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % MOD;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
        }
    }
    printf("%d\n", dp[0][len - 1] % MOD);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) printf("Case %d: ", i), solve();
    return 0;
}