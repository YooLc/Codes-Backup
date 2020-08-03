#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 150;
struct Comp
{
    int x, y, id;
} v[MAXN];
int n, tx, ty, ans[MAXN], tot, flag;
bool vis[MAXN];
struct State
{
    int curx, cury;
    vector<int> ans;
};
// 优化搜索顺序
inline int dist(int x, int y) { return sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y)); }
bool cmp(Comp &a, Comp &b) { return dist(a.x, a.y) < dist(b.x, b.y); }
inline bool operator< (const State &a, const State &b) { return dist(a.curx, a.cury) > dist(b.curx, b.cury); }
// Search
inline bool bfs()
{
    priority_queue<State> q;
    State s; s.curx = 0; s.cury = 0;
    q.push(s);
    while(q.size())
    {
        State pre = q.top();
        cout << pre.curx << " " << pre.cury << endl;
        for(auto i : pre.ans) printf("%d ", i);
        cout<<endl;
        q.pop();
        if(pre.curx == tx && pre.cury == ty)
        {
            for(auto i : pre.ans) printf("%d ", i);
            return true;
        }
       // cout<<"Chosing: Phase "<<<<endl;
        for(int i = 1; i <= n; ++i)
        {
            if(count(pre.ans.begin(), pre.ans.end(), v[i].id) > 0) continue;
            // cout << count(pre.ans.begin(), pre.ans.end(), v[i].id) << " " <<v[i].id<<endl;
            State nxt;
            nxt.curx = pre.curx + v[i].x;
            nxt.cury = pre.cury + v[i].y;
            nxt.ans = pre.ans;
            nxt.ans.push_back(v[i].id);
            printf("(%d, %d) -> (%d, %d)\n", pre.curx, pre.cury, nxt.curx, nxt.cury);
            q.push(nxt);
        }
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) 
    {
        scanf("%d %d", &v[i].x, &v[i].y), v[i].id = i;
    }
    scanf("%d %d", &tx, &ty);
    sort(v + 1, v + 1 + n, cmp);
    // for(int i = 1; i <= 4; ++i)
    // {
    //     cout << i << endl;
    //     for(auto j : s[i]) cout << j.x << " " << j.y << endl;
    // }
    if(!bfs()) puts("impossible");
    return 0;
}