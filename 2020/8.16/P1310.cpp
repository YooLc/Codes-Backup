#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 50, MOD = 1e5 + 7;
typedef long long LL;
int p[50] = { 0 };
struct Data
{
    char op;
    LL f[2];
    Data() { f[0] = f[1] = 0; }
};
inline Data newNode(char c)
{
    Data t;
    t.op = c;
    if (c == '+') t.f[0] = 1, t.f[1] = 3;
    else if (c == '*') t.f[0] = 3, t.f[1] = 1; 
    return t;
}
char expr[MAXN];
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1310.in", "r", stdin);
    // freopen(".out", "w", stdout);
#endif
    // ios::sync_with_stdio(false);
    // int len;
    // cin >> len >> expr;
    // stack<Data> stk;
    // p['+'] = 1; p['*'] = 2;
    // for (int i = 0; i < len; ++i)
    // {
    //     if (expr[i] == '(') stk.push(newNode('('));
    //     else if (expr[i] == '+' && expr[i] == '*')
    //     {
    //         // '*' 42, '+' 43.
    //         while (!stk.empty() && stk.top().op != '(' && p[(int)stk.top()] >= p[(int)expr[i]])
    //         {
    //             Data t = stk.top(); stk.pop();
    //             Data k = stk.top(); stk.pop();
    //             // '*'
    //             t.f[1] = k.f[1] * kf[1]) % MOD;
    //             rt->f[0] = ((rt->l->f[0] * rt->r->f[0]) % MOD +
    //                         (rt->l->f[0] * rt->r->f[1]) % MOD +
    //                         (rt->l->f[1] * rt->r->f[0]) % MOD) % MOD;
    //         }
    //     }
    //     else if (expr[i] == ')')
    //     {
    //         while (!stk.empty() && stk.top().op != '(')
    //         {
    //             Data t = newNode()
    //         }
    //         stk.pop();
    //     }
    // }
    return 0;
}