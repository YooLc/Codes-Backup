#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 50, MAXM = 2e5 + 50;
int head[MAXN], nxt[MAXM << 1], edge[MAXM << 1], ver[MAXM << 1], id[MAXM << 1], tot;
int n, m;
struct Node
{
    int cur, time;
    map<int, bool> vis;
    bool operator < (const Node &c) const { return c.time > time; }
};
inline void add(int u, int v, int w, int idn)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
    id[tot] = idn;
}
// brute force search
inline void bfs()
{
    priority_queue<Node> q;
    Node s;
    s.cur = 1;
    s.time = 0;
    q.push(s);
    while (q.size())
    {
        Node pre = q.top();
        q.pop();
        // cout << pre.time << " " << pre.cur << endl;
        if (pre.vis.size() && pre.cur == 1)
        {
            printf("%d", pre.time);
            return;
        }
        for (int k = head[pre.cur]; k; k = nxt[k])
        {
            if (!pre.vis.count(id[k]))
            {
                Node nxt;
                nxt.cur = ver[k];
                nxt.time = pre.time + edge[k];
                nxt.vis = pre.vis;
                nxt.vis[id[k]] = true;
                q.push(nxt);
            }
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) 
    {
        int u, v, wuv, wvu;
        scanf("%d %d %d %d", &u, &v, &wuv, &wvu);
        add(u, v, wuv, i);
        add(v, u, wvu, i);
    }
    bfs();
    return 0;
}