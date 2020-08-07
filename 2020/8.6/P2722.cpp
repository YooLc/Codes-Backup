#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> f;
int main() 
{
    int m, n, time, score;
    scanf("%d %d", &m, &n);
    f.resize(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &score, &time);
        for (int j = time; j <= m; ++j)
            f[j] = max(f[j], f[j - time] + score);
    }
    printf("%d", f[m]);
    return 0;
}