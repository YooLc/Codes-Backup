#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
inline void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, head, tail, q[800000][3];
bool vis[20050][97];
inline void push(int p1, int p2, int step)
{
    if (p1 < 20050 && p2 < 97)
    {
        if(vis[p1][p2]) return;
        else vis[p1][p2] = true;
    }
    if (p1 > n && !p2) return;
    if (p1 < p2) swap(p1, p2);
    if (p2 > 97) return;
    if (p1 == p2) return;
    if (n % gcd(p1, p2)) return;
    q[tail][0] = p1;
    q[tail][1] = p2;
    q[tail][2] = step;
    ++tail;
}
inline int bfs()
{
    push(1, 0, 0);
    while(head < tail)
    {
        int p1 = q[head][0], p2 = q[head][1], step = q[head][2];
        head++;
        if (p1 == n || p2 == n) { return step; }
        push(p1 + p2, p1, step + 1);
        push(p1 + p2, p2, step + 1);
        push(p1 << 1, p1, step + 1);
        push(p1 << 1, p2, step + 1);
        push(p2 << 1, p1, step + 1);
        push(p2 << 1, p2, step + 1);
        push(p1 - p2, p1, step + 1);
        push(p1 - p2, p2, step + 1);
    }
    return 0;
}
int main()
{
    freopen("test.out","w",stdout);
    for(int i = 1; i <= 20000; ++i)
    {
        head = tail = 0;
        memset(vis, 0, sizeof(vis));
        n = i;
        printf("%d\n", bfs());
    }
    head = tail = 0;
        memset(vis, 0, sizeof(vis));
        n = 19997;
        cerr<<bfs()<<endl;
    return 0;
}