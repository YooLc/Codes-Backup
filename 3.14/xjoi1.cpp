#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const static int MAXN = 104, MAXD = 155, N = 4e3 + 50, MOD = INT_MAX;
struct bign
{
    int len, s[MAXD];
    bign()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(int num) { *this = num; }
    bign(char *num) { *this = num; }
    bign operator=(int num)
    {
        char c[MAXD];
        sprintf(c, "%d", num);
        *this = c;
        return *this;
    }
    bign operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            s[i] = num[len - 1 - i] - '0';
        return *this;
    }
    string str()
    {
        string res = "";
        for (int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        return res;
    }
    void clean()
    {
        while (len > 1 && !s[len - 1])
            len--;
    }
    bign operator+(const bign &b)
    {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < len || i < b.len; i++)
        {
            int x = g;
            if (i < len)
                x += s[i];
            if (i < b.len)
                x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator*(const bign &b)
    {
        bign c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];
        for (int i = 0; i < c.len - 1; i++)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator+=(const bign &b)
    {
        *this = *this + b;
        return *this;
    }
}C[MAXN][MAXN], dp[MAXN][MAXN], sum;
istream &operator>>(istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream &operator<<(ostream &out, bign &x)
{
    out << x.str();
    return out;
}
inline int calc(int x, int y)
{
    if(x == 1) return y;
    if(y == 1) return x;
    int n = x - 1, m = y - 1, c;
    while(m % n != 0)
    {
        c = m % n;
        m = n;
        n = c;
    }
    return n + 1;
}
int main()
{
    for(int i = 1; i < MAXN; ++i) C[i][i] = 1, C[i][0] = 1;
    for(int i = 1; i < MAXN; ++i)
        for(int j = i + 1; j < MAXN; ++j)
            C[j][i] = C[j - 1][i - 1] + C[j - 1][i];
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    n += 2; m += 2;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 2; j <= m; ++j)
        {
            int num = calc(i, j);
            if(num > k) cout << i << " " << j << " " << num << " " << C[num - 1][k - 1] <<endl, sum = sum + C[num - 1][k - 1];
            else if(num == k) cout << i << " " << j << " " << num << " " << C[num][k] <<endl, sum = sum + C[num][k];
        }
    }
    cout << sum;
    return 0;
}