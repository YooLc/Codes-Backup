#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 4e2 + 5, Z = 27, L = 11, PL = 2.1e6;
int ans, l, n, m; bool vis[PL];
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
    void query(int st, int len)
    {
        int cur = 0;
        for (int i = st; i < len; ++i)
        {
            int to = mainstr[i] - start;
            if (!nxt[cur][to]) return;
            cur = nxt[cur][to];
            if (eostr[cur]) vis[i] = true;
        }
    }
} t;
char t1[] = "123", t2[] = "123";
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2-3-E2.in", "r", stdin);
#endif
    t.init('a');
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) { scanf("%s", pattern); t.insert(pattern); }
    for (int i = 1; i <= m; ++i)
    {
        ans = 0;
        scanf("%s", mainstr);
        int len = strlen(mainstr);
        for (int j = 0; j < len; ++j) vis[j] = false;
        t.query(0, len);
        for (int j = 0; j < len; ++j)
        {
            if (!vis[j]) continue;
            t.query(j + 1, len);
            ans = j + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}