#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 1e2 + 1, MAXM = 1e5 + 1;
int w[MAXN], t[MAXM];
bool f[MAXM];
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
int main() 
{
    /*
        有硬币个数限制，想到多重背包：
        1. 多重背包的形式为 f[j] = max(f[j - w[i]] + v[i], f[j]) （0-1背包） 然后拆分
        2. 发现硬币面值占得是体积，而价值没有意义，只需要记录 f[j] 是否能拼到即可
        3. 进行二进制分解的多重背包，转移方程为或，时间复杂度 O(nmlog c) 单组数据勉强过，多组数据 TLE
        //  单调队列 -> 待考证
        4. 考虑到 f[i] 只有可能是 0/1，可以尝试“带限制的完全背包”也就是我另记录一个数组，
           t[j] 代表当前这种硬币在总面额为 j 时最少需要放多少种，
           当且仅当 t[j - w[i]] < c[i] 时可以转移。
           这样时间复杂度被优化为 O(nm)
           也可以用类似思路：https://yoolc.cn/problem/p6567
    */
    int n, m, c;
    while (n = rd(), m = rd())
    {
        if (n == 0 && m == 0) break;
        memset(f, 0, m + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) w[i] = rd();
        for (int i = 1; i <= n; ++i)
        {
            c = rd();
            memset(t, 0, (m << 2) + 4);
            for (int j = w[i]; j <= m; ++j)
            {
                // 判断 f[j] 是因为防止本来能拼，再浪费一枚硬币来拼，导致后面本来可以拼的被跳过
                if (!f[j - w[i]] || t[j - w[i]] >= c || f[j]) continue; 
                f[j] = true;
                t[j] = t[j - w[i]] + 1;
            }
        }
        int ans = 0;
        for (int j = 1; j <= m; ++j) ans += f[j];
        printf("%d\n", ans);
    }
    return 0;
}