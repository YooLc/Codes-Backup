#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 2e5 + 5, MOD = 998244353;
long long a[MAXN], n, m;
inline int rd()
{
	int t = 0, f = 1; char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
	return t * f;
}
struct Task
{
	int type, p, v, c;
	vector<int> g;
	Task() { g.clear(); type = p = v = c = 0;}
} task[MAXN];
inline void add(long long &x, int val) { x = (x + val) % MOD; }
inline void mul(long long &x, int val) { x = (x * (val % MOD)) % MOD; }
inline void call(int k)
{
	if (task[k].type == 1) add(a[task[k].p], task[k].v);
	else if (task[k].type == 2)
	{
		for (int i = 1; i <= n; ++i) mul(a[i], task[k].v);
	}
	else if (task[k].type == 3)
	{
		for (size_t i = 0; i < task[k].c; ++i)
			call(task[k].g[i]);
	}
}
int main()
{
	//freopen("call.in", "r", stdin);
	//freopen("call.out", "w", stdout);
	n = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	m = rd();
	for (int i = 1; i <= m; ++i)
	{
		task[i].type = rd();
		if (task[i].type == 2) task[i].v = rd();
		else if (task[i].type == 1)
		{
			task[i].p = rd();
			task[i].v = rd();
		}
		else if (task[i].type == 3)
		{
			task[i].c = rd();
			task[i].g.resize(task[i].c);
			for (size_t j = 0; j < task[i].c; ++j) task[i].g[j] = rd();
		}
	}
	int q = rd();
	for (int i = 1; i <= q; ++i)
	{
		int f = rd();
		call(f);
	}
	for (int i = 1; i <= n; ++i) printf("%lld ", a[i]);
	return 0;
}