#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline int lowbit(int x) { return x & (-x); }
const int MAXN = 1e6 + 50, MOD = 1e9 + 7;
typedef long long LL;
int a[MAXN], tree[MAXN], n, pre[MAXN];
bool vis[MAXN];
map<int, int> last;
inline void add(int x, int k)
{
    while(x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
inline int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}
inline int query(int l, int r) { return sum(r) - sum(l - 1);}
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    n = rd();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rd();
        if (last.count(a[i])) pre[i] = last[a[i]];
        else pre[i] = -1;
        last[a[i]] = i;
        add(i, 1);
    }
    LL s = 0;
    for (int r = 1; r <= n; ++r)
    {
        if(pre[r] != -1) add(pre[r], -1);
        for (int l = 1; l <= r; ++l)
        {
            LL t = sum(r) - sum(l - 1);
            s = (s + (t * t % MOD)) % MOD;
        }
    }
    printf("%lld\n", s);
    return 0;
}