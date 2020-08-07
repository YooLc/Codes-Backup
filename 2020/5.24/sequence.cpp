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
typedef long long LL;
const int MAXN = 1e6 + 5, MOD = 1e9 + 7;
LL fact[MAXN];
inline void init()
{
    fact[0] = fact[1] = 1;
    for(LL i = 2; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
}
inline LL qpow(LL a, LL n, LL p)
{
    LL ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
inline LL inv(LL a, LL b)
{
    return qpow(a, b - 2, b);
}
inline LL C(LL a, LL b)
{
    if(a < b) return 0;
    return fact[a] * inv(fact[b], MOD) % MOD * inv(fact[a - b], MOD) % MOD;
}
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    LL n, zcnt = 0, ocnt = 0;
    n = rd();
    for (int i = 1; i <= n; ++i)
    {
        LL t; t = rd();
        if (t == 0) zcnt++;
        if (t == 1) ocnt++;
    }
    init();
    LL s = 0; 
    for (int i = 1; i <= zcnt; i++) s = (s + C(zcnt, i)) % MOD;
    LL ans = s % MOD * ocnt % MOD;
    printf("%lld", (ans + 1) % MOD);
    return 0;
}