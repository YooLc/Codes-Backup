#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 50, MAXM = 5e4 + 50, INF = 0x3f3f3f3f, MOD = 1e4;
int head[MAXN], nxt[MAXM], ver[MAXM], edge[MAXM], tot;
int cnt[MAXN], s[MAXN], in[MAXN];
bool vis[MAXM];
inline void add(int u, int v, int w) 
{
    in[v]++;
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
inline void topo(int start)
{
    queue<int> q;
    cnt[start] = 1;
    q.push(start);
    while (q.size())
    {
        int u = q.front(); q.pop();
        // cout << u << " s: " << s[u] << " cnt: " <<cnt[u] << endl;
        for (int k = head[u]; k; k = nxt[k])
        {
            if (vis[k]) continue;
            int to = ver[k]; 
            vis[k] = true; in[to]--;
            cnt[to] = (cnt[to] + cnt[u]) % MOD;
            // cout << u<<" -> "<<to<<" = "<<s[to]<<" "<<mul(s[u],cnt[u])<<" "<<edge[k]<<endl;
            s[to] = (((s[to] % MOD) + mul(edge[k], cnt[u])) % MOD + s[u]) % MOD;
            if (in[to] == 0) q.push(to);
        }
    }
}
int main()
{
    int n, m, start, t, ts;
    scanf("%d %d %d %d %d", &n, &m, &start, &t, &ts);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    topo(start);
    int ans = (s[t] + mul(ts, cnt[t] - 1) + MOD) % MOD;
    printf("%d", ans);
    return 0;
}
/*
4 6 1 3 1
1 2 1
1 2 1
2 3 1
1 4 1
1 4 1
4 3 1
*/