#include <iostream>
#include <ctime>
#pragma GCC optimize(2)
using namespace std;
const int MAXN = 1e5 + 5, MAXP = 1e3 + 50, e4 = 1e4, e3 = 1e3, e2 = 1e2;
bool notPrime[MAXN], solved = false;
int sum[MAXN], prime[MAXP], cnt, targetSum, leftTop;
string col, row[6];
    clock_t startTime, endTime;
// sum[i] 表示小于等于 i 的符合条件的质数个数
inline int calcSum(int t)
{
    string str = to_string(t);
    int sum = 0;
    for (unsigned int i = 0; i < str.size(); ++i) sum += str[i] - '0';
    return sum;
}
inline void init()
{
    notPrime[0] = notPrime[1] = true;
	for(int i = 2; i < MAXN; i++)
    {
        if(notPrime[i]) { sum[i] = cnt; continue; }
		for(int j = i * 2; j < MAXN; j += i)
			notPrime[j] = true;
        if (i >= 1e4 && i <= 1e5 && calcSum(i) == targetSum) 
            prime[(sum[i] = ++cnt)] = i;
    }
} 
inline bool hasPrime(int l, int r) { return (sum[r] - sum[l - 1]) > 0; }
/*
11351
14033
30323
53201
13313
*/
void dfs(int curRow)
{
    if (curRow == 6) 
    { 
        for (int i = 1; i <= 5; ++i)
            cout << row[i] << endl;
        cout << endl; 
        return; 
    }
    int firstNum = col[curRow - 1] - '0';
    for (int k = sum[firstNum * e4] + 1; k < sum[(firstNum + 1) * e4]; ++k)
    {
        row[curRow] = to_string(prime[k]);
        bool flag = true;
        for (int j = 2; j <= 5; ++j)
        {
            int curNum = 0, nxtNum;
            for (int i = 1; i <= curRow; ++i) curNum = curNum * 10 + row[i][j - 1] - '0';
            nxtNum = curNum + 1;
            for (int i = curRow + 1; i <= 5; ++i) curNum *= 10, nxtNum *= 10;
            cout << "CurNum: " << curNum << " " << nxtNum << " " << sum[curNum] << " " << sum[nxtNum] << endl;
            if (!hasPrime(curNum, nxtNum) || (curRow == 5 && hasPrime(curNum, curNum))) { flag = false; break; }
        }
        cout << endl;
        if (flag) dfs(curRow + 1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1-3-L3.in", "r", stdin);
    freopen("1-3-L3.out", "w", stdout);
#endif
    scanf("%d %d", &targetSum, &leftTop);
    init();
    for (int i = 1; i <= cnt; ++i) cout << prime[i] << endl;
    startTime = clock();//计时开始
    
    
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    if (!hasPrime(leftTop * e4, (leftTop + 1) * e4)) { printf("NONE"); return 0; }
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    for (int i = sum[leftTop * e4 + 1111] + 1; i < sum[(leftTop + 1) * e4]; ++i)
    {
        row[1] = to_string(prime[i]);
        for (int j = sum[leftTop * e4 + 1111] + 1; j < sum[(leftTop + 1) * e4]; ++j)
            col = to_string(prime[j]), dfs(2);
    }
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}