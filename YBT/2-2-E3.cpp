#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1.5e4 + 50;
char str[MAXN];
int pref[MAXN];
int k, len, ans = 0, cnt = 0;
inline void getAndCalc(char *s, int len)
{
    if (len <= (k << 1)) return;
    for (int i = 0; i < len; ++i) pref[i] = 0;
    for (int i = 1; i < len; ++i)
    {
        cnt++;
        int j = pref[i - 1]; 
        while (j > 0 && s[i] != s[j]) j = pref[j - 1];
        if (s[i] == s[j]) ++j;
        pref[i] = j;
        if (i + 1 <= 2 * k) continue;
        int t = pref[i]; // t 是 A 段的长度，指向 A 段末尾字符的后一位（下标从 0 开始）
        // 两个相同的 A 段(长为 t)，拼起来要小于串长(i + 1)，给 B 留下位置
        while (t * 2 >= i + 1) t = pref[t - 1]; // 回溯到上一个相同的位置（下标）
        if (t >= k) ++ans; // A 段长度大于 k
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("2-2-E3.in", "r", stdin);
#endif
    // O[(n - 1) ^ 2 / 2] = O(n ^ 2)
    scanf("%s %d", str, &k);
    len = strlen(str);
    cerr << "Recieved string of " << len << " characters" << endl;
    for (int l = 0; l < len; ++l)
        getAndCalc(str + l, len - l);
    printf("%d\n", ans);
    cerr << "OK, looped " << cnt << " times" << endl;
    return 0;
}