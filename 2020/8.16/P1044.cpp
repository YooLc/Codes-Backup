#include <iostream>
#include <cstdio>
int f[20];
int catlan(int n)
{
    if (f[n] > 0) return f[n];
    for (int i = 1; i <= n; ++i) f[n] += catlan(n - i) * catlan(i - 1);
    return f[n];
}
int main() 
{
    /*
        这道题如果真的推的话，绝对不是 普及- 难度 = =
        不过这不就是卡特兰数吗，背就完事了
    */
    int n;
    f[0] = f[1] = 1;
    scanf("%d", &n);
    printf("%d", catlan(n));
    return 0;
}