#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int point[1002],had[500],nxt[1003];
int tot;
int vis[500],fa[500];
int exa[500],exb[500];
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
			if(fa[y]==-1||dfs(fa[y]))
			{
				fa[y]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	int n,m,k;
	cin>>n;
	while(n)
	{
		cin>>m>>k;
		memset(had,0,sizeof(had));
		memset(nxt,0,sizeof(nxt));
		memset(point,0,sizeof(point));
		memset(fa,-1,sizeof(fa));
		memset(exa,0,sizeof(exa));
		memset(exb,0,sizeof(exb));
		tot=0;
		for(int i=1;i<=k;i++)
		{
			int j,a,b;
			cin>>j>>a>>b;
			if(a&&b)add(a,b+n);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		cout<<ans<<endl;
		cin>>n;
	}
} 
