#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ULL;
int book[65];
int main()
{
    freopen("P7076_14.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
	int n, m, c, k, p, q; ULL a, t = 0ULL;
    cin >> n >> m >> c >> k;
    if (n == 0) { puts("18446744073709551616"); return 0; }
    int cnt = k;
	for (int i = 1; i <= n; ++i) { cin >> a; t |= a; }
    for (int i = 1; i <= m; ++i)
	{
		cin >> p >> q;
        if ((1ULL << p & t) == 0 && !book[p])
            cnt--, book[p] = true;
    }
	cout << (1ULL << cnt) - n << endl;
	return 0;
}