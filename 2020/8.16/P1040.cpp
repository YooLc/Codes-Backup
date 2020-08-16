#include <iostream>
#include <cstdio>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 30;
typedef pair<int, int> pii;
int pts[MAXN];
int f[MAXN][MAXN][MAXN], ret[MAXN], tot;
pii pre[MAXN][MAXN][MAXN];
inline void preOrder(int rt, int l, int r)
{
    if (!rt) return;
    if (rt != ret[tot]) ret[++tot] = rt;
    preOrder(pre[rt][l][r].first, l, rt - 1);
    preOrder(pre[rt][l][r].second, rt + 1, r);
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1040.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &pts[i]);
    /*
        f[i][j][k] 表示 i 为根节点，二叉树包括 k 到 j 节点时候的得分最大值
        当且仅当 j \le i \le k 时，能够满足中序遍历为 1...n 的要求
        然后不知怎么就整了个前序遍历 = =，有的时候遇到左右端点重合的情况要判重
        看了题解之后，发现不需要枚举根也能做= =，只要分左右端点的情况讨论就行了
        硬是把 n^3 做成了 n^5，还好 2020 年的机器跑 2003 年的数据很快
    */
    for (int i = 1; i <= n; ++i)
        f[i][i][i] = pts[i], pre[i][i][i] = make_pair(0, 0);
    for (int rt = 0; rt <= n; ++rt)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                f[rt][i][j] = 1, pre[rt][i][j] = make_pair(0, 0);
    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            for (int rt = l; rt <= r; ++rt)
            {
                for (int lrt = l; lrt <= rt; ++lrt)
                {
                    for (int rrt = rt + 1; rrt <= r; ++rrt)
                    {
                        int treepts = f[lrt][l][rt - 1] * f[rrt][rt + 1][r] + pts[rt];
                        if (treepts <= f[rt][l][r]) continue;
                        f[rt][l][r] = treepts;
                        pre[rt][l][r] = make_pair(lrt, rrt);
                    }
                }
                
            }
        }
    }
    int ans = 0, rt;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i][1][n] <= ans) continue;
        ans = f[i][1][n];
        rt = i;
    }
    printf("%d\n", ans);
    preOrder(rt, 1, n);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ret[i]);
    return 0;
}