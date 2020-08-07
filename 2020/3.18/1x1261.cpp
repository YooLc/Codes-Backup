#include <iostream>
#include <cstring>
#include <algorithm>
const static int MAXN = 55, MAXM = 8.4e6 + 50;
typedef unsigned int LL;
LL vol[MAXN], suspectAns[MAXM], tot, n, w, bound, ansNum, ans;
// 双向搜索，妙啊
// 不允许正解比暴力快
// 待我今后搞清楚为什么搬运趟数最少
void dfs1(int cur, LL sum) // [1, bound)
{
    if(cur == bound) {  suspectAns[++tot] = sum; return; }
    dfs1(cur + 1, sum);
    if(sum + vol[cur] <= w) dfs1(cur + 1, sum + vol[cur]);
}
void dfs2(int cur, LL sum) // [bound, n + 1)
{
    if(cur == n + 1) 
    { 
        ans = max(ans, sum + suspectAns[upper_bound(suspectAns + 1, suspectAns + 1 + tot, w - sum) - suspectAns - 1]);
        return; 
    }
    dfs2(cur + 1, sum);
    if(sum + vol[cur] <= w) dfs2(cur + 1, sum + vol[cur]);
}
int main()
{ 
    scanf("%lld %lld", &w, &n);
    bound = n >> 1;
    for(int i = 1; i <= n; ++i) scanf("%lld", &vol[i]);
    dfs1(1, 0);
    sort(suspectAns + 1, suspectAns + 1 + tot);
    unique(suspectAns + 1, suspectAns + 1 + tot);
    dfs2(bound, 0);
    printf("%u", ans);
    return 0;
}