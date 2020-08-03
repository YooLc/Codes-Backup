#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const static int MAXN = 10, MAXXS = (1 << MAXN) - 1;
LL dp[MAXN][MAXN * MAXN][MAXXS];
inline int knum(int state)
{
    int num = 0;
    while(state)
    {
        num++;
        state -= state & (-state);
    }
    return num;
}
inline bool aval(int pre, int cur)
{
    if(cur << 1 & pre) return false;
    if(cur & pre) return false;
    if(cur >> 1 & pre) return false;
    if(cur << 1 & cur) return false;
    if(cur >> 1 & cur) return false;
    return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("1.txt","w",stdout);
    #endif
    int n, k;
    scanf("%d %d", &n, &k);
    LL sum = 0, MAXS = (1 << n) - 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int preState = 0; preState <= MAXS; ++preState)
            for (int curState = 0; curState <= MAXS; ++curState)
                if(aval(preState, curState))
                    for(int j = 0; j < k; ++j)
                        dp[i][knum(curState) + j][curState] += dp[i - 1][j][preState];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= MAXS; ++j)
            sum += dp[i][k][j];
    printf("%lld", sum);
    return 0;
}