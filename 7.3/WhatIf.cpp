#include <iostream>
#include <cstdio>
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
using namespace std;
const int MAXN = 1e4 + 50;
int n;
struct Carpet 
{
    int a, b, g, k;
} c[MAXN];
inline int findCarpet(int x, int y)
{
    for (int i = n; i >= 1; --i)
    {
        if (x >= c[i].a && x <= c[i].a + c[i].g && 
            y >= c[i].b && y <= c[i].b + c[i].k)
            return i;
    }
    return -1;
}
int main() 
{
    int x, y;
    n = rd();
    for (int i = 1; i <= n; ++i)
    {
        c[i].a = rd();
        c[i].b = rd();
        c[i].g = rd();
        c[i].k = rd();
    }
    x = rd(); y = rd();
    printf("%d", findCarpet(x, y));
    return 0;
}