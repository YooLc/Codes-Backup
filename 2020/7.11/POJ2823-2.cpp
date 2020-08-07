// 强烈感谢: https://loj.ac/submission/739580 请选择显示原始代码 欢迎讨论
// 左边: [0, mid]
// 右边: [mid + 1, n - 1]
#include <iostream>
#include <cstdio>
const int MAXN = 2e6 + 5;
char str[MAXN], obuf[MAXN], *o = obuf;
int n, mid;
bool misMatched, pos[2];
inline void fput(char *a) { while (*a != '\0') *o++ = *a++;} 
int main()
{
    scanf("%d %s", &n, str);
    mid = (n >> 1);
    if (!(n & 1)) { puts("NOT POSSIBLE"); return 0; }    // 偶数个不可能
    for (int l = 0, r = mid; r < n; ++l, ++r)            // 假设错误在左边
        if(str[l] != str[r])                             // 有错误
            if (!misMatched) { --l; misMatched = true; } // 确定在左半部分
            else { pos[0] = true; break; }               // 左半部分有确定的错误
    misMatched = false;
    for (int l = 0, r = mid + 1; r < n; ++l, ++r)        // 假设错误在右边
        if(str[l] != str[r])                             // 有错误
            if (!misMatched) { --r; misMatched = true; } // 确定在右半部分
            else { pos[1] = true; break; }               // 右半部分有确定的错误
    if (!pos[1])                                                // 右边没有确定的错误
        if (!misMatched || pos[0])                              // 右边没有失配 || 左边有确定的错误
            for (int i = mid + 1; i < n; ++i) *o++ = str[i];    // 输出右边的
        else fput("NOT UNIQUE");                                // 失配了但左右都没有确定的错误：只有多个错误才会发生
    else if (pos[0]) fput("NOT POSSIBLE");                      // 左右都有确定的错误：这不可能发生
    else for (int i = 0; i < mid; ++i) *o++ = str[i];           // 右边有确定的错误，左边没有， 输出左边的
    fwrite(obuf, o - obuf, 1, stdout);
    return 0;
}