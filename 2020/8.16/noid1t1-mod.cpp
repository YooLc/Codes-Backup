#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 55, MAXT = 52505, MAXM = 505;
int n, m, T, k, tot = 0;
int val[MAXN];
struct Fest
{
    int time, x, y;
    bool operator > (const Fest &right) const { return time > right.time; }
};
struct Edge
{
    int u, v, w;
} e[MAXM];
LL f[MAXT][MAXM];
// long long ?!
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("delicacy.in", "r", stdin);
    freopen("delicacy.out", "w", stdout);
#endif
    n = rd(); m = rd(); T = rd(); k = rd();
    for (int i = 1; i <= n; ++i) val[i] = rd();
    bool isA = (n == m);
    LL sum = 0LL, sumy = 0LL, sval = 0LL;
    for (int i = 1; i <= m; ++i) 
    {
        e[i].u = rd();
        e[i].v = rd();
        e[i].w = rd();
        sum += e[i].w; sval += val[i];
        isA &= (e[i].v == (i % n) + 1 && e[i].u == i);
    }
    priority_queue<Fest, vector<Fest>, greater<Fest>> q;
    for (int i = 1; i <= k; ++i)
    {
        Fest fest;
        fest.time = rd(); fest.x = rd(); fest.y = rd();
        sumy += fest.y;
        if (!isA) q.push(fest);
    }
    if (isA)
    {
        if (T % sum) { printf("-1"); return 0; }
        LL ans = (T / sum) * sval + sumy;
        printf("%lld", ans);
        return 0;
    }
    memset(f, -0x7f, sizeof(f));
    f[0][1] = val[1];
    int uplim = min(T, 52501);
    for (int t = 1; t <= uplim; ++t)
    {
        int city = 0, bonus = 0;
        if (q.size() && q.top().time == t)
        {
            city = q.top().x;
            bonus = q.top().y;
            q.pop();
        }
        for (int i = 1; i <= m; ++i)
        {
            if (t < e[i].w) continue;
            f[t][e[i].v] = max(f[t][e[i].v], f[t - e[i].w][e[i].u] + val[e[i].v] + (e[i].v == city ? bonus : 0));
        }
    }
    if (T <= 52501)
    {
        if (f[T][1] >= 0LL) printf("%lld", f[T][1]);
        else printf("-1");
        return 0;
    }
    // else if (k == 0)
    // {
    //     LL ans = 0LL;
    //     for (int i = 1; i <= 52501; ++i)
    //     {
    //     bn     if (T % i == 0)

    //     }
    // }
    printf("-1");
    return 0;
}