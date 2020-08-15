#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
const int MAXN = 1e5 + 5;
int arr[MAXN], f[MAXN][2][2];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2612/flower9.in", "r", stdin);
#endif
    /*
        f[i][0][0] 表示前 i 盆花符合 A 条件且第 i 盆为偶数盆
        f[i][1][1] 表示前 i 盆花符合 B 条件且第 i 盆为奇数盆
        以此类推
    */
    int n = rd();
    for (int i = 1; i <= n; ++i) arr[i] = rd();
    f[1][0][1] = f[1][1][0] = f[1][0][0] = f[1][1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        bool flag1 = false, flag2 = false;
        for (int j = i - 1; j >= 1; --j)
        {
            if (arr[j] < arr[i])
            {
                f[i][0][0] = max(f[i][0][0], f[j][0][1] + 1);
                f[i][1][1] = max(f[i][1][1], f[j][1][0] + 1);
                flag1 = true;
            }
            else if (arr[j] > arr[i])
            {
                f[i][0][1] = max(f[i][0][1], f[j][0][0] + 1);
                f[i][1][0] = max(f[i][1][0], f[j][1][1] + 1);
                flag2 = true;
            }
            if (flag1 && flag2) break;
        }
    }
    int ans = max(max(f[n][0][0], f[n][0][1]), max(f[n][1][0], f[n][1][1]));
    printf("%d", ans);
    return 0;
}