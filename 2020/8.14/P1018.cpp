#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 45;
bool flag;
struct BigNum
{
    const static int MAXL = 105;
    int data[MAXL], len;
    BigNum() { memset(data, 0, sizeof(data)); len = 1; }
    BigNum(char *str)
    {
        memset(data, 0, sizeof(data));
        len = strlen(str);
        for (int i = 0; i < len; ++i)
            data[i] = str[len - i - 1] - '0';
    }
    string to_string()
    {
        string ret = "";
        for (int i = len - 1; i >= 0; --i)
            ret += data[i]  + '0';
        return ret;
    }
    BigNum operator + (const BigNum &a)
    {
        BigNum b = *this; 
        b.len = max(a.len, b.len);
        for (int i = 0; i < b.len; ++i)
        {
            b.data[i] += a.data[i];
            if (b.data[i] >= 10)
            {
                b.data[i + 1]++;
                b.data[i] %= 10;
            }
        }
        if (b.data[b.len]) b.len++;
        return b;
    }
    BigNum operator * (const BigNum &a)
    {
        BigNum b = *this, c;
        for (int i = 0; i < a.len; ++i)
        {
            for (int j = 0; j < b.len; ++j)
            {
                c.data[i + j] += a.data[i] * b.data[j];
                c.data[i + j + 1] += c.data[i + j] / 10;
                c.data[i + j] %= 10;
            }
        }
        c.len = a.len + b.len;
        while (!c.data[c.len - 1] && c.len > 1) c.len--;
        return c;
    }
    bool operator < (const BigNum &rightObj) const
    {
        if (len < rightObj.len) return true;
        else if (len > rightObj.len) return false;
        for (int i = len - 1; i >= 0; --i)
        {
            if (data[i] < rightObj.data[i]) return true;
            else if (data[i] > rightObj.data[i]) return false;
        }
        return false;
    }
    BigNum slice(int l, int r)
    {
        BigNum ret;
        ret.len = (r - l + 1);
        for (int i = len - r, cur = 0; i <= len - l; ++i, ++cur)
            ret.data[cur] = data[i];
        return ret;
    }
} f[MAXN][MAXN];
char a[MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1018.in", "r", stdin);
    freopen("P1018.out", "w", stdout);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", a);
    BigNum t(a);
    BigNum v("1234"), b("1321");
    for (int i = 1; i <= n; ++i) f[i][0] = t.slice(1, i);
    /*
        f[i][j] 表示前 i 位数字有 j 个乘号时，结果的最大值
        f[i][j] = max(f[k][j - 1] * Num(k + 1, i)) 其中 k 范围为 [1, i)
    */
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k < i; ++k)
                f[i][j] = max(f[i][j], f[k][j - 1] * t.slice(k + 1, i));
    cout << f[n][m].to_string() << endl;
    return 0;
}