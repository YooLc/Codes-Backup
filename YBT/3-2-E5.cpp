#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 2.5e4 + 5, MAXM = 1e5 + 5, INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM << 1], ver[MAXM << 1], edge[MAXM << 1], tot;
int dis[MAXN]; bool inq[MAXN];
// 手打队列，舒服
struct Deque 
{
    int head, tail, tot;
    int data[MAXN];
    /* 这里得循环用，否则空间不够 */
    int size() { return tot; }
    int front() { return data[head]; }
    bool empty() { return !(head ^ tail); } // head != tail
    void pop_front() { ++head; head %= MAXN; --tot; }
    void pop_back() { tail = (tail - 1 + MAXN) % MAXN; --tot; }
    void push_back(int v) { data[tail++] = v; tail %= MAXN; ++tot; }
    void push_front(int v) { head = (head - 1 + MAXN) % MAXN; data[head] = v; ++tot; }
    void clear() { head = tail = 0; memset(data, 0, sizeof(data));}
} q;
inline void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
} 
inline void spfa(int s)
{
    
    memset(dis, 0x3f, sizeof(dis));
    memset(inq, false, sizeof(inq));
    q.clear();
    q.push_back(s);
    dis[s] = 0;
    inq[s] = true;
    int sum = 0;
    while (!q.empty())
    {
        int u = q.front(); 
        // while (dis[u] * q.size() > sum)
        // {
        //     q.pop_front();
        //     q.push_back(u);
        //     u = q.front();
        // }
        q.pop_front(); 
        // sum -= dis[u];
        inq[u] = false;
        for (int k = head[u]; k; k = nxt[k])
        {
            int v = ver[k];
            if (dis[v] > dis[u] + edge[k])
            {
                dis[v] = dis[u] + edge[k];
                if (!inq[v])
                {
                    inq[v] = true;
                    if (dis[v] < dis[q.front()] && !q.empty()) q.push_front(v);
                    else q.push_back(v);
                    // sum += dis[v];
                }
            }
        }
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("3-2-E5.in", "r", stdin);
    freopen("3-2-E5.out", "w", stdout);
#endif
    /*
        有负权没负环的最短路，肯定选 SPFA 啊
        - 关于 SPFA， 它死了（这也要卡....
        - SLF, LLF 太神了....快了不少....
        - SLF, 将入队的点 v, 队首 u, 若 dis[v] < dis[u] 则插入队首
        - LLF, 不断调整队首, 使 dis[u] 小于平均值
        - 本题 SLF 优化明显， LLF 优化不明显，甚至可能负优化= =（要看出题人的数据怎么卡，所以 SPFA 还是死透的....
        - Reference: https://www.cnblogs.com/gosick/p/9492634.html
    */
    int T, R, P, S;
    T = rd(); R = rd(); P = rd(); S = rd();
    for (int i = 1; i <= R; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= P; ++i)
    {
        int u, v, w;
        u = rd(); v = rd(); w = rd();
        add(u, v, w);
    }
    spfa(S);
    for (int i = 1; i <= T; ++i)
    {
        if (dis[i] < INF) printf("%d\n", dis[i]);
        else printf("NO PATH\n");
    }
    return 0;
}