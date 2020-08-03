#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
const static int MAXR = 1e5 + 5, MAXN = 10, MAXS = 1e2 + 5, MAXXS = (1 << 10) + 5, MOD = 1e6;
typedef long long LL;
int bits[10], aval[MAXS], tot = 0;
int n, m, k, kstate = 0;
int dp[2][MAXXS];
void watch(int s) {
    bitset<10> bst = s;
    cout << bst << endl;
}
inline void add(int &a, int &b) { a = (a + b) % MOD; }
inline int calc(int cur, int p, int tar) {
    cur -= (3 << bits[p]) & cur;
    cur |= tar << bits[p];
    return cur;
}
inline bool check(int pre, int cur)
{
    int preState[10], curState[10];
    for (int i = 0; i <= m; ++i) {
        preState[i] = pre >> bits[i] & 3;
        curState[i] = cur >> bits[i] & 3;
    }
    if(preState[0] == curState[0]) return false;
    for (int i = 1; i < m; ++i) {
        if(preState[i] == preState[i - 1]) return false;
        if(curState[i] == curState[i - 1]) return false;
        if(preState[i] == curState[i]) return false;
    }
    return true;
}
void dfs(int pre, int preState, int step)
{
    if(step == m) {
        aval[tot++] = preState;
        return;
    }
    for (int i = 0; i <= 2; ++i)
        if(i != pre)
            dfs(i, calc(preState, step, i), step + 1);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("1.txt", "w", stdout);
#endif
    for (int i = 0; i <= 10;++i)
        bits[i] = i << 1;
    scanf("%d %d %d", &n, &m, &k);
    int s, pre = -1, flag = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &s);
        kstate = calc(kstate, i, s - 1);
        if(pre != -1 && s == pre) flag = 0;
        pre = s;
    }
    dfs(0, 0, 1); dfs(1, 1, 1); dfs(2, 2, 1);
    if(!flag) {
        putchar('0');
        return 0;
    }
    int cur = 0;
    if(k == 1)
        dp[cur][kstate] = 1;
    else {
        for (int i = 0; i < tot; ++i)
            dp[cur][aval[i]] = 1;
    }
    for (int i = 2; i <= n;++i) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int prep = 0; prep < tot; ++prep) {
            if(i == k) {
                if(check(aval[prep], kstate)) {
                    add(dp[cur][kstate], dp[cur ^ 1][aval[prep]]);
                }
            }
            else {
                for (int curp = 0; curp < tot; ++curp) {
                    if(check(aval[prep], aval[curp])) {
                        add(dp[cur][aval[curp]], dp[cur ^ 1][aval[prep]]);
                    }
                }
            }
        }
    }
    if(n == k) printf("%d\n", dp[cur][kstate]);
    else {
        int sum = 0;
        for (int i = 0; i < tot; ++i)
            add(sum, dp[cur][aval[i]]);
        printf("%d", sum);
    }
    return 0;
}
