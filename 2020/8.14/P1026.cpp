#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 205, MAXM = 7;
struct Trie
{
    int nxt[MAXN * MAXM][26], tot;
    bool eostr[MAXN * MAXM];
    Trie() { tot = 0; }
    void insert(char *str)
    {
        int cur = 0, len = strlen(str);
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - 'a';
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        eostr[cur] = true;
    }
    int search(char *str, int s, int t)
    {
        int cur = 0;
        for (int i = s; i <= t; ++i)
        {
            int to = str[i] - 'a';
            if (!nxt[cur][to]) return false; 
            cur = nxt[cur][to];
            if (eostr[cur]) return true;
        }
        return false;
    }
} t;
char str[MAXN], v[MAXN];
int p[MAXN][MAXN];
int f[MAXN][45];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1026.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int line, part, vocab;
    scanf("%d %d", &line, &part);
    for (int i = 0; i < line; ++i) scanf("%s", str + i * 20);
    scanf("%d", &vocab);
    for (int i = 0; i < vocab; ++i)
    {
        scanf("%s", v);
        t.insert(v);
    }
    /*
        p[i][j] 表示从 i 到 j 的匹配数 （尽量匹配最长的）
        f[i][j] 表示前 i 位分 j 段的最大匹配数
    */
    int len = line * 20;
    for (int i = 0; i < len; ++i) p[i][i] = t.search(str, i, i);
    for (int l = 2; l <= len; ++l)
    {
        for (int i = 0; i + l - 1 < len; ++i)
        {
            int j = i + l - 1;
            p[i][j] = t.search(str, i, j) + p[i + 1][j];
            for (int k = i; k < j; ++k) 
                p[i][j] = std::max(p[i][j], p[i][k] + p[k + 1][j]);
        }
    }
    memset(f, -0x3f, sizeof(f));
    for (int i = 0; i < len; ++i) f[i][0] = p[0][i];
    for (int i = 0; i < len; ++i)
        for (int j = 1; j <= part; ++j)
            for (int k = 0; k < i; ++k)
                f[i][j] = std::max(f[i][j], f[k][j - 1] + p[k + 1][i]);
    printf("%d", f[len - 1][part - 1]); // 是切成 k 份，不是切 j 刀啊啊啊啊.......
    return 0;
}