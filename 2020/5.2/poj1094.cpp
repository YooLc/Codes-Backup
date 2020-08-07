#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40;
bool e[MAXN][MAXN], d[MAXN][MAXN], conflict;
int n, m;
struct Character { char ch; int num; };
inline bool cmp(Character a, Character b) { return a.num < b.num; }
inline void floyd()
{
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i)
        for (int j = 0 ; j < n; ++j)
            d[i][j] = e[i][j];
    for (int k = 0; k <= n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                d[i][j] |= (d[i][k] & d[k][j]);
                if (d[i][j] == 1 && d[j][i] == 1 && i != j) conflict = true;
            }
}
inline void printAns() // Reference: https://www.cnblogs.com/wyboooo/p/9972039.html
{
    Character t[MAXN];
    for (int i = 0; i < n; ++i)
    {
        t[i].ch = i + 'A';
        t[i].num = 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if(d[i][j]) t[i].num++;
    sort(t, t + n, cmp);
    for (int i = 0; i < n; ++i) printf("%c", t[i].ch);
    printf(".\n");
}
inline bool check()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if(d[i][j] == false && d[j][i] == false && i != j) return false;
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("poj1094.in", "r", stdin);
#endif
    while (~scanf("%d %d", &n, &m))
    {
        bool hasAnswer = false; int i; conflict = false;
        memset(e, 0, sizeof(e));
        // 特判
        if (n == 0 && m == 0) break;
        if (n == 1 && m == 0) puts("Sorted sequence determined after 0 relations: A."), hasAnswer = true;
        for (i = 1; i <= m; ++i)
        {
            char first, second;
            getchar(); // 回车
            scanf("%c<%c", &first, &second);
            e[second - 'A'][first - 'A'] = 1;
            if (!hasAnswer)
            {
                floyd();
                if (conflict == true) printf("Inconsistency found after %d relations.\n", i), hasAnswer = true;
                else if (check()) 
                {
                    printf("Sorted sequence determined after %d relations: ", i);
                    printAns();
                    hasAnswer = true;
                }
            }
        }
        if (i > m && !hasAnswer) printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}