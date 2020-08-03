#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 11, Z = 2, L = 11; // MAXN 估计节点数， Z 字符集大小
struct Trie
{
    int nxt[MAXN * L][Z], num[MAXN * L], tot;
    char start;
    bool eostr[MAXN * L];
    void init(char p) 
    { 
        memset(nxt, 0, sizeof(nxt));
        memset(num, 0, sizeof(num));
        memset(eostr, false, sizeof(eostr));
        start = p; tot = 0;
    }
    void insert(char *str)
    {
        int len = strlen(str), cur = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to])
                nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
            num[cur]++;
        }
        eostr[cur] = true;
    }
    int query(char *str)
    {
        int len = strlen(str), cur = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to]) return 0;
            else if (i == len - 1) return num[cur];
            cur = nxt[cur][to];
            if (eostr[cur]) return num[cur];
        }
        return 0;
    }
} t;
int main() 
{
    int T = 0, ans = 0;
    char s[MAXN];
    t.init('0');
    while (~scanf("%s", s))
    {
        if (s[0] == '9')
        {
            if(!ans) printf("Set %d is immediately decodable\n", ++T);
            else printf("Set %d is not immediately decodable\n", ++T);
            ans = 0; t.init('0');
            continue;
        }
        ans |= t.query(s);
        t.insert(s);
    }
    return 0;
}