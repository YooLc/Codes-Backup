#include <iostream>
#include <cstdio>
using namespace std;
// int cnt[101][101], tot;
inline void print(int a, int b)
{
    cout << a << " " << b << endl;
    // cnt[a][b] = ++tot;
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    print(x, y);
    for (int i = y + 1; i <= m; ++i) print(x, i);
    for (int i = y - 1; i >= 1; --i) print(x, i);
    for (int cur = 1; x -  cur >= 1 && x + cur <= n; ++cur)
    {
        if (cur & 1)
        {
            for (int i = 1; i <= m; ++i)
            {
                if (i & 1)
                {
                    print(x - cur, i);
                    print(x + cur, i);
                }
                else 
                {
                    print(x + cur, i);
                    print(x - cur, i);
                }
            }
        }
        else
        {
            for (int i = m, c = m & 1; i >= 1; --i, ++c)
            {
                if (c & 1)
                {
                    print(x + cur, i);
                    print(x - cur, i);
                }
                else 
                {
                    print(x - cur, i);
                    print(x + cur, i);
                }
            }
        }
    }
    if (x * 2 - 1 < n)
    {
        for (int i = x * 2, cur = (x - 1) & 1; i <= n; ++i, ++cur)
        {
            if (cur & 1)
            {
                for (int j = m; j >= 1; --j)
                    print(i, j);
            }
            else
            {
                for (int j = 1; j <= m; ++j)
                    print(i, j);
            }
            
        }
    }
    else if (x * 2 - 1 > n)
    {
        for (int i = x - (n - x) - 1, cur = (n - x) & 1; i >= 1; --i, ++cur)
        {
            if (cur & 1)
            {
                for (int j = m; j >= 1; --j)
                    print(i, j);
            }
            else
            {
                for (int j = 1; j <= m; ++j)
                    print(i, j);
            }
            
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //         cout << cnt[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}