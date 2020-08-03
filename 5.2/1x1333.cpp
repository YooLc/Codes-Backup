#include <iostream>
#include <cstdio>
#define THE_BEST_PONY Rainbow_Dash
const int N = 205;
int d[N][N], t[N];
int main()
{
    int n, to, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        while(~scanf("%d", &to) && to) if (!d[to][i]) d[i][to] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] |= d[i][k] & d[k][j], t[j] |= d[i][j];
    for (int i = 1; i <= n; ++i) 
        if (!t[i]) ans++;
    printf("%d", std::max(ans, 1));
    return 0;
}
/*
5
2 0
1 3 0
0
5 0
0
*/