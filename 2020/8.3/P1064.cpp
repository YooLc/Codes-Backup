#include <iostream>
#include <cstdio>
const int MAXV = 3.2e4 + 5, MAXN = 65;
int vol[MAXN], val[MAXN], fa[MAXN];
int dp[MAXV], tot = 0;
using namespace std;
inline void add(int vo, int va, int f)
{
    cout << vo << " " << va << " " << f << " added" <<endl;
    vol[++tot] = vo;
    val[tot] = va;
    fa[tot] = f;
}
int main() 
{
    int V, n;
    scanf("%d %d", &V, &n);
    for (int i = 1; i <= n; ++i)
    {
        int v, p, q;
        scanf("%d %d %d", &v, &p, &q);
        add(v, v * p, q);
        if (!q) fa[tot] = i;
        for (int j = 1, u = tot; j < u; ++j)
        {
            if (fa[j] == fa[u]) 
                add(v + vol[j], v * p + val[j], q);
        }
    }
    for (int i = 1; i <= tot; ++i)
        for (int j = V; j >= vol[j]; --j)
            dp[j] = std::max(dp[j], dp[j - vol[j]] + val[j]);
    printf("%d", dp[V]);
    return 0;
}