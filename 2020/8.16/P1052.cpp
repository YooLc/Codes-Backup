#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXM = 1e2 + 50, MAXL = 1e4 + 50, INF = 0x3f3f3f3f;
int arr[MAXM], g[MAXL], f[MAXL];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1052.txt", "r", stdin);
    freopen("P1052.out", "w", stdout);
#endif
    /*
        L 很大， m 很小
        把石子之间的距离缩小一点就可以了
        参考 NOIP2017 小凯的疑惑，只要间距大于 10 * 9 - 10 - 9 = 71，就把间距变成 71 即可
        当然不知道对不对的做法，我把它之间的距离变成了 2 * t，也过了
    */
    int l, s, t, m;
    l = rd(); s = rd(); t = rd(); m = rd();
    for (int i = 1; i <= m; ++i) arr[i] = rd();
    sort(arr + 1, arr + 1 + m);
    int cnt = 0;
    for (int i = 1, last = 0; i <= m; ++i)
    {
        arr[i] -= cnt * t;
        int delta = 0;
        if (arr[i] - last >= t * 2)
        {
            delta =  (arr[i] - last - t * 2) / t;
            arr[i] -= delta * t;
            cnt += delta;
        }
        g[arr[i]]++;
        last = arr[i];
    }
    l = arr[m] + 1;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i < MAXL; ++i)
    {
        for (int j = max(0, i - t); j <= i - s; ++j)
        {
            f[i] = min(f[i], f[j] + g[i]);
        }
    }
    int ans = INF;
    for (int i = l; i < MAXL; ++i) ans = std::min(ans, f[i]);
    printf("%d", ans);
    return 0;
}