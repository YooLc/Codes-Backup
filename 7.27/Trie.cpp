#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e4 + 5, Z = 11, L = 11; // MAXN 估计节点数: 字符串个数 * 字符串平均长度， Z 字符集大小， L 字符串长度
char str[MAXN][L];
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
            else if (i == len - 1) return num[cur]; // 如果前缀也算的话
            cur = nxt[cur][to];
            if (eostr[cur]) return num[cur];
        }
        return 0;
    }
} t;
inline void solve()
{
    t.init('0');
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", str[i]);
    for (int i = 0; i < n; ++i) t.insert(str[i]);
}
int main() 
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) solve();   
    return 0;
}