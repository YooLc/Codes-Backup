#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 5, Z = 3; // MAXN 估计节点数， Z 字符集大小
struct Trie
{
    int nxt[MAXN * 32][Z], tot;
    bool eostr[MAXN]; char start;
    void init(char p) 
    { 
        start = p; tot = 0; 
        memset(nxt, 0, sizeof(nxt)); 
        memset(eostr, false, sizeof(eostr));
    }
    int insert(string str)
    {
        int len = str.length(), cur = 0, revcur = 0, ans = 0;
        for (int i = 0; i < len; ++i)
        {
            int to = str[i] - start;
            if (!nxt[cur][to])
                nxt[cur][to] = ++tot;
            // 贪心：尽量找不同的
            if (nxt[revcur][to ^ 1]) revcur = nxt[revcur][to ^ 1], ans = (ans << 1) | 1;
            else revcur = nxt[revcur][to], ans <<= 1;
            cur = nxt[cur][to];
        }
        return ans;
    }
} t;
int main() 
{
    t.init('0');
    int n; int ans = 0; scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u; scanf("%d", &u);
        bitset<32> bst(u);
        ans = max(ans, t.insert(bst.to_string())); // 还好有 C++11，要不然还得拆分每一位
    }   
    printf("%d", ans);
    return 0;
}