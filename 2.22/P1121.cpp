#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
typedef long long LL;
inline LL rd()
{
	LL t = 0, f = 1; char ch = getchar();
	while(!(ch >= '0' && ch <= '9')){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){t = (t << 3) + (t << 1) + ch - '0'; ch = getchar();}
	return t * f;
}
const int MAXN = 2e5 + 5;
struct Result
{
	LL num, s, t;
};
LL a[MAXN << 1], n;
Result maxSum(int s, int t)
{
	if (t < s)
		return {0, 0, 0};
	LL sum = 0, res = -10086;
	int rs = s, rt = s, curs = s, curt = s;
	for (int i = s; i <= t; ++i) {
		if (sum <= 0)
			sum = a[i], curs = curt = i;
		else
			sum += a[i], curt = i;
		if (curt - curs + 1 >= n)
			sum -= a[curs], curs++;
		if (sum > res)
			res = sum, rs = curs, rt = curt;
	}
	return {res, rs, rt};
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("P1121_4.in", "r", stdin);
		//freopen("P1121_1.out", "w", stdout);
	#endif
	n = rd();
	for (int i = 1; i <= n; ++i)
		a[i] = a[i + n] = rd();
	Result tans1 = maxSum(1, (n << 1) - 1), tans2;
	tans2 = tans1.t <= n ? maxSum(tans1.t + 1, (n << 1) - 1) : maxSum(tans1.t + 1, n + tans1.s - 1);
	// 以下部分感谢题解作者 Morning_Glory 指点迷津
	for (int i = tans1.s; i <= tans1.t; ++i)
		a[i] = -a[i];
	Result tans3 = maxSum(tans1.s, tans1.t);
	if(tans3.num + tans1.num == 0)
		tans3.num = LLONG_MIN;
	LL ans = tans1.num + max(tans2.num, tans3.num);
	printf("%lld\n", ans);
	return 0;
}
