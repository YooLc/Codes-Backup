#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MAXN = 3e6 + 5, MAXP = 3e5 + 5, MOD = 3221225473;
int a[MAXN], f[MAXN], p[MAXP], mx[MAXP], tot, tp, n;
bool vis[MAXN], t[MAXN];
inline LL qpow(LL a, LL x, LL p) // Fermat's Little Theorem
{
    LL base = a, res = 1;
    while(x)
    {
        if(x & 1) res = res * base % p;
        base = base * base % p;
        x >>= 1;
    }
    return res;
}
inline void sieve()
{
    for(int i = 2; i * i < MAXN; ++i)
		if(!t[i])
			for(int j = i * 2; j < MAXN; j += i)
				t[j] = true;
    for (int i = 2; i < MAXN; ++i) if (!t[i]) p[++tp] = i;
}
inline void dfs(int cur, int step)
{
    vis[cur] = true;
    if (vis[a[cur]]) { f[++tot] = step + 1; return; }
    else dfs(a[cur], step + 1);
}
inline void solve()
{
    memset(vis, false, sizeof(vis));
    memset(mx, 0, sizeof(mx)); 
    tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i, 0);
    for (int i = 1; i <= tot; ++i)
    {
        for (int j = 1; j <= tp && p[j] <= f[i]; ++j)
        {
            int cnt = 0;
            while (f[i] % p[j] == 0) f[i] /= p[j], cnt++;
            mx[j] = max(mx[j], cnt);
        }
    }
    LL ans = 1;
    for (int i = 1; i <= tp; ++i) 
        if (mx[i]) ans = ans * qpow(p[i], mx[i], MOD) % MOD;
    printf("%lld\n", ans);
}
int main()
{
    int T; sieve();
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) solve();
    return 0;
}