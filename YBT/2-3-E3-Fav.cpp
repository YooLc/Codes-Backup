#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 5e5 + 5, Z = 3, L = 1e4 + 50;
using namespace std;
int l;
char pattern[L], mainstr[L];
inline void rd(char *str, int length)
{
    for (int i = 0; i < length; ++i) cin >> str[i];
    str[length] = '\0';
}
struct Trie
{
    int nxt[MAXN][Z], tot, num[MAXN], eostr[MAXN];
    char start;
    void init(char p) 
    { 
        std::cerr << "_(:з」∠)_\n";
        memset(nxt, 0, sizeof(nxt));
        memset(eostr, 0, sizeof(eostr));
        memset(num, 0, sizeof(num));
        start = p; tot = 0;
    }
    void insert(char str[])
    {
        int len = strlen(str), cur = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
            num[cur]++;
        }
        eostr[cur]++;
    }
    int query()
    {
        int cur = 0, ans = 0;
        for (int i = 0; i < l; ++i)
        {
            int to = mainstr[i] - start;
            if (!nxt[cur][to]) return ans; // 没有以模式串为前缀的主串，不需要添加
            cur = nxt[cur][to];
            if (i < l - 1) ans += eostr[cur]; // 主串是模式串的前缀，考虑重复
        }
        return ans + num[cur]; // 添加以模式串为前缀的主串数量
    }
} t;
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-2-E3.in", "r", stdin);
#endif
    t.init('0'); 
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
    { 
        scanf("%d", &l);
        rd(pattern, l);
        t.insert(pattern); 
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &l);
        rd(mainstr, l);
        printf("%d\n", t.query());
    }
    return 0;
}