#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 505, MAXM = 105, MAXT = 4e6 + MAXM, INF = 0x3f3f3f3f;
int n, m, mx, a[MAXT], sum[MAXT], sumt[MAXT], f[MAXT];
inline int waitTime(int l, int r) { return sumt[r] - sumt[l] - sum[l - 1] * (r - l); }
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P5017.in", "r", stdin);
    freopen("test1.out", "w", stdout);
#endif
    n = rd(); m = rd();
    for (int i = 1; i <= n; ++i) 
    {
        int time = rd();
        a[time]++;
        mx = max(mx, time);
    }
    sumt[0] = f[0] = 0;
    sum[0] = a[0];
    for (int i = 0; i < mx + m; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
        sumt[i] = sumt[i - 1] + sum[i - 1];
    }
    /*
        f[i] 表示 i 时刻前等车的同学等候时间的最小值（在数轴上表示见题解 1 ） 注意 i 能取到 0
        在之前即 [0,i - m] 枚举断点（即发车时间），计算等车时长（用前缀和） -- O(t^2)
        不过其实只需要在 [i - 2m, i - m] 内寻找答案就可以了，再远的话，肯定在之前多加一班车会更好 O(tm)
        然后在 [mx, mx + m) 内寻找答案
        不从 f[i - m] 直接转移，不直接用 f[mx] 当答案是因为他们不一定最优（比如时间不够发车之类的）
    */
    for (int i = 1; i < mx + m; ++i)
    {
        f[i] = sumt[i];
        for (int j = max(i - (m << 1), 0); j <= i - m; ++j)
            f[i] = min(f[i], f[j] + waitTime(j + 1, i));
    }
    int ans = INF;
    for (int i = mx; i < mx + m; ++i) ans = min(ans, f[i]);
    printf("%d", ans);
    return 0;
}