#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 5, MAXM = 205, MOD = 1e9 + 7;
int f[MAXM][MAXM][2];
char str[MAXN], pattern[MAXM];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P2679.in", "r", stdin);
#endif
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s %s", str + 1, pattern + 1);
    /*
        f[i][j][k] 表示主串前 i 位切割成 k 份后匹配了 j 位子串的方案数
        目标 f[n][m][k]
        阶段：主串匹配到了 i 位
        状态：子串尝试匹配第 j 位
        转移： 
        最开始的设计：
            对于所有 f[i][j][t] = f[i - 1][j][t]
            str[i] == pattern[j] 时
                f[i][j][k] += f[i - 1][j - 1][k] (与上一个字符在同一串)+ f[i - 1][j - 1][k - 1] (遇上一个字符在不同串)
        但这样会遇到一个问题，比如样例 aabaab 前 5 位切一份匹配 aa 有两种方案，然而两种方案并不是都能与最后一位 b 结合起来。
        看了题解之后发现只要记录选和不选（因为要在同一个串就必须选上一个字符）就可以正确地转移了（学到了...
        最后可以滚调第一维，但是 j 需要倒序
    */
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            for (int t = 1; t <= k; ++t)
            {
                f[j][t][0] = (f[j][t][0] + f[j][t][1]) % MOD;
                // 同一串内，上一个字符必须选，不在同一个串可随意
                if (str[i] == pattern[j]) f[j][t][1] = ((f[j - 1][t - 1][0] + f[j - 1][t - 1][1]) % MOD + f[j - 1][t][1]) % MOD; 
                else f[j][t][1] = 0; // 不能匹配
            }
        }
    }
    printf("%d", (f[m][k][0] + f[m][k][1]) % MOD);
    return 0;
}