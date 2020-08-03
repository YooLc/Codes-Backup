#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int MAXN = 1e6 + 10;
struct Aho_Corasick_Automaton
{
    int nxt[MAXN][26], eostr[MAXN], fail[MAXN], tot;
    void init() 
    { 
        ++tot; // 节省内存空间
        memset(nxt, 0, (tot * 26) << 2); 
        memset(fail, 0, tot << 2);
        memset(eostr, 0, tot << 2);
        tot = 0; 
    }
    void insert(char *str)
    {
        int len = strlen(str), cur = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - 'a';
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        eostr[cur]++;
    }
    void buildFail()
    {
        std::queue<int> q; 
        for (int i = 0; i < 26; ++i) if (nxt[0][i]) q.push(nxt[0][i]);
        while (q.size())
        {
            int cur = q.front(); q.pop();
            for (int i = 0; i < 26; ++i)
            {
                if (nxt[cur][i]) fail[nxt[cur][i]] = nxt[fail[cur]][i], q.push(nxt[cur][i]);
                else nxt[cur][i] = nxt[fail[cur]][i];
            }
        }
    }
    int query(char *str)
    {
        int len = strlen(str), cur = 0, ans = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - 'a';
            cur = nxt[cur][to]; 
            // eostr 标记为 -1 代表已经统计过了
            for(int j = cur; j && eostr[j] != -1; j = fail[j])
                ans += eostr[j], eostr[j] = -1;
        }
        return ans;
    }
} ac;
char str[MAXN];
inline void solve()
{
    ac.init();
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) scanf("%s", str), ac.insert(str);
    scanf("%s", str), ac.buildFail();
    printf("%d\n", ac.query(str));
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-4-L1.in", "r", stdin);
    // freopen("2-4-L1.out", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i) solve();
    return 0;
}