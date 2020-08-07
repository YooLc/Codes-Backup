#include <iostream>
#include <cstdio>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e6 + 5;
int a[MAXN];
int main()
{
    freopen("kettle.in", "r", stdin);
    freopen("kettle.out", "w", stdout);
    int n, k, ans = 0, sum = 0;
    n = rd(); k = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    for (int i = 1; i <= k + 1; ++i) sum += a[i];
    ans = sum;
    for (int i = k + 2; i <= n; ++i) 
    {
        sum = sum - a[i - k - 1] + a[i];
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}