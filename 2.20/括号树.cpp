// I'm sorry.
//Thanks to Social_Zhao
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 5e5 + 5;
char brac[maxn];
int len, fa[maxn], dp[maxn], nxt[maxn], top;
long long ans, sum[maxn];
inline long long rd()
{
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9'){ x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    return x * f;
}
int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    len = rd();
    scanf("%s", brac + 1);
    for (int i = 2; i <= len; i++)
        fa[i] = rd();
    for (int i = 1; i <= len; i++)
    {
        if (brac[i] == '(') nxt[i] = i; //添加左括号
        else
        {
            nxt[i] = nxt[fa[i]]; //记录上一个左括号位置
            if (nxt[i])
            {
                dp[i] = dp[fa[nxt[i]]] + 1; //贡献值为上一次匹配贡献值+1
                //若上一次贡献值非0，则两个区间比如() (())可以合并，可以和之前每一个合法串组成新串
                //也可以自己组成一串，若为0，则只有自己，为1
                nxt[i] = nxt[fa[nxt[i]]]; //已用该左括号，转为匹配上一个左括号
            }
        }
        sum[i] = sum[fa[i]] + dp[i]; //求和，dp数组实际可以看成一个差分数组
        ans ^= (sum[i] * i);
    }
    printf("%lld", ans);
    return 0;
}