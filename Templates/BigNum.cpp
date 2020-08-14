#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// 非压位高精注释版
struct BigNum
{
    const static int MAXL = 4005; // 数组长度
    int data[MAXL], len;
    BigNum() { memset(data, 0, sizeof(data)); }
    BigNum(char *str)
    {
        memset(data, 0, sizeof(data));
        len = strlen(str);
        for (int i = 0; i < len; ++i)
            data[i] = str[len - i - 1] - '0';
    }
    void output()
    {
        for (int i = len - 1; i >= 0; --i)
            printf("%d", data[i]);
    }
    string to_string()
    {
        string ret = "";
        for (int i = len - 1; i >= 0; --i)
            ret += data[i];
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
};
typedef BigNum LL;
char s[2005];
int main() 
{
    LL a("21387941263897457892354987519875233748912");
    LL b("1231243129824356134578902354");
    (a + b).output();
    putchar('\n');
    (a * b).output();
    return 0;
}