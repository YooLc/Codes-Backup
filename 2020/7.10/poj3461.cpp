#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e6 + 5, p = 131;
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
    ull getSubstrHash(int s, int len) { return hash[s + len] - hash[s] * pow[len]; }
} a, b;
int main() 
{
    pow[0] = 1;
    for (int i = 1; i < MAXN; ++i) pow[i] = pow[i - 1] * p;
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%s\n%s", a.text, b.text);
        a.getHash(); b.getHash();
        int ans = 0;
        for (int i = 0; i + a.len - 1 < b.len; ++i)
            if (b.getSubstrHash(i, a.len) == a.hash[a.len]) 
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}