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
int main() 
{
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdin);
#endif
    
    return 0;
}