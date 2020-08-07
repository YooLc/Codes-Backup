#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
const int MAXN = 3e4 + 5, MAXM = 1e6 + 5;
using namespace std;
int mx[155];
struct Aho_Corasick_Automaton
{
    int nxt[MAXN][26], fail[MAXN], tot, idn[MAXN];
    void init() 
    { 
        memset(nxt, 0, sizeof(nxt)); 
        memset(mx, 0, sizeof(mx));
        memset(fail, 0, sizeof(fail));
        memset(idn, 0, sizeof(idn));
        tot = 0; 
    }
    void insert(string &str, int id)
    {
        int cur = 0;
        for (unsigned i = 0; i < str.length(); ++i)
        {
            int to = str[i] - 'a';
            if (!nxt[cur][to]) nxt[cur][to] = ++tot;
            cur = nxt[cur][to];
        }
        idn[cur] = id;
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
    int query(string &str)
    {
        int cur = 0, ans = 0;
        for (unsigned i = 0; i < str.length(); ++i)
        {
            int to = str[i] - 'a';
            cur = nxt[cur][to];
            // 有可能一些模式串是另一个的前缀
            for (int j = cur; j; j = fail[j]) 
                if (idn[j]) mx[idn[j]]++, ans = std::max(ans, mx[idn[j]]);
        }
        return ans;
    }
} ac;
string str;
vector<string> vocab;
int main() 
{
    ios::sync_with_stdio(false);
    int n; 
    while (cin >> n)
    {
        if (!n) break;
        ac.init(); vocab.clear();
        for (int i = 1; i <= n; ++i) 
        {
            cin >> str;
            ac.insert(str, i);
            vocab.push_back(str);
        }
        ac.buildFail();
        cin >> str;
        int ans = ac.query(str);
        cout << ans << endl;
        for (int i = 1; i <= n; ++i)
            if (mx[i] == ans) cout << vocab[i - 1] << endl;
    }
    return 0;
}
/*
4
ab
bc
cd
abcd
abcd
0
*/