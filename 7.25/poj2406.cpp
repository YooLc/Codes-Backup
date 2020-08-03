#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN = 1e6 + 50, p = 19260817;
char str[MAXN];
typedef unsigned long long ULL;
ULL pow[MAXN], _hash[MAXN], len;
inline int calcHash(int l, int r) { return _hash[r + 1] - _hash[l] * pow[r - l + 1]; }
using namespace std;
int main() 
{ 
    pow[0] = 1;
    for (int i = 1; i < MAXN; ++i) pow[i] = pow[i - 1] * p;
    while (~scanf("%s", str))
    {
        int len = strlen(str);
        if (str[0] == '.' && len == 1) break;
        _hash[0] = 0;
        for (int i = 0; i < len; ++i)
            _hash[i + 1] = _hash[i] * p + str[i] - 'A';
        
        for (int i = 1; i <= len; ++i)
        {
            if (len % i) continue;
            int t = calcHash(0, i - 1); bool isOkay = true;
            for (int j = i; j + i - 1 < len; j += i)
                if (calcHash(j, j + i - 1) != t) 
                    { isOkay = false; break; }
            if (isOkay) { printf("%d\n", len / i); break; }
        }
    }
    return 0;
}