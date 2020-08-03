#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
const int MAXN = 4e5 + 5, Z = 3; // MAXN 估计节点数， Z 字符集大小
int arr[MAXN], l[MAXN], r[MAXN];
struct Trie
{
    int nxt[MAXN * 32][Z], tot;
    char start;
    void init(char p) 
    { 
        for (int i = 0; i <= tot; ++i) 
            for (int j = 0; j < Z; ++j) 
                nxt[i][j] = 0;
        start = p; tot = 0;
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
inline string str(int x) { bitset<32> bst(x); return bst.to_string(); }
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
int main() 
{
    int n, ans = 0; n = rd();
    int x = 0; // xor is a keyword after C++11
    /*
        x[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]  ==> Trie
        L[i] 找到在 i 左边连续异或和最大的一段
        R[i] 找到在 i 右边连续异或和最大的一段
        ans = max(L[i] + R[i + 1]) i in 1 ... n - 1
    */
    t.init('0'); t.insert(str(0));
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = rd();
        x ^= arr[i];
        l[i] = max(l[i - 1], t.insert(str(x)));
    }
    t.init('0'); t.insert(str(0));
    x = 0;
    for (int i = n; i >= 1; --i)
    {
        x ^= arr[i];
        bitset<32> bst(x);
        r[i] = max(r[i + 1], t.insert(str(x)));
        ans = max(l[i - 1] + r[i], ans);
    }
    printf("%d", ans);
    return 0;
}