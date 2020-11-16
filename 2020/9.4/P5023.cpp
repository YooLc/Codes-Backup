#include <iostream>
#include <cstdio>
const int MOD = 1e9 + 7;
int n, m;
int d[8][9] = {{2, 4, 8, 16, 32, 64, 128, 256},
            {4, 12, 36, 108, 324, 972, 2916, 8748},
            {8, 36, 112, 336, 1008, 3024, 9072, 27216},
            {16, 108, 336, 912, 2688, 8064, 24192, 72576},
            {32, 324, 1008, 2688, 7136, 21312, 63936, 191808},
            {64, 972, 3024, 8064, 21312, 56768, 170112, 510336},
            {128, 2916, 9072, 24192, 63936, 170112, 453504, 1360128},
            {256, 8748, 27216, 72576, 191808, 510336, 1360128, 3626752, 10879488}};
inline long long qpow(int a,int x)
{
	long long base = a, res = 1;
	while (x)
	{
		if(x & 1) res = res * base % MOD;
		base = base * base % MOD;
		x >>= 1;
	}
	return res;
}
int main() 
{
    /*
        Reference: https://www.luogu.com.cn/blog/1445353309froggy/solution-p5023
        1.  容易看出这个举行表格，每条对角线单调不增加
        2.  不容易看出，若一个子矩阵左上角向上和向右相邻的两个格子填涂相同，则子矩阵每条对角线都必填涂相同
            因为可以拐弯，比如：
            1 2 3
            4 5 6
            7 8 9
            选择 1 -> 2 -> 5 -> 8 -> 9 和 1 -> 4 -> 5 -> 6 -> 9，此时如果 6 和 8 填涂不同，会不满足题意
        可以证明 1 && 2 条件与题意互为充要条件
        如果只有第一个限制，可以用状压 dp 推，然而第二个限制就只能用大法师 dfs 了
        打表之后找规律.... 当 m > n + 1 时，F(n, m) = 3 * F(n, m - 1)
        同时 n, m 可以调换
    */
    scanf("%d %d", &n, &m);
    if (n > m) std::swap(n, m);
    if (n <= 8 && m <= 8) printf("%d", d[n - 1][m - 1]);
    else if (n == 0) printf("%d", qpow(2, m));
    else printf("%d", (1LL * d[n - 1][n] * qpow(3, m - n - 1)) % MOD); // d[][] 向右上平移了一位要注意
    return 0;
}