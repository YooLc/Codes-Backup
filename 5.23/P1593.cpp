#include <iostream>
#include <cstdio>
typedef long long LL;
const int MAXN = 1e4 + 5, MOD = 9901;
LL p[MAXN], c[MAXN], tot, a, b;
inline LL mul(LL a, LL b) { return (a % MOD * b % MOD) % MOD;}
// 快速幂
inline LL qpow(int a, int x) 
{
	int base = a % MOD, res = 1; // 这里少了个取模就 WA....
	while(x)
	{
		if(x & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		x >>= 1;
	}
	return res;
}
// 费马小定理求乘法逆元
inline LL inv(LL a) { return qpow(a, MOD - 2); }
inline LL sum(int t) { return mul(qpow(p[t], c[t] * b + 1) - 1, inv(p[t] - 1)); }
inline void divprime()
{
    for (int i = 2; i * i <= a; ++i)
    {
        while(!(a % i))
        {
            a /= i;
            c[++tot]++;
            p[tot] = i;
            while(!(a % i)) a /= i, c[tot]++;
        }
    }
    if (a > 1) c[++tot]++, p[tot] = a;
}
int main()
{
    scanf("%lld %lld", &a, &b);
    divprime();
    LL ans = 1;
    // 三元运算一时爽， 写错分支火葬场
    for (int i = 1; i <= tot; ++i) ans = (p[i] - 1) % MOD ? mul(ans, sum(i)) : mul(ans, b * c[i] + 1);
    printf("%lld", (ans + MOD) % MOD);
    return 0;
}
/*
    Step I:   分解质因子
    Step II:  根据因数和与质因子的公式（可用大炮发射法理解）求出式子，再用等比数列优化
    Step III: 因为要带着取模做除法，所以用逆元
    Step IV:  特判（MOD 太小导致 pi - 1 为 9901 的倍数）
    Step V:   Orz dalao-zzt
    9876523 1201346
*/