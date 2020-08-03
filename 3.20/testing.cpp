#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int r, c, t = 0, sx, sy, tx, ty, bx, by;
char _map[21][21];
bool book[21][21][4], book2[21][21];
int _next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string go[4] = {"N", "S", "W", "E"};
string go2[4] = {"n", "s", "w", "e"};
struct node
{
    int boxx, boxy, peox, peoy;
    string ans;
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (~scanf("%d%d", &r, &c) && r != 0 && c != 0)
    {
        memset(book, 0, sizeof(book));
        t++;
        for (int i = 1; i <= r; i++)
        {
            scanf("%s", _map[i] + 1);
            for (int j = 1; j <= c; j++)
            {
                if (_map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if (_map[i][j] == 'T')
                {
                    tx = i;
                    ty = j;
                }
                if (_map[i][j] == 'B')
                {
                    bx = i;
                    by = j;
                }
            }
        }
        printf("Maze #%d\n", t);
        bool flag = false;
        queue<node> q;
        node bnow, bnex;
        bnow.boxx = bx; // boxx
        bnow.boxy = by;
        bnow.peox = sx; // startx
        bnow.peoy = sy;
        bnow.ans = "";
        q.push(bnow);
        while (!q.empty())
        {
            bnow = q.front();
            q.pop();
            if (bnow.boxx == tx && bnow.boxy == ty) // ok
            {
                flag = 1;
                break;
            }
            for (int i = 0; i < 4; i++) // 4 direction
            {
                bnex.boxx = bnow.boxx + _next[i][0];
                bnex.boxy = bnow.boxy + _next[i][1];
                int mx = bnow.boxx - _next[i][0], my = bnow.boxy - _next[i][1];
                if (bnex.boxx > 0 && bnex.boxx <= r && bnex.boxy > 0 && bnex.boxy <= c && !book[bnex.boxx][bnex.boxy][i] && _map[bnex.boxx][bnex.boxy] != '#' && mx > 0 && mx <= r && my > 0 && my <= c && _map[mx][my] != '#')
                {
                    bool flag2 = 0;
                    queue<node> q2;
                    memset(book2, 0, sizeof(book2));
                    book2[bnow.boxx][bnow.boxy] = 1; //
                    book2[bnow.peox][bnow.peoy] = 1; //
                    // cerr << "(" << mx <<","<<my<<") <- ("<<bnow.peox<<","<<bnow.peoy<<")"<<endl;
                    node pnow, pnex;
                    pnow.peox = bnow.peox;
                    pnow.peoy = bnow.peoy;
                    pnow.ans = "";
                    q2.push(pnow);
                    while (!q2.empty())
                    {
                        pnow = q2.front();
                        // cerr << pnow.peox << " " << pnow.peoy << " " << pnow.ans << endl;
                        q2.pop();
                        if (pnow.peox == mx && pnow.peoy == my)
                        {
                            flag2 = 1;
                            break;
                        }
                        for (int i = 0; i < 4; i++)
                        {
                            pnex.peox = pnow.peox + _next[i][0];
                            pnex.peoy = pnow.peoy + _next[i][1];
                            if (pnex.peox > 0 && pnex.peox <= r && pnex.peoy > 0 && pnex.peoy <= c && !book2[pnex.peox][pnex.peoy] && _map[pnex.peox][pnex.peoy] != '#')
                            {
                                pnex.ans = pnow.ans + go2[i];
                                book2[pnex.peox][pnex.peoy] = 1;
                                q2.push(pnex);
                            }
                        }
                    }
                    if (flag2)
                    {
                        bnex.peox = bnow.boxx;
                        bnex.peoy = bnow.boxy;
                        bnex.ans = bnow.ans + pnow.ans + go[i];
                        book[bnex.boxx][bnex.boxy][i] = 1;
                        q.push(bnex);
                    }
                }
            }
        }
        if(flag) cout << bnow.ans << endl << endl;
        else printf("Impossible.\n\n");
    }
}
