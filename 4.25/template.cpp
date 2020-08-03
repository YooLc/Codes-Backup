#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    
    return 0;
}