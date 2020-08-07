#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2.5e4 + 5;
bool f[MAXN];
vector<int> a;
inline void solve()
{
    int n, lim = 0;
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    f[0] = true;
    a.clear(); a.resize(n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d", &a[i]);
        lim = std::max(lim, a[i]);
    }
    sort(a.begin(), a.end());
    int ans = n;
    for (int i = 0; i < n; ++i)
    {
        // 类似于基底，如果 a[i] 已经可以被表示了，那么 a[i] 能表示的一定都能被表示
        if (f[a[i]]) { ans--; continue; }
        for (int j = a[i]; j <= lim; ++j)
            f[j] |= f[j - a[i]];
    }
    printf("%d\n", ans);
}
int main() 
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) solve();    
    return 0;
}