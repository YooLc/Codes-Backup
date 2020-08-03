#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int MAXN = 1.5e6 + 10;
using namespace std;
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
            if (eostr[cur]) 
            {
                cout << i << " " << ans << endl;
                if (i + 1 - ans > 10) return ans;
                ans = i + 1;
            }
        }
        return ans;
    }
} ac;
char str[MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-3-E2.in", "r", stdin);
    // freopen("2-4-L1.out", "w", stdout);
#endif
    ac.init();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", str), ac.insert(str);
    ac.buildFail();
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", str);
        printf("%d\n", ac.query(str));
    }
    return 0;
}