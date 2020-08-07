//https://blog.csdn.net/dxx_111/article/details/51103263�ķ��� 
#include<iostream>
#include<cstring>
const int maxn=1e4+5,maxm=1e2+5;
int dp[maxn],wi[maxm],val[maxm],n,v,sum;
int main()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++)scanf("%d",&wi[i]);
	for(int i=1;i<=n;i++)val[i]=wi[i],sum+=val[i];
	for(int i=1;i<=n;i++)
		for(int j=sum;j>=val[i];j--)
			dp[j]=std::min(dp[j],dp[j-val[i]]+wi[i]);
	for(int i=sum;i>=0;i--)
		if(dp[i]<=v)
			{printf("%d",i);return 0;}
}
