#include <cstdio>
#include <cstring>
typedef unsigned int ull;
const int MAXN = 2e6 + 5, base = 20040817;
ull _hash[MAXN], pow[MAXN];
char str[MAXN];
inline int getHash(int l, int r) 
{ 
    if (r < l) return 0ull;
    return _hash[r + 1] - _hash[l] * pow[r - l + 1]; // [0..(n - 1)] ---> [1..n]
}
int main()
{
    pow[0] = 1; _hash[0] = 0;
    for (int i = 1; i < MAXN; ++i) pow[i] = pow[i - 1] * base;
    int n, len, isUnique = 1;
    ull lasthash = -1ull;
    scanf("%d\n%s", &n, str);
    if (!(n & 1)) { printf("NOT POSSIBLE"); return 0; }
    len = strlen(str);
    int mid = len >> 1, idx = -1;
    for (int i = 0; i < len; ++i)
        _hash[i + 1] = _hash[i] * base + str[i] - 'A';
    for (int i = 0; i <= mid; ++i)
    {
        ull lhash = getHash(0, i - 1) * pow[mid - i] + getHash(i + 1, mid);
        ull rhash = getHash(mid + 1, mid + i) * pow[mid - i] + getHash(mid + i + 1, len - 1);
        if (lhash == rhash)
        {
            idx = mid + 1;
            lasthash = rhash;
            break;
        }
    }
    for (int i = mid + 1; i < len; ++i)
    {
        ull rhash = getHash(mid, i - 1) * pow[len - i - 1] + getHash(i + 1, len - 1);
        ull lhash = getHash(0, i - mid - 1) * pow[len - i - 1] + getHash(i - mid, mid - 1);
        if (rhash == lhash) 
        {
            idx = 0;
            if (lhash != lasthash && ~lasthash) { isUnique = 0; break; } // 必定在两侧？
            lasthash = lhash;
            break;
        }
    }
    if (!isUnique) puts("NOT UNIQUE");
    else if (~lasthash) for (int t = 0; t < mid; t++) putchar(str[idx + t]);
    else puts("NOT POSSIBLE");
}