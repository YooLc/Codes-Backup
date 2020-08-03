#include <iostream>
#include <cstdio>
const int MAXN = 1e6 + 50;
char str[MAXN];
int pref[MAXN], len;
long long ans = 0;
int main() 
{
    scanf("%d %s", &len, str);
    /*
        当且仅当
        1. A 是 B 的真前缀
        2. B 是 AA 的前缀
        时，我们称 A 是 B 的周期
        发现 A 首先是 B 的一个前缀，而且 B 剩下的部分必须要是 A 的前缀，
        这和前缀数组的功能是相匹配的，选用前缀数组。
        -----------
        题目中要求最大周期，也就相当于 B 中找到最短的相同前后缀，用 B 长度减去后缀长度即为所求。
        -----------
        前缀数组记录的是 B 中最长的相同前后缀，要转化为最小的。
        发现前缀数组其实记录了一颗树。（通过记录当前节点的“父节点”，也就是以当前字符为终止，前缀与后缀相同的位置）
        父节点记录的值肯定要比子节点记录的值小，而且都是合法的。
        那么只要父节点的值不为 0，就让他的儿子变为父节点的值就 ok 了。
        这里不需要 dfs，只需要在循环内部更新就行了，注意 0 没有贡献，不需要。
    */
    for (int i = 1; i < len; ++i)
    {
        int j = pref[i - 1];
        while (j > 0 && str[i] != str[j]) j = pref[j - 1];
        if (str[i] == str[j]) ++j;
        pref[i] = j;
    }
    for (int i = 1; i < len ;++i)
    {
        if (pref[pref[i] - 1]) pref[i] = pref[pref[i] - 1];
        if (pref[i]) ans += i + 1 - pref[i];
    }
    printf("%lld", ans);
    return 0;
}