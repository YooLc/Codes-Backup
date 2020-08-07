#include <iostream> 
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 50;
string strPool[MAXN];

inline void solve()
{
    int n, lmin = 150, tmin = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> strPool[i];
        if (strPool[i].length() < lmin) 
            lmin = strPool[i].length(), tmin = i;
    }
    int len = strPool[tmin].length();
    for (int i = 0; i < len; ++i)
    {
        for (int t = 1; i + t - 1 < len; ++t)
        {
            bool canUse = true;
            string tstr = strPool[tmin].substr(i, t);
            string rstr = tstr;
            reverse(rstr.begin(), rstr.end());
            for (int j = 1; j <= n; ++j)
            {
                if(strPool[j].find(tstr) == string::npos &&
                   strPool[j].find(rstr) == string::npos)
                   canUse = false;
            }
            if (canUse) ans = max(ans, (int) tstr.length());
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) 
        solve();
    return 0;
}