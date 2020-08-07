#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 205;
int e[MAXN][MAXN];
int ind[MAXN], ans[MAXN];
inline void solve()
{
    memset(e, 0, sizeof(e));
    memset(ind, 0, sizeof(ind));
    priority_queue<int> q;
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &u, &v);
        if (!e[v][u]) ind[u]++; // 判断重边
        e[v][u] = 1; // 反向建图，保证题目的要求
    }
    for (int i = 1; i <= n; ++i)
        if(!ind[i]) q.push(i);
    int label = n;
    while(q.size())
    {
        int pre = q.top(); q.pop();
        ans[pre] = label--;
        for (int k = 1; k <= n; k++)
        {
            if (e[pre][k])
            {
                ind[k]--;
                e[pre][k] = 0; // 别成环被卡成 TLE
                if (ind[k] == 0) q.push(k);
            }
        }
    }
    if (label > 0) printf("-1\n"); // 拓扑排序进行完但没排完，发现不是DAG
    else
    {
        for (int i = 1; i <= n; ++i) 
            printf("%d ", ans[i]);
        printf("\n");
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("poj.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}