#include<cstring>
#include<iostream> 
#include<cstdio>
using namespace std;
char a[1000],b[10000];
int len[1000],p[10000];
void solve()
{
	int mx=0,id=0;
	len[1]=0;
	int n=strlen(a+1);
	for(int i=2;i<=n;i++)
    {
    	if(mx<=i)len[i]=0;
    	else len[i]=min(mx-i+1,len[i-id+1]);
    	while(i+len[i]<=n&&a[i+len[i]]==a[1+len[i]])len[i]++;
    	if(len[i]+i-1>mx)
    	{
    		mx=len[i]+i-1;
    		id=i;
		}
	}	
	
	id=mx=0;
	int m=strlen(b+1);
	for(int i=1;i<=m;i++)
	{
		if(mx<=i)p[i]=0;
		else p[i]=min(mx-i+1,len[i-id+1]);
		while(i+p[i]<=m&&b[i+p[i]]==a[1+p[i]])p[i]++;
		if(i+p[i]-1>mx)
		{
			mx=i+p[i]-1;
			id=i;
		}
	}
}
int main()
{
	scanf("%s%s",a+1,b+1);
	solve();
	int n=strlen(b+1);
	for(int i=1;i<=n;i++)
	  printf("p[%d]=%d\n",i,p[i]);
}
