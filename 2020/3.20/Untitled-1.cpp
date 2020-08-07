#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5, A = 0, B = 1;
int n, a[N], b[N], f[N][2][2];
char ans[N];
inline void upd(int &x, int y) { if(y > x) x = y; }
int main()
{
    freopen("02-02.txt.in", "r", stdin);
    freopen("JOI1.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n << 1; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n << 1; i++) scanf("%d", &b[i]);
    memset(f, -1, sizeof f);
    f[1][A][A] = 1; f[1][A][B] = 0; f[1][B][A] = 0; f[1][B][B] = 1;
    for(int i = 2; i <= n << 1; i++)
    {
        if(a[i - 1] <= a[i])
            upd(f[i][A][A], f[i - 1][A][A] + 1), upd(f[i][A][B], f[i - 1][A][B]);
        if(b[i - 1] <= a[i])
            upd(f[i][A][A], f[i - 1][B][A] + 1), upd(f[i][A][B], f[i - 1][B][B]);
        if(a[i - 1] <= b[i])
            upd(f[i][B][A], f[i - 1][A][A]), upd(f[i][B][B], f[i - 1][A][B] + 1);
        if(b[i - 1] <= b[i])
            upd(f[i][B][A], f[i - 1][B][A]), upd(f[i][B][B], f[i - 1][B][B] + 1);
    }
    cout<<f[n<<1][A][B]<<" "<<f[n<<1][B][A]<<endl;
    int cntA = 0, cntB = 0, lst = 1<<30;
    for(int i = n << 1; i; i--)
    {

        if(cntA + f[i][A][A] >= n && cntB + f[i][A][B] >= n && a[i] <= lst)
            cntA++, ans[i] = 'A', lst = a[i];
        else if(cntA + f[i][B][A] >= n && cntB + f[i][B][B] >= n && b[i] <= lst)
            cntB++, ans[i] = 'B', lst = b[i];
        else return puts("-1") && 0;
    }
    for(int i = 1; i <= n << 1; i++) putchar(ans[i]);
    return 0;
}