#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 2e2 + 1, MAXM = 21, SHIFT = 425, INF = 0x3f3f3f3f; // 401 本地能过 20 0 数据
int n, m, d[MAXN], p[MAXN];
int f[MAXN][MAXM][SHIFT << 1];
int tot = 0, dsum = 0, psum = 0, ans[MAXM];
inline void calc(int row, int col, int val)
{
    if (row <= 0 || col <= 0 || val < 0 || val > (SHIFT << 1)) return;
    if (f[row][col][val] == f[row - 1][col][val]) calc(row - 1, col, val); // 没被选
    else 
    {
        ans[++tot] = row;
        psum += p[row]; dsum += d[row];
        calc(row - 1, col - 1, val - (d[row] - p[row]));
    }
}
int main() 
{
    memset(f, -1, sizeof(f));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &p[i], &d[i]);
    /*
        先打暴力搜索，我的 dfs 程序里参数为 cur 表示当前的人，s 表示选了多少人，sd 表示 d 的总和，sp 表示 p 的总和
        按照题目所说的设定来更新答案，可惜 TLE 了。
        于是设计一个存储状态的数组: f[i][j][sumD][sumP]，然而空间可能会开不下，
        不过题目中只会选 m 人， D - P 的范围小一些，而且的确不必分别存下 sumD 和 sumP 的值，
        于是最终状态设计为：f[i][j][S] 表示前 i 个人里选了 j 个人且 D - P 为 S 时的最大权值和
        我们把 D - P 加上一个值，让它不会变成负数（或者用 map 做？）
        那么对于每一个人，都有选和不选两种决策：
        选就是 f[i][j][S] = f[i - 1][j][S]
        不选是 f[i][j][S] = f[i - 1][j - 1][S - (d[i] - p[i])] + (d[i] + p[i])
        最后再根据 f 数组用 dfs 恢复决策就行。
        时间复杂度 O(nmS)，其中 S 为最大分值。
    */
    // SHIFT 代表数轴上的原点
    for (int i = 0; i <= n; ++i) f[i][0][SHIFT] = 0; // 1 个人都不选 D - P 的值为 0 时，D + P 总和为 0
    int uplim = SHIFT << 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < uplim; ++k)
            {
                f[i][j][k] = f[i - 1][j][k];
                int s = d[i] - p[i];
                if (f[i - 1][j - 1][k - s] != -1) // 如果这个位置有意义
                    f[i][j][k] = max(f[i - 1][j - 1][k - s] + d[i] + p[i], f[i][j][k]);
            }
        } 
    } 
    // 枚举 |D - P|，遇到了就是最小的
    for (int cur = 0; cur < SHIFT; ++cur)
    {
        int l = SHIFT - cur;
        int r = SHIFT + cur;
        if (f[n][m][l] == -1 && f[n][m][r] == -1) continue;
        if (f[n][m][l] > f[n][m][r]) calc(n, m, l);
        else calc(n, m, r);
        break;
    }
    printf("%d %d\n", psum, dsum);
    for (int i = tot; i >= 1; --i) printf("%d ", ans[i]);
    return 0;
}
/*
20 20
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
20 0
*/