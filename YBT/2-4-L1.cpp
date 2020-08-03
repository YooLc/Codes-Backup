#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 50, MAXM = 1e6 + 50, MAXL = 55, Z = 27;
char str[MAXM];
struct Trie
{
    int nxt[MAXN * MAXL][Z], eostr[MAXN * MAXL], root, tot;
    char start;
    void insert(char *str)
    {
        int len = strlen(str), cur = root;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to])
                nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        eostr[cur]++;
    }
};
struct Aho_Corasick_Automaton : Trie
{
    int fail[MAXN * MAXL];
    void init(char p) 
    { 
        start = p; tot = root = 1; 
        memset(nxt, 0, sizeof(nxt)); 
        memset(fail, 0, sizeof(fail));
        memset(eostr, false, sizeof(eostr));
    }
    void buildFail()
    {
        for (int i = 0; i < Z; ++i) nxt[0][i] = root;    // 0 节点所有转移边都指向根节点 1
        queue<int> q; q.push(root); 
        fail[0] = fail[root] = 0;                        // 与根节点失配的无法继续匹配
        while (q.size())
        {
            int cur = q.front(); q.pop();
            for (int i = 0; i < Z; ++i)                  // BFS 寻找子节点
            {
                int to = nxt[cur][i];
                if (!to) 
                { 
                    nxt[cur][i] = nxt[fail[cur]][i];      // 直接连接到最开始能匹配的位置，传递 fail 指针
                    continue;                            // 从而省去跳 fail 指针的时间 
                }
                q.push(to);                              // 子节点存在，加入队列
                int j = fail[cur];                       // 构建 fail 数组，最开始指向父节点的 fail 节点
                while (j > 0 && !nxt[j][i]) j = fail[j]; // 查找那个 fail 位置是否有和自己相同的出边，如果没有就继续跳
                fail[to] = nxt[j][i];                    // 自己的 fail 位置是相同出边指向的节点
            }
        }
    }
    int query(char *str)
    {
        int len = strlen(str), cur = 1, ans = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            int t = nxt[cur][to];
            while (t >= 1)
            {
                ans += eostr[t];  // 更新 ans
                eostr[t] = 0;     // 不能重复统计
                t = fail[t];      // 往回寻找前缀也在词典里的
            }
            cur = nxt[cur][to];   // 之前连过了，所以这里不需要跳 fail 指针
        }
        return ans;
    }
} ac;
void solve()
{
    ac.init('a');
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
    {
        scanf("%s", str);
        ac.insert(str);
    }
    scanf("%s", str);
    ac.buildFail();
    printf("%d\n", ac.query(str));
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-4-L1.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}