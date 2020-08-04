/*
    统计时建立 fail 树，
    Reference: https://www.luogu.com.cn/blog/ouuan/solution-p5357
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
const int MAXN = 2e5 + 5, MAXM = 2e6 + 5;
using namespace std;
int idn[MAXN];
struct Tree 
{
    const static int SIZE = MAXN;
    int head[SIZE], nxt[SIZE], ver[SIZE], ans[SIZE], tot;
    Tree(): tot(0) { }
    void add(int u, int v)
    {
        ver[++tot] = v;
        ans[tot] = 0;
        nxt[tot] = head[u];
        head[u] = tot;
    }
    void dfs(int cur)
    {
        for (int k = head[cur]; k; k = nxt[k])
        {
            dfs(ver[k]);
            // Fail 树上，父节点的答案是所有子树答案的和
            // 因为只要子节点匹配了，父节点就一定匹配
            ans[cur] += ans[ver[k]];
        }
    }
} failTree;
struct Aho_Corasick_Automaton
{
    int nxt[MAXN][26], fail[MAXN], tot;
    void init() 
    { 
        memset(nxt, 0, sizeof(nxt)); 
        memset(fail, 0, sizeof(fail));
        memset(idn, 0, sizeof(idn));
        tot = 0; 
    }
    void insert(char *str, int id)
    {
        int cur = 0, len = strlen(str);
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - 'a';
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        idn[id] = cur; // id -> trie节点的对应关系
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
        for (int i = 1; i <= tot; ++i) 
            failTree.add(fail[i], i);
    }
    void query(char *str)
    {
        int cur = 0, len = strlen(str);
        for (int i = 0; i < len; ++i)
        {
            cur = nxt[cur][str[i] - 'a'];
            ++failTree.ans[cur]; // fail 树上当前节点匹配到了，记录
            // 这里太暴力，会被卡
            // for (int j = cur; j; j = fail[j])
            //     for (auto id: idn[j]) mx[id]++;
        }
    }
} ac;
char str[MAXM];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P5357.in", "r", stdin);
    // freopen("P5337.out", "w", stdout);
#endif
    int n; 
    scanf("%d", &n);
    ac.init();
    for (int i = 0; i < n; ++i) 
    {
        scanf("%s", str);
        ac.insert(str, i);
    }
    ac.buildFail();
    scanf("%s", str);
    ac.query(str);
    failTree.dfs(0);
    for (int i = 0; i < n; ++i)
        printf("%d\n", failTree.ans[idn[i]]);
    return 0;
}