#include<iostream>//poj 1804 
#include<cstring>
#include<cstdio>
using namespace std;
int te[2000002];
int n,T;
int a[2000];
inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int k)
{
	while(k<=2000000)
	{
		te[k]++;
		k+=lowbit(k);
	}
}
inline int ask(int k)
{
	int ans=0;
	while(k)
	{
		ans+=te[k];
		k-=lowbit(k);
	}
	return ans;
 } 
int main()
{
	scanf("%d",&T);
	for(int K=1;K<=T;K++)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(te,0,sizeof(te));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]+=1000000;
		}
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			ans+=ask(a[i]-1);
			add(a[i]);
		}
		printf("Scenario #%d:\n%d\n\n",K,ans);
	}
	return 0;
 } 
