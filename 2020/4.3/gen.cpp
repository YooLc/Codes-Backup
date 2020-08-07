#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int rand2(int n)
{
    return (long long)rand()*rand() % n;
}
char mapp[51][51];
bool book[100000000];
bool hhh[100000000];
int main()
{
    freopen("maze1.in","w", stdout);
    srand((unsigned)time(0));
    int r=rand2(10)+1,c=rand2(10)+1;
    cout<<r<<" "<<c<<endl;
    int qq=rand2(r)+1,qw=rand2(r)+1;
	if(qw==qq) qw++;
    int rr=rand2(c)+1,re=rand2(c)+1;
	if(re==rr) re++;
    for(int i=1;i<=r;i++)
    {
    	for(int j=1;j<=c;j++)
    	{
    		int k=rand2(100);
    		if(i==qq&&j==rr)
    		{
    			printf("S");
    			mapp[i][j]='S';
			}
    		else if(i==qw&&j==re)
    		{
    			printf("T");
    			mapp[i][j]='T';
			}
			else if(k<=20)
			{
				printf("#");
				mapp[i][j]='#';
			}
    		else
    		{
    			printf(".");
    			mapp[i][j]='.';
			}
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(mapp[i][j]=='#')
			{
				cout<<"1 1\n"<<"#\n"<<endl;
				continue; 
			}
			else
			{
				int n=rand2(5)+2,m=rand2(5)+2;
				if(n==1&&m==1) m++;
				cout<<n<<" "<<m<<endl;
				qq=rand2(n)+1,qw=rand2(n)+1;
				while(qw==qq) qq=rand2(n)+1,srand((unsigned)19260817+qq);
			    rr=rand2(m) + 1,re=rand2(m) + 1;
				while(re == rr) rr=rand2(m) + 1,srand((unsigned)19260817+rr);
				for(int i1=1;i1<=n;i1++)
				{
					for(int j1=1;j1<=m;j1++)
					{
						srand((unsigned)time(0) + j1 * i1 + 1926);
						int k=rand2(100);
			    		if(i1==qq&&j1==rr)
			    		{
			    			printf("S");
						}
			    		else if(i1==qw&&j1==re)
			    		{
			    			printf("T");
						}
						else if(k<=20)
						{
							printf("#");
						}
			    		else
			    		{
			    			printf(".");
						}
					}
					cout<<endl;
				} 
			}
			cout<<endl;
		}
	}
	int k=rand2(3);
	printf("%d\n",k);
	for(int i=1;i<=k;i++)
	{
		int x=rand2(r+c);
		while(book[x]) x=rand2(r+c);
		
			book[x]=1;
			int y=rand2(r),z=rand2(c);
			while(book[y*100+z])
			{
				y=rand2(r),z=rand2(c);
			 } 
			book[y*100+z]=1;
		cout<<x<<" "<<y<<" "<<z<<endl;
	}
}
