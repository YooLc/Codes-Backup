#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000010
int dfn[N],low[N],col[N],cnt,num;
bool cut[N];//记录割点 
int tot,hd[N];
int n,m,ans;
struct node{
	int nxt,to;
}e[N<<1];
void add(int u,int v){
	e[++tot].to=v;e[tot].nxt=hd[u];hd[u]=tot;
}
void tarjan(int x,int f){
	int num=0;
	dfn[x]=low[x]=++cnt;
	for(int i=hd[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!dfn[y]){
			tarjan(y,f);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=f)cut[x]=1;
            //非根节点是割点，且子节点中没有返祖边；
            if(x==f)num++;//子树个数 
		}
		low[x]=min(low[x],dfn[y]); 
	}
	if(x==f&&num>=2)cut[x]=1;//根节点是割点，且子节点数大于等于2；
}
int main(){
	freopen("input.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i,i);
	ans=0;
	for(int i=1;i<=n;i++) if(cut[i]) ans++;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) if(cut[i]) printf("%d ",i);
	return 0;
}