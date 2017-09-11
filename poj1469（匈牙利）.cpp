#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int point[60003],nxt[60003],had[3030];
int tot;
int vis[1000],fa[1000];
void add(int a,int b)
{
	tot++;
	point[tot]=b;
	nxt[tot]=had[a];
	had[a]=tot;
}
bool dfs(int x)
{
	int i,y;
	for(i=had[x];i;i=nxt[i])
		if(!vis[y=point[i]])
		{
			vis[y]=1;
			if(!fa[y]||dfs(fa[y]))
			{
				fa[y]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(point,0,sizeof(point));
		memset(fa,0,sizeof(fa));
		memset(nxt,0,sizeof(nxt));
		memset(had,0,sizeof(had));
		memset(vis,0,sizeof(vis));
		tot=0;
		int n,p;
		scanf("%d%d",&p,&n);
		for(int i=1;i<=p;i++)
		{
			int n;
			scanf("%d",&n);
			for(int j=1;j<=n;j++)
			{
				int a;
				scanf("%d",&a);
				add(i,a+p);
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		if(ans==p)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
