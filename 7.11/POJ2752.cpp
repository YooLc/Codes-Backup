#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 4e5 + 5, p = 20040817;
ull pow[MAXN];
struct MyString {
    ull hash[MAXN];
    char text[MAXN];
    int len;
    void getHash()
    {
        hash[0] = 0;
        len = strlen(text);
        for (int i = 0; i < len; ++i)
            hash[i + 1] = hash[i] * p + text[i] - 'A';
    }
    ull getSubstrHash(int l, int r) { return hash[r + 1] - hash[l] * pow[r - l + 1]; }
} a;
int main() 
{
    pow[0] = 1;
    for (int i = 1; i < MAXN; ++i) pow[i] = pow[i - 1] * p;
    while(~scanf("%s", a.text))
    {
        a.getHash();
        for (int i = 0; i < a.len; ++i)
            if (a.getSubstrHash(0, i) == a.getSubstrHash(a.len - 1 - i, a.len - 1))
                printf("%d ", i + 1);
        putchar('\n');
    }
    return 0;
}