#pragma GCC optimize("Ofast")
#include <cstdio>
#include<ctime>
#include <cstring>
#include <algorithm>
const static int MAXN = 105, HASH = 2.1e5 + 5, MOD = 20110520; // HASH should be enough
bool mapp[MAXN][MAXN];
char str[MAXN];
int bitsToMove[20], ans, r, c, maxx = 0;
inline void swap(int &a, int &b) { int t = b; b = a; a = t; }
struct hashTable
{
    // Thanks to OIH for his hash Table
    // size : size of this hashTable
    // curKey -> states -> state
    // curKey -> nxt -> Next key with the same hash value
    // curKey -> val -> value
    // state -> key -> curKey
    int nxt[HASH], val[HASH], key[HASH], states[HASH], size;
    inline void clear()
    {
        memset(key, 0, sizeof(key));
        size = 0;
    }
    inline int &operator[](int state)
    {
    	int hashed = state % HASH;
        int curKey = key[hashed];
        while(curKey && states[curKey] != state)
            curKey = nxt[curKey]; // Do not crash
        if(!curKey) // Assign a new space
        {
            nxt[++size] = key[hashed];
            states[key[hashed] = curKey = size] = state;
            val[size] = 0;
        }
        return val[curKey] %= MOD;
    }
} dp[2];
inline void add(int p, int state, int val) {
    maxx = std::max(maxx, state);
    dp[p][state] += val;
}
inline int calcState(int pre, int nr, int nd, int block)
{
    pre -= pre & (15 << bitsToMove[block - 1]);
    pre = pre | (nr << bitsToMove[block]) | (nd << bitsToMove[block - 1]);
    return pre;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("floor9.in", "r", stdin);
        freopen("1.txt", "w", stdout);
    #endif
    int cur = 0;
    scanf("%d %d", &r, &c);
    if(r >= c)
    {
        for (int i = 1; i <= r; ++i)
        {
            scanf("%s", str + 1);
            for (int j = 1; j <= c; ++j)
                mapp[i][j] = bool(str[j] == '_');
        }
    }
    else
    {
        for (int i = 1; i <= r; ++i)
        {
            scanf("%s", str + 1);
            for (int j = 1; j <= c; ++j)
                mapp[j][i] = bool(str[j] == '_');
        }
        swap(r, c);
    }
    for (int i = 1; i <= 15; ++i)
            bitsToMove[i] = i << 1;
    dp[cur][0] = 1;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cur ^= 1;
            dp[cur].clear();
            for (int k = 1; k <= dp[cur ^ 1].size; ++k)
            {
            	int preState = dp[cur ^ 1].states[k];
                int right = preState >> bitsToMove[j - 1] & 3,
                    down = preState >> bitsToMove[j] & 3,
                    val = dp[cur ^ 1].val[k]; //  >> (int(j == 1) << 1)];
                if(mapp[i][j])
                {
					if(right && down && right + down > 2) continue;
                    if(!right && !down)
                    {
                        if(mapp[i + 1][j] && mapp[i][j + 1])
                            add(cur, calcState(preState, 2, 2, j), val);
                        if(mapp[i + 1][j])
                            add(cur, calcState(preState, 0, 1, j), val);
                        if(mapp[i][j + 1])
                            add(cur, calcState(preState, 1, 0, j), val);
                    }
                    else if(!right && down == 1)
                    {
                        if(mapp[i][j + 1])
                            add(cur, calcState(preState, 2, 0, j), val);
                        if(mapp[i + 1][j])
                            add(cur, calcState(preState, 0, 1, j), val);
                    }
                    else if(!right && down == 2)
                    {
                        if(mapp[i + 1][j])
                            add(cur, calcState(preState, 0, 2, j), val);
                        add(cur, calcState(preState, 0, 0, j), val);
                    }
                    else if(right == 1 && !down)
                    {
                        if(mapp[i][j + 1])
                            add(cur, calcState(preState, 1, 0, j), val);
                        if(mapp[i + 1][j])
                            add(cur, calcState(preState, 0, 2, j), val);
                    }
                    else if(right == 2 && !down)
                    {
                        if(mapp[i][j + 1])
                            add(cur, calcState(preState, 2, 0, j), val);
                        add(cur, calcState(preState, 0, 0, j), val);
                    }
                    else if(right == 1 && down == 1)
                    {
                        add(cur, calcState(preState, 0, 0, j), val);
                    }
                }
                else if(!right && !down)
                {
                    add(cur, preState, val);
                }
            }
        }
        for(int j = 1; j <= dp[cur].size; ++j) dp[cur].states[j] <<= 2;
    }
    printf("%d\n%d", dp[cur][0], maxx);
    return 0;
}
