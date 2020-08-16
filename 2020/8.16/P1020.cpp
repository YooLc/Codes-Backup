#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN], tot;
int down[MAXN], up[MAXN];
int lend = 1, lenu = 1;
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1020.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    while (~scanf("%d", &arr[++tot]));
    --tot;
    // 最多拦截多少导弹 -> 最长不下降子序列
    // 最少需要多少系统 -> 最长上升子序列
    down[1] = arr[1];
    up[1] = arr[1];
    for (int i = 2; i <= tot; ++i)
    {
        // 对于最长上升子序列，肯定希望里面的元素越小越好，这样才能接更多的元素
        // 因此能接就接，不能接用它替换原来在序列里面的值
        // 最长不下降子序列也类似，可是 lower_bound 是求小于等于的，用 greater<int>() 让它强行变成大于等于
        // Reference: https://www.luogu.com.cn/blog/w1049/solution-p1020
        // down[i] 的含义是：最大不上升子序列长度为 i 时，最优的结尾元素，up 同理
        if (arr[i] > up[lenu]) up[++lenu] = arr[i];
        else *lower_bound(up + 1, up + 1 + lenu, arr[i]) = arr[i];
        if (arr[i] <= down[lend]) down[++lend] = arr[i];
        else *upper_bound(down + 1, down + 1 + lend, arr[i], greater<int>()) = arr[i]; 
        // 假装降序是升序，用 upper_bound 是因为可以等于
    }
    printf("%d\n%d", lend, lenu);
    return 0;
}