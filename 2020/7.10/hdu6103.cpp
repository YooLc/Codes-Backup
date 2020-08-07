#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 5e3 + 50;
char str[MAXN];
inline void solve()
{
    int m, len, ans = 0;
    scanf("%d %s", &m, str);
    len = strlen(str);
    // 枚举中点和字符串长度 -> n ^ 3 变 n ^ 2
    // 而且方便剪枝 -> 结果单调不减小
    for (int mid = 0; mid < len; ++mid)
    {
        int sum = 0, t = 0;
        // mid 为正中间，总长为奇数
        for (int l = 1; mid - l >= 0 && mid + l < len; ++l)
        {   
            sum += abs(str[mid - l] - str[mid + l]);
            // 进行尺取
            if (sum <= m) ans = max(ans, l - t);
            else 
            {
                while (sum > m && t <= l) t++, sum -= abs(str[mid - t] - str[mid + t]);
                if (sum <= m) ans = max(ans, l - t);
            }
        }
        sum = 0; t = 0;
        // mid 为中间，包含在后面的串里，总长为偶数
        for (int l = 1; mid - l >= 0 && mid + l - 1 < len; ++l)
        {
            sum += abs(str[mid - l] - str[mid + l - 1]);
            // 进行尺取
            if (sum <= m) ans = max(ans, l - t);
            else 
            {
                while (sum > m && t <= l) t++, sum -= abs(str[mid - t] - str[mid + t - 1]);
                if (sum <= m) ans = max(ans, l - t);
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) solve();
    return 0;
}