// Reference: https://www.cnblogs.com/syksykCCC/p/LOJ3271.html
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const static int MAXN = 5e5 + 50;
int f[MAXN << 1][2][2], A[MAXN << 1], B[MAXN << 1];
char ans[MAXN << 1];
// f[i][A/B][A/B] stands for the max amount of A/B (second) we can get 
// while we currently choose A/B (first) 
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
inline int max(int a, int b) { return (a > b) ? a : b; } 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("02-02.txt.in", "r", stdin);
    freopen("JOI1.out", "w", stdout);
#endif
    memset(f, -1, sizeof(f));
    int n, m, a = 0, b = 1;
    n = rd(); m = n << 1;
    for(int i = 1; i <= m; ++i) A[i] = rd();
    for(int i = 1; i <= m; ++i) B[i] = rd();
    f[1][a][a] = 1; f[1][b][b] = 1;
    f[1][a][b] = 0; f[1][b][a] = 0;
    for(int i = 2; i <= m; ++i)
    {
        // We could use A[i]
        if(A[i - 1] <= A[i]) 
        {
            f[i][a][a] = max(f[i][a][a], f[i - 1][a][a] + 1); // as we append A
            f[i][a][b] = max(f[i][a][b], f[i - 1][a][b]);
        }
        if(B[i - 1] <= A[i])
        {
            f[i][a][a] = max(f[i][a][a], f[i - 1][b][a] + 1);
            f[i][a][b] = max(f[i][a][b], f[i - 1][b][b]);
        }
        // We could use B[i]
        if(A[i - 1] <= B[i])
        {
            f[i][b][a] = max(f[i][b][a], f[i - 1][a][a]);
            f[i][b][b] = max(f[i][b][b], f[i - 1][a][b] + 1); // as we append B
        }
        if(B[i - 1] <= B[i])
        {
            f[i][b][a] = max(f[i][b][a], f[i - 1][b][a]);
            f[i][b][b] = max(f[i][b][b], f[i - 1][b][b] + 1);
        }
    }
    //cout<<f[m][a][b]<<" "<<f[m][b][a]<<endl;
    //cout<<f[m][b][b]<<" "<<f[m][a][a]<<endl;
    int cnta = 0, cntb = 0, lst = 2147483647, flag = 1;
    for(int i = m; i >= 1; --i)
    {
        if(cnta + f[i][a][a] >= n && cntb + f[i][a][b] >= n && A[i] <= lst) // In this case, we can chose A[i], since both A and B amount could be higher than N
            cnta++, ans[i] = 'A', lst = A[i];
        else if (cnta + f[i][b][a] >= n && cntb + f[i][b][b] >= n && B[i] <= lst) // In this case, we can chose B[i], in the same reason
            cntb++, ans[i] = 'B', lst = B[i];
        else { flag = 0; break; }
    }
    if(flag) 
    {
        for(int i = 1; i <= m; ++i)
            putchar(ans[i]);
    }
    else puts("-1");
    return 0;
}