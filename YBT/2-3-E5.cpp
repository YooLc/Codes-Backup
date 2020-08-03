#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 2e5 + 50, MAXL = 33, Z = 2;
typedef long long LL;
int head[MAXN], edge[MAXN], nxt[MAXN], ver[MAXN], tot = 0;
int f[MAXN], ans = 0, n;
bool vis[MAXN];
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
struct Trie
{
    int nxt[MAXN * MAXL][Z], tot, ret[MAXL];
    void init() { tot = 0; memset(nxt, 0, sizeof(nxt)); memset(ret, 0, sizeof(ret)); }
    Trie () { init(); }
    int insert(int x)
    {
        for (int i = MAXL - 1; i >= 0; --i)
        {
            ret[i] = (x & 1) ? 1 : 0;
            if (x) x >>= 1;
        }
        int cur = 0, revcur = 0, ans = 0;
        for (int i = 0; i < MAXL; ++i)
        {
            int to = ret[i];
            if (!nxt[cur][to])
                nxt[cur][to] = ++tot;
            // 贪心：尽量找不同的
            if (nxt[revcur][to ^ 1]) revcur = nxt[revcur][to ^ 1], ans = (ans << 1) | 1;
            else revcur = nxt[revcur][to], ans <<= 1;
            cur = nxt[cur][to];
        }
        return ans;
    }
} t;
inline void init()
{
    t.init();
    tot = 0; ans = 0;
    memset(head, 0, sizeof(head));
    memset(vis, false, sizeof(vis));
}
void dfs(int cur)
{
    /*
        异或具有自反性，
        因此不必要把树拆成几条链然后求异或和，最后连接起来，
        只需要固定一个点，求出那个点到其他点路径的异或和即可，
        用 Trie 很方便地可以求出两个路径（经过定点）的异或和，
        由于异或的自反性，因此所求的异或和就是经过两者 LCA 的一条路径。
        dfs的时候顺便枚举起点，然后对每一个点都求出当时“异或距离”最远的路径，取最大值即可。
    */
    vis[cur] = true;
    ans = std::max(ans, t.insert(f[cur]));
    for (int k = head[cur]; k; k = nxt[k])
    {
        int to = ver[k];
        f[to] = f[cur] xor edge[k]; // xor is a keyword after C++11
        if (!vis[to]) dfs(to);
    }
}
int main() 
{
    // Reference：https://blog.csdn.net/qq_40642465/article/details/86618681
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 1; i < n; ++i)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}