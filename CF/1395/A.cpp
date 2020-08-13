#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;
inline bool solve()
{
    LL a[4], b[4];
    for (int i = 0; i <= 3; ++i) cin >> a[i];
    LL t = min(min(a[0], a[1]), a[2]);
    int odd = 0, even = 0;
    bool flag = false;
    for (int i = 0; i <= 3; ++i)
        if ((a[i] & 1) && a[i] > 0) odd++;
        else if (a[i] > 0) even++;
    if (t > 0)
    {
        if (odd <= 1 || even <= 1) return true;
        return false;
    }
    else 
    {
        if (odd <= 1) return true;
        else return false;
    }
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        puts(solve() ? "Yes" : "No");
    return 0;
}