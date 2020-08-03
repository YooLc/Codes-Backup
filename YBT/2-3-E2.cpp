#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 4e2 + 5, Z = 27, L = 11, PL = 2.1e6;
int ans, l; bool vis[PL];
char pattern[L], mainstr[PL];
struct Trie
{
    int nxt[MAXN * L][Z], tot;
    char start; bool eostr[MAXN * L];
    void init(char p) 
    { 
        std::cerr << "_(:з」∠)_\n";
        memset(nxt, 0, sizeof(nxt));
        memset(eostr, false, sizeof(eostr));
        start = p; tot = 0;
    }
    void insert(char *str)
    {
        int len = strlen(str), cur = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        eostr[cur] = true;
    }
    void query(int st)
    {
        int cur = 0;
        for (int i = st; i < l; ++i)
        {
            int to = mainstr[i] - start;
            if (!nxt[cur][to]) return;
            cur = nxt[cur][to];
            if (eostr[cur]) // 尝试从这里截断去匹配，而不是贪心
            {
                ans = std::max(ans, i + 1);
                if (vis[i]) continue;
                vis[i] = true;
                query(i + 1);
            }
        }
    }
} t;
int main() 
{
    t.init('a');
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) { scanf("%s", pattern); t.insert(pattern); }
    for (int i = 1; i <= m; ++i)
    {
        ans = 0;
        scanf("%s", mainstr);
        l = strlen(mainstr); // strlen 效率太低了
        memset(vis, false, sizeof(vis));
        t.query(0);
        printf("%d\n", ans);
    }
    return 0;
}