#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a[50005];
int mx[50005][21];
int mi[50005][21];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	memset(mi,0x1111,sizeof(mi));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) mx[i][0]=mi[i][0]=a[i];
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<(j-1))>n) break;
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		double l=y-x+1;
		int k=log(l)/log(2);
		printf("%d\n",max(mx[x][k],mx[y-(1<<k)+1][k])-min(mi[x][k],mi[y-(1<<k)+1][k]));
	}
	return 0;
}
