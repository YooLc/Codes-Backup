#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 3e5 + 5;
int f[MAXN], mana;
int main() 
{
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int s, t, ans = -1;
    scanf("%d %d %d", &mana, &s, &t);
    f[0] = 0;
    /*
        f[i] 表示经过 i 秒后，守望者跑的路程的最大值
        策略是能闪则闪，不能就走
        可是两者同时考虑的时候，分类讨论容易出现问题（wtcl，90）
        看题解后知道了，如果不好分类讨论，那么可以尝试分开进行决策 - -
    */
    for (int i = 1; i <= t; ++i)
    {
        if (mana >= 10) // 最快速的转移
        {
            f[i] = f[i - 1] + 60;
            mana -= 10;
        }
        else
        {
            f[i] = f[i - 1];
            mana += 4;
        }
    }
    for (int i = 1; i <= t; ++i)
    {
        f[i] = max(f[i], f[i - 1] + 17); // 把走路的部分补回来
        if (f[i] >= s) { ans = i; break; }
    }
    if (ans == -1) printf("No\n%d", f[t]);
    else printf("Yes\n%d", ans);
    return 0;
}