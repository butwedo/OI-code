#include<iostream>
using namespace std;
int f[500000*2+3];
int n,m;
inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int x,int k)
{
/*	while(x<=n)
	{
		f[x]+=k;
		x+=lowbit(x);
	}*/
	for(;x<=n;x+=lowbit(x))
	f[x]+=k;
}
inline void queur(int x,int y)
{
	long long ans=0;
	/*while(x>=1)
	{
		ans+=f[x];
		x-=lowbit(x);
	}*/
	for(;y;y-=lowbit(y))
	{
		ans+=f[y];
	}
//	long long an=ans;
/*	while(y>=1)
	{
		ans+=f[y];
		y-=lowbit(y);
	}*/
	for(;x;x-=lowbit(x))
	ans-=f[x];
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		add(i,a);
	 } 
	for(int i=1;i<=m;i++)
	{
		int j,a,b;
		scanf("%d%d%d",&j,&a,&b);
		if(j==1)add(a,b);
		else queur(a-1,b);
	}
	return 0;
} 
