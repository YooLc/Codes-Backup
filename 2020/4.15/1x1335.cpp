#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 50, MAXM = 2e5 + 50, INF = 0x3f3f3f3f;
struct M
{
    int head[MAXN], nxt[MAXM << 1], edge[MAXM << 1], ver[MAXM << 1], tot;
} e[2];
int n, m, dis[2][MAXN], p[MAXN], book[MAXN], vis, T;
inline void add(int u, int v, int w, int id)
{
    e[id].ver[++e[id].tot] = v;
    e[id].edge[e[id].tot] = w;
    e[id].nxt[e[id].tot] = e[id].head[u];
    e[id].head[u] = e[id].tot;
}
// brute force search
inline void dij(int id)
{
    memset(book, 0, sizeof(book));
    for(int i = 1; i <= n; i++) dis[id][i] = INF;
	dis[id][1] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 1));
	while(q.size())
	{
		int t = q.top().second;
        q.pop();
		if(book[t]) continue;
		book[t] = 1;
		for(int k = e[id].head[t]; k; k = e[id].nxt[k])
		{
            int to = e[id].ver[k];
            if(dis[id][to] > dis[id][t] + e[id].edge[k])
			{
                if (p[t]) p[to] = p[t];
                else p[to] = to;
				dis[id][to] = dis[id][t] + e[id].edge[k];
				q.push(make_pair(-dis[id][to], to));
			}
		}
	}
}
int main()
{
    scanf("%d %d", &n, &m);
    T = n + 1;
    for (int i = 1; i <= m; ++i) 
    {
        int u, v, wuv, wvu;
        scanf("%d %d %d %d", &u, &v, &wuv, &wvu);
        add(u, v, wuv, 0);
        add(v, u, wvu, 0);
    }
    dij(0);
    for (int fr = 1; fr <= n; ++fr)
    {
        for (int k = e[0].head[fr]; k; k = e[0].nxt[k])
        {
            int to = e[0].ver[k], w = e[0].edge[k];
            if (to == 1)
            {
                if (p[fr] != fr) add(1, T, dis[0][fr] + w, 1);
                else add(fr, T, w, 1);
            }
            if (fr == 1)
            {
                if (p[to] != to) add(1, to, w, 1);
            }
            if (to != 1 && fr != 1)
            {
                if (p[fr] != p[to]) add(1, to, dis[0][fr] + w, 1);
                else add(fr, to, w, 1);
            }
        }
    }
    dij(1);
    for(int i = 1; i <= n + 1; ++i) cout << dis[1][i] << endl;
    if (dis[1][T] == INF) { puts("-1"); return 0;}
    else printf("%d", dis[1][T]);
    return 0;
}