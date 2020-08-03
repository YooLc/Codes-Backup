//解题思路：先判断盒子的四周是不是有空位，如果有，则判断人是否能到达盒子的那一边，能的话，把盒子推到空位处,然后继续
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int bx,by,sx,sy,tx,ty;
int m,n,dir[][2]={-1,0,1,0,0,-1,0,1};//注意题目要求的是n、s、w、e的顺序，因为这个wa了一次
char op[]={'n','s','w','e'};
bool mark[25][25][4];//标记箱子四周的位置时候已被用过
int vis[25][25];//标记人走过的位置
char  map[25][25];
struct BB//盒子
{
    int x,y,SX,SY;//SX,SY表示当前箱子固定了，人所在的位置
    string ans;
}bnow,beed;
struct YY//人
{
    int x,y;
    string ans;
}ynow,yeed;
char up(char c)
{
    return (c-'a'+'A');
}
//aa,bb 表示当前盒子的位置；ss，ee表示起点；
bool bfs2(int s,int e,int aa,int bb,int ss,int ee)//寻找当前人，是否能够到达盒子指定的位置；
{
    queue<YY>yy;
    if(s<0 || s>m || e<0 || e>n || map[s][e] == '#') return false;
    ynow.x = ss; ynow.y = ee; ynow.ans="";
    memset(vis,0,sizeof(vis));
    vis[aa][bb] =1;//不能经过盒子
    vis[ss][ee] = 1;//起点标记为
    yy.push(ynow);
    while(!yy.empty())
    {
        ynow = yy.front();
        yy.pop();
        if(ynow.x == s && ynow.y == e)
        {
            return true;
        }
        for(int i=0;i<4;i++)
        {
            yeed.x = ynow.x+dir[i][0];
            yeed.y = ynow.y+dir[i][1];
            if(yeed.x>0 && yeed.x<=m && yeed.y>0 && yeed.y<=n && !vis[yeed.x][yeed.y] && map[yeed.x][yeed.y]!='#')
            {
                yeed.ans = ynow.ans+op[i];//记录走过的路径
                vis[yeed.x][yeed.y] = 1;
                yy.push(yeed);
            }
        }
    }
    return false;
}
bool bfs1()
{
   queue<BB>bb;
   bnow.x = bx;bnow.y=by;bnow.ans="";
   bnow.SX = sx;bnow.SY=sy;
   bb.push(bnow);
   while(!bb.empty())
     {

       bnow=bb.front();
       bb.pop();
       if(bnow.x == tx && bnow.y==ty)
       {
           return true;
       }
       for(int i=0;i<4;i++) //盒子周围的四个方向；
       {
           beed.x = bnow.x+dir[i][0];
           beed.y = bnow.y+dir[i][1];
           if(beed.x>0 && beed.x<=m && beed.y>0 && beed.y<=n && !mark[beed.x][beed.y][i] && map[beed.x][beed.y]!='#')
           {
               if(bfs2(beed.x-2*dir[i][0],beed.y-2*dir[i][1],bnow.x,bnow.y,bnow.SX,bnow.SY))//如果能推到yeed，则需要判断人是否能到达，它的上一个点；
               {
                    beed.SX = bnow.x;//推完箱子后，人的位置在箱子上
                    beed.SY = bnow.y;
                    beed.ans=bnow.ans+ynow.ans+up(op[i]);//当前的加上推箱子的加上目前挨着推的；
                    mark[beed.x][beed.y][i] = true;
                    bb.push(beed);
               }
           }
       }
     }
   return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
int T,k=1;
while(scanf("%d %d",&m,&n) && m+n)
{
    memset(mark,false,sizeof(mark));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        scanf(" %c",&map[i][j]);
        if(map[i][j] == 'S')
        {
            sx=i;sy =j;
        }
        if(map[i][j] == 'T')
        {
            tx = i;ty = j;
        }
        if(map[i][j] == 'B')
        {
            bx = i;by = j;
        }
    }
    printf("Maze #%d\n",k++);
        if(bfs1()) printf("%s\n\n",bnow.ans.c_str());//少个换行wa了一次
           else printf("Impossible.\n\n");
}
  return 0;
}