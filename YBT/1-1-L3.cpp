#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1.5e4 + 5;
const double eps = 1e-11;
struct Data {
    double start, end;
    bool operator< (const Data &b) const { return start < b.start; }
} d[MAXN];
bool cmp(Data &a, Data &b) { return a.start < b.start; }
int main()
{
    double n, L, W; int cnt;
    while(cin >> n >> L >> W)
    {
        cnt = 0;
        double w = W / 2.0;
        for (int i = 1; i <= n; ++i)
        {
            double o, r; cin >> o >> r;
            if (r <= w) continue; // 无效
            double l = sqrt(r * r - w * w);
            d[++cnt].start = o - l;
            d[cnt].end = o + l;
        }
        std::sort(d + 1, d + 1 + cnt);
        double s = 0.0;
        int cur = 1, ans = 0;
        while (s < L + eps && cur <= cnt)
        {
            ans++;
            double ori_s = s;
            for (; d[cur].start <= ori_s && cur <= cnt; ++cur) 
                if (d[cur].end > s) s = d[cur].end;
            if (ori_s == s && ori_s < L + eps) { ans = -1; break; }     
        }
        cout << ans << endl;
    }
    return 0;
}