#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 50, MAXM = 2e5 + 50, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM], ver[MAXM], edge[MAXM], color[MAXM], tot;
int dis[505], m, n;
vector<int> station[105];
inline void add(int u, int v, int c)
{
    cout << "adding "<<u<<" -> "<<v<<"of line"<<c<<endl;
    ver[++tot] = v;
    color[tot] = c;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline int dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<int, pair<int, int> > >q;
    q.push(make_pair(0, make_pair(1, 0)));
    dis[1] = 0;
    while(q.size())
    {
        int pre = q.top().second.first, lst = q.top().second.second; q.pop();
        for (int k = head[pre]; k; k = nxt[k])
        {
            int to = ver[k];
            if (lst[pre] && color[k] != lst[pre] && pre != 1)
            {
                cout << pre <<" -> "<<to << " of line " <<color[k] <<" last "<<lst[pre]<< endl;
                if (dis[to] > dis[pre] + 1)
                {
                    dis[to] = dis[pre] + 1;
                    lst[to] = color[k];
                    q.push(make_pair(-dis[to], to));
                }
            }
            else 
            {
                cout << pre <<" -> "<<to << " of line " <<color[k] <<" last "<<lst[pre]<< endl;
                if (dis[to] > dis[pre]) 
                {
                    dis[to] = min(dis[to], dis[pre]);
                    lst[to] = color[k];
                    q.push(make_pair(-dis[to], to));
                }
            }
        }
    }
    return dis[n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1x1332.in", "r", stdin);
#endif
    int t = 1, stop, ans;
    scanf("%d %d", &m, &n);
    while(~scanf("%d", &stop))
    {
        station[t].push_back(stop);
        char ch = getchar();
        if (ch == 10) t++; // '\n'
        else if (!~ch) break; // EOF = -1
    }
    for (int i = 1; i <= m; ++i)
        for (int k = 1; k < station[i].size(); k++)
            add(station[i][k - 1], station[i][k], i);
    ans = dijkstra();
    if (ans != INF) printf("%d", ans);
    else printf("NO");
    return 0;
}