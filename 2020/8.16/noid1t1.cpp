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
const int MAXN = 55;
int n, m, T, k;
int val[MAXN];
struct Fest
{
    int time, x, y;
    bool operator > (const Fest &right) const { return time > right.time; }
};
namespace subtask1
{
const int MAXT = 52505, MAXM = 55;
struct Edge
{
    int u, v, w;
} e[MAXM];
LL f[MAXT][MAXM];
int tot = 0;
void solve()
{
    for (int i = 1; i <= m; ++i) 
    {
        e[i].u = rd();
        e[i].v = rd();
        e[i].w = rd();
    }
    priority_queue<Fest, vector<Fest>, greater<Fest>> q;
    for (int i = 1; i <= k; ++i)
    {
        Fest fest;
        fest.time = rd(); fest.x = rd(); fest.y = rd();
        q.push(fest);
    }
    memset(f, -0x7f, sizeof(f));
    f[0][1] = val[1];
    for (int t = 1; t <= T; ++t)
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
    if (f[T][1] >= 0) printf("%lld", f[T][1]);
    else printf("-1");
}
}; // namespace subtask1
namespace subtask2
{
LL dis[MAXN];
void solve()
{
    memset(dis, 0, sizeof(dis));
    LL sum = 0, sval = 0, sbonus = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        if (v != 1) dis[v] = dis[u] + w;
        sum += w;
        sval += val[i];
    }
    for (int i = 1; i <= k; ++i)
    {
        LL t, x, y;
        scanf("%lld %lld %lld", &t, &x, &y);
        if (t % sum == dis[x]) sbonus += y;
    }
    if (T % sum) {  printf("-1"); return; }
    LL ans = (T / sum) * sval + sbonus;
    printf("%lld", ans);
}
}; // namespace subtask2
// long long ?!
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("delicacy.in", "r", stdin);
    // freopen("delicacy.out", "w", stdout);
#endif
    n = rd(); m = rd(); T = rd(); k = rd();
    for (int i = 1; i <= n; ++i) val[i] = rd();
    if (T <= 52501) { subtask1::solve(); return 0; }
    
    subtask2::solve();
    return 0;
}