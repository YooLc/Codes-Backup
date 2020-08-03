#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int MAXHASH = 4e5 + 5, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int table[2][MAXHASH];
string init, goal = "123804765";
inline int cantor(string str)
{
    int ans = 0, sum = 0;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = i + 1; j <= 8; j++)
            if(str[j] < str[i]) sum++;
        ans += sum * fact[8 - i];
        sum = 0;
    }
    return ans + 1;
}
inline int bfs()
{
    queue<pair<string, int> > q[2];
    q[0].push(make_pair(init, 0));
    q[1].push(make_pair(goal, 0));
    memset(table, 0, sizeof(table));
    // table[0][cantor(init)] = 0;
    // table[1][cantor(goal)] = 0;
    while(q[0].size() && q[1].size())
    {
        int p = q[0].size() > q[1].size() ? 1 : 0;
        string cur = q[p].front().first;
        int step = q[p].front().second;
        q[p].pop();
        int pos;
        for(pos = 0; pos < 9; ++pos) if(cur[pos] == '0') break;
        pii zero = make_pair(pos / 3, pos % 3);
        for(int i = 0; i < 4; ++i)
        {
            int nx = zero.first + dx[i];
            int ny = zero.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            swap(cur[zero.first * 3 + zero.second], cur[nx * 3 + ny]);
            int key = cantor(cur);
            if(!table[p][key])
            {
                if(table[p ^ 1][key] > 0)
                    return step + table[p ^ 1][key] + 1;
                else table[p][key] = step + 1, q[p].push(make_pair(cur, step + 1));
            }
            swap(cur[zero.first * 3 + zero.second], cur[nx * 3 + ny]);
        }
    }
    return 0;
}
int main()
{
    cin >> init;
    if(init == goal) puts("0");
    else cout << bfs();
    return 0;
}