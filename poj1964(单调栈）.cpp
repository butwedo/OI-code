#include<iostream>
#include<cstdio>
using namespace std;
int high[1001][1001];
bool pd[1001][1001];
struct dou{
	long long h;
	long long w;
}stk[100001];
long long ans;
void stacka(int k,int n)
{
	int had=1;
		int a;
		for(int i=1;i<=n;i++)
		{
			a=high[k][i];
			long long tmp=0;
			while(a<=stk[had-1].h&&had>1)
			{
				ans=max(ans,stk[had-1].h*(stk[had-1].w+tmp));
				tmp+=stk[had-1].w;
				had--;
			}
			stk[had].h=a;
			stk[had++].w=1+tmp;
		}
		int tmp=0;
		while(had>1)
		{
			ans=max(ans,stk[had-1].h*(tmp+stk[had-1].w));
			tmp+=stk[had-1].w;
			had--;
		}
}
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			pd[i][j]=0;
			high[i][j]=0;
			char c='p';
			while(c!='R'&&c!='F')scanf("%c",&c);
			if(c=='F')
			{
				pd[i][j]=1;
				high[i][j]=1;
			}
		}
	}
	stacka(1,m);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(pd[i][j])high[i][j]+=high[i-1][j];
		}
		stacka(i,m);
	}
	printf("%lld\n",ans*3);
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",high[i][j]);
		cout<<endl;
	}*/
	ans=0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	  solve();
	return 0;
} 
