#include <iostream>
#include <algorithm>
const int MAXN = 3e4 + 5;
struct Data {
    int start, end, target;
} d[MAXN];
int tree[MAXN], n, h, ans = 0;
bool check[MAXN];
char buf[(int)3e5], *p = buf;
bool cmp(Data a, Data b) { return a.end < b.end; }
inline int lowbit(int &x) { return x & (-x); }
inline int init(){ buf[fread(buf, 1, (int)3e5 - 1, stdin)] = '\n'; fclose(stdin); return 0; }
inline int rd() 
{
    int t = 0;
    while(!isdigit(*p)) ++p;
    while(isdigit(*p)) t = t * 10 + (*p++ ^ '0');
    return t;
}
void add(int x, int k) { while (x <= n) tree[x] += k, x += lowbit(x); }
int sum(int x) { int s = 0; while(x) { s += tree[x]; x -= lowbit(x); } return s; }
int main()
{
    init(); n = rd(); h = rd();
    for (int i = 1; i <= h; ++i) d[i] = Data{rd(), rd(), rd()}; // 构造函数的读入顺序是怎样的...
    std::sort(d + 1, d + 1 + h, cmp);
    for (int i = 1; i <= h; ++i)
    {
        int s = sum(d[i].end) - sum(d[i].start - 1);
        if (s >= d[i].target) continue;
        d[i].target -= s;
        for (int j = d[i].end; j >= 1; --j)
            if (d[i].target) { if (!check[j]) check[j] = true, add(j, 1), d[i].target--; }
            else break;
    }
    printf("%d", sum(n));
    return 0;
}