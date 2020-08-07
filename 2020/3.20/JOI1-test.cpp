#include <iostream>
#include <cstdio>
using namespace std;
const static int MAXN = 2e3 + 50;
int A[MAXN << 1], B[MAXN << 1], n, m;
string dp[2][MAXN][MAXN];
bool flag = false;
inline int rd()
{
    int t = 0, f = 1; char ch = getchar();
    while(!(ch >= '0' && ch <= '9')) { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { t = t * 10 + ch - '0'; ch = getchar(); }
    return t * f;
}
int main()
{
    freopen("JOI1.in", "r", stdin);
    freopen("JOI1.out", "w", stdout);
    n = rd(); m = n << 1;
    for(int i = 1; i <= m; ++i) A[i] = rd();
    for(int i = 1; i <= m; ++i) B[i] = rd();
    dp[0][1][0] = "A";
    dp[1][0][1] = "B";
    // dp[s][i][j] Current State, A count is i, B count is j
    // 0 for A, 1 for B
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            // Append A
            if(max(A[i + j - 1], B[i + j - 1]) <= A[i + j])
            {
                if(B[i + j - 1] < A[i + j - 1] && i) dp[0][i][j] = dp[1][i - 1][j] + "A";
                else if(j) dp[0][i][j] = dp[0][i][j - 1] + "A";
            }
            else if(A[i + j - 1] <= A[i + j] && j) dp[0][i][j] = dp[0][i][j - 1] + "A";
            else if(B[i + j - 1] <= A[i + j] && i) dp[0][i][j] = dp[1][i - 1][j] + "A";
            // Append B
            if(max(A[i + j - 1], B[i + j - 1]) <= B[i + j])
            {
                if(B[i + j - 1] < A[i + j - 1] && i) dp[1][i][j] = dp[1][i - 1][j] + "B";
                else if(j) dp[1][i][j] = dp[0][i][j - 1] + "B";
            }
            else if(A[i + j - 1] <= B[i + j] && j) dp[1][i][j] = dp[0][i][j - 1] + "B";
            else if(B[i + j - 1] <= B[i + j] && i) dp[1][i][j] = dp[1][i - 1][j] + "B";
        }
    }
    cout << "A" << endl;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
            cout << "A count: " << i << " B count: " << j << " " << dp[0][i][j] << endl;
        cout << endl;
    }
    cout << "B" << endl;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
            cout << "A count: " << i << " B count: " << j << " " << dp[1][i][j] << endl;
        cout << endl;
    }
    if(dp[0][n][n] == "")
    {
        if(dp[1][n][n] == "") cout << -1;
        else cout << dp[1][n][n];
    }
    else cout << dp[0][n][n];
    return 0;
}