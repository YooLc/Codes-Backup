#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
pLL exgcd(LL a, LL b)
{
	if(b == 0) return make_pair(1, 0);
	pLL t = exgcd(b, a % b);
	pLL res;
	res.first = t.second;
	res.second = t.first - (a / b) * t.second;
	return res;
}
int main() 
{
    LL x, y, m, n, l;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
    LL X = l, Y = n - m, C = x - y; // 经过化简（或由同余方程推导）kl + t(n - m) = x - y
    if (Y < 0) Y = -Y, C = -C;      // 系数必须为正整数
    LL g = __gcd(X, Y);             // 判断是否有解，化简方程
    if (C % g) { printf("Impossible"); return 0; } // 互质，无解
    X /= g; Y /= g; C /= g;         // 化简
    pLL sol = exgcd(X, Y);          // 求解
    sol.second *= C;                // 通过 ... = gcd(x, y) 的解求原方程的解，此时 x, y 已经互质
    printf("%lld", (sol.second % X + X) % X); // 最小正整数解
    return 0;
}