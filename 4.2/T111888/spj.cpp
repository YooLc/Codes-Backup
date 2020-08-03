#include "testlib.h"
const int MAXN = 105;
struct Comp
{
    int x, y;
} v[MAXN];
bool vis[MAXN];
int main(int argc, char* argv[]) 
{
    registerTestlibCmd(argc, argv);
    int n, tx, ty, sx = 0, sy = 0;
    n = inf.readInt(0, 100);
    for(int i = 1; i <= n; ++i) v[i].x = inf.readInt(-10000, 10000), v[i].y = inf.readInt(-10000, 10000);
    tx = inf.readInt(-10000, 10000); ty = inf.readInt(-10000, 10000);
    int parttot = ouf.readInt(), anstot = ans.readInt();
    for(int i = 1; i <= parttot; ++i)
    {
        int id = ouf.readInt(1, n);
        if (vis[id]) quitf(_wa, "You can't use vector No.%d twice.", id);
        sx += v[id].x; sy += v[id].y;
        vis[id] = true;
    }
    if(sx == tx && sy == ty)
    {
        if(anstot < parttot) quitf(_ok, "Your answer is correct with %d vector(s). But Luster is better than you, with %d vector(s).", parttot, anstot);
        else if(anstot > parttot) quitf(_ok, "Your answer is correct with %d vector(s). You are even better than Luster with %d vector(s).", parttot, anstot);
        else quitf(_ok, "Your answer is correct with %d vector(s). Same with Luster.", parttot);
    }
        
    else quitf(_wa, "The answer is wrong: expected (%d, %d), found (%d, %d).", tx, ty, sx, sy);
}