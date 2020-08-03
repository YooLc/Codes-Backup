#include <iostream>
using namespace std;
const int MAXN = 1050;
int a[MAXN], q[MAXN], m, n, res = 0;
void dfs(int cur, int ans)
{
    if(cur > n) { res = max(res, ans); return; }
    for(int i = 1; i <= m; ++i)
    {
        if(a[i] >= q[cur])
        {
            a[i] -= q[cur];
            dfs(cur + 1, ans + 1);
            a[i] += q[cur];
        }
    }
    dfs(cur + 1, ans);
}
int main()
{
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> q[n];
    dfs(1, 0);
    cout << res << endl;
    return 0;
}