#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 501, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int r, c, ans, h[MAXN][MAXN], left[MAXN][MAXN], right[MAXN][MAXN];
bool vis[MAXN][MAXN];
void check(int tx, int ty)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = tx + dx[i], ny = ty + dy[i];
        if (nx < 1 || ny < 1 || nx > r || ny > c || h[nx][ny] >= h[tx][ty]) continue;
        if (!vis[nx][ny]) check(nx, ny);
        vis[nx][ny] = true; // 不搜但也要更新答案
        left[tx][ty] = std::min(left[tx][ty], left[nx][ny]);
        right[tx][ty] = std::max(right[tx][ty], right[nx][ny]);
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1514.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    /*
        Reference: https://www.luogu.com.cn/problem/solution/P1514
        若最终都能灌溉到，则一个水塔能灌溉的绝对是一个区间，dfs 计算其最大的范围
        --> 若没灌溉到，统计并输出
        --> 都灌溉到了，转化为区间覆盖问题，可以进行贪心
        这和 dp 有什么关系啊 = =，为什么有 dp 的标签.....而且我还想不出来怎么做....
    */
    memset(left, 0x3f, sizeof(left));
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            scanf("%d", &h[i][j]);
    for (int i = 1; i <= c; ++i) left[r][i] = right[r][i] = i;
    for (int i = 1; i <= c; ++i) check(1, i);
    if (r != 1) for (int i = 1; i <= c; ++i) ans += !vis[r][i]; // 坑点注意特判
    if (ans) { printf("0\n%d", ans); return 0; }
    //  贪心的区间覆盖问题
    int lptr = 1, rptr = 1;
    while (lptr <= c)
    {
        for (int i = 1; i <= c; ++i)
            if (left[1][i] <= lptr) 
                rptr = std::max(right[1][i], rptr);
        lptr = rptr + 1;
        ans++;
    }
    printf("1\n%d", ans);
    return 0;
}