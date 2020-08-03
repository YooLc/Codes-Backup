#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1005, INF = 0x3f3f3f3f;
int  m, n;
LL f[MAXN][MAXN], ans;
vector<int> sta[105];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1x1332.in", "r", stdin);
#endif
    int t = 1, stop;
    scanf("%d %d", &m, &n);
    while(~scanf("%d", &stop))
    {
        sta[t].push_back(stop);
        char ch = getchar();
        if (ch != ' ') t++; // '\n'
        else if (ch == EOF) break;
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < sta[i].size(); ++j)
            for (int k = j; k < sta[i].size(); ++k)
                f[sta[i][j]][sta[i][k]] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + 1);
    ans = f[1][n];
    if (ans < INF) printf("%lld", ans);
    else printf("NO");
    return 0;
}