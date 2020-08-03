#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 5, mod = 1e9 + 7;
string str;
int dp[MAXN][20][3], s[20], ans[20];
int main()
{
    #ifndef ONLINE_JUDGE
	    freopen("LOJ2575.in", "r", stdin);
    #endif
	int n, k;
	cin >> n >> k >> str;
	int len = str.size();
	for (int i = 0; i < len; ++i)
		s[i + 1] = str[i] == 'N' ? 0 : str[i] == 'O' ? 1 : 2;
	for (int i = 1; i <= len; ++i) 
    {
		for (int j = 1; j <= n; ++j) 
        {
			dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + 1;
			dp[i][j][0] = max(max(dp[i - 1][j][0], dp[i][j - 1][0]), max(dp[i - 1][j][1], dp[i][j - 1][1]));
		}
		ans[dp[i][n][0]]++;
		ans[dp[i][n][1]]++;
	}
	for (int i = 0; i <= k;++i)
		printf("%d\n", ans[i]);
	return 0;
}