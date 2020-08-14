#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXM = 1e4 + 5;
int f[MAXM];
int main() 
{
    memset(f, 0, sizeof(f));
    f[0] = 1;
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) 
    {
        scanf("%d", &t);
        // 只能加一次，所以倒序来
        for (int j = m; j >= t; --j) 
            f[j] += f[j - t];
    }
    printf("%d", f[m]);
    return 0;
}