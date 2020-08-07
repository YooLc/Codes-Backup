#include <iostream>
#include <cstdio>
using namespace std;
const static int MAXN = 5e5 + 50;
int A[MAXN << 1], B[MAXN << 1], n, m;
bool flag = false;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
void dfs(int cur, int lastp, int cnta, int cntb, string ops)
{
    //cout << cnta << " " << cntb << " " << ops << endl;
    // 0 for A
    // 1 for B
    if(flag) return;
    if(cur == m + 1)
    {
        flag = true;
        cout << ops;
        return;
    }
    if(lastp == 0)
    {
        if(A[cur] >= A[cur - 1] && cnta + 1 <= n && B[cur] >= A[cur - 1] && cntb + 1 <= n)
        {
            if(A[cur] < B[cur])
            {
                dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
                dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
            }
            else
            {
                dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
                dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
            }
            
        }
        else if(A[cur] >= A[cur - 1] && cnta + 1 <= n) dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
        else if(B[cur] >= A[cur - 1] && cntb + 1 <= n) dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
    }
    if(lastp == 1)
    {
        if(A[cur] >= B[cur - 1] && cnta + 1 <= n && B[cur] >= B[cur - 1] && cntb + 1 <= n)
        {
            if(A[cur] < B[cur])
            {
                dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
                dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
            }
            else
            {
                dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
                dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
            }
            
        }
        else if(A[cur] >= B[cur - 1] && cnta + 1 <= n) dfs(cur + 1, 0, cnta + 1, cntb, ops + "A");
        else if(B[cur] >= B[cur - 1] && cntb + 1 <= n) dfs(cur + 1, 1, cnta, cntb + 1, ops + "B");
    }
}
int main()
{
    //freopen("JOI1.in", "r", stdin);
    n = rd(); m = n << 1;
    for(int i = 1; i <= m; ++i) A[i] = rd();
    for(int i = 1; i <= m; ++i) B[i] = rd();
    dfs(1, 0, 0, 0, "");
    if(!flag) dfs(1, 1, 0, 0, "");
    if(!flag) printf("-1");
    return 0;
}