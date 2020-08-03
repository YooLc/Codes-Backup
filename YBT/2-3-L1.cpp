#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 5, Z = 11, L = 11; // Z 字符集大小， L 字符串长度
char str[MAXN][L];
struct Trie
{
    int nxt[MAXN][Z], tot;
    bool eostr[MAXN]; char start;
    void init(char p) 
    {
        start = p; tot = 0; 
        memset(nxt, 0, sizeof(nxt)); 
        memset(eostr, false, sizeof(eostr));
    }
    bool searhAndInsert(char str[])
    {
        int cur = 0, len = strlen(str);
        bool found = false;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to])
                nxt[cur][to] = ++tot;
            else if (i == len - 1) found = true;  // 之前的某个字符串的前缀是该字符串
            // 如果最后节点已经有了记录，那么这个字符串之前的所有节点一定都被创建过了
            cur = nxt[cur][to];
            if (eostr[cur]) found = true;         // 该字符串的前缀是之前的某个字符串
        }
        eostr[cur] = true;
        return found;
    }
} t;
inline bool solve()
{
    t.init('0');
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", str[i]);
    for (int i = 0; i < n; ++i)
        if(t.searhAndInsert(str[i])) return true;
    return false;
}
int main() 
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) puts(solve() ? "NO" : "YES");   
    return 0;
}