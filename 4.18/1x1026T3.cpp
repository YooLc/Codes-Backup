#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 55;
int a[MAXN], f[MAXN], n;
inline int sum(int s, int t)
{
    // [s, t] 的最大的 k
    cout << "sum of " << s<< " " << t<<endl;
    for(int i = s; i <= t; ++i) cout << a[i] << " ";
    cout << endl;
    int ans = 0, len = t - s + 1;
    for (int k = 1; k <= len; ++k)
    {
        bool flag = true;
        for (int p = s + k; p <= t; ++p)
            if(a[p] - a[p - k] > 1) { flag = false; break; }
        if (flag) ans = max(ans, k);
    }
    cout << ans<<endl;
    return ans;
}
int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                f[i] = max(f[i], f[j] + sum(j + 1, i));
            }
        }
        printf("%d", f[n]);
    }
    return 0;
}