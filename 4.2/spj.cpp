#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 150;
struct Comp
{
    int x, y, id;
} v[MAXN];
int test[MAXN], tot, n, tx, ty;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test1.in", "r", stdin);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d %d", &v[i].x, &v[i].y), v[i].id = i;
    scanf("%d %d", &tx, &ty);
    while(scanf("%d", &test[++tot]) != -1);
    int sx = 0, sy = 0;
    for(int i = 1; i <= tot; ++i)
        sx += v[test[i]].x, sy += v[test[i]].y;
    cout<<sx<<" "<<sy<<endl;
    return 0;
}