#include <iostream>
#include <cstdio>
const int MAXN = 1e3 + 5;
int weight[6] = {1, 2, 3, 5, 10, 20}, count[6];
bool f[MAXN];
int main() 
{
    for (int i = 0; i < 6; ++i) scanf("%d", &count[i]);
    f[0] = true;
    for (int i = 0; i < 6; ++i)
        for (int j = 1; j <= count[i]; ++j)
            for (int k = MAXN - 1; k >= j * weight[i]; --k)
                f[k] |= f[k - weight[i]];
    int ans = 0;
    for (int i = 1; i < MAXN; ++i) ans += f[i];
    printf("Total=%d", ans);
    return 0;
}