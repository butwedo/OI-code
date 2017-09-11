#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[4000];
int point[4000],had[4000],nxt[4000],tot;
int n;
int deep[4000];
int p[4000][4000];
bool vis[4000];
void add(int a,int b)
{
	tot++;
	point[tot]=b;
	nxt[tot]=had[a];
	had[a]=tot;
}
void dfs(int f)
{
	for(int i=had[f];i;i=nxt[i])
	{
		int to=point[i];
		if(vis[to])continue;
		if(!deep[to])
		{
			deep[to]=deep[f]+1;
			p[to][0]=f;
			vis[to]=1;
			dfs(to);
		}
	}
}
void find_anc()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(p[i][j-1]!=-1)
				p[i][j]=p[p[i][j-1]][j-1];
		 } 
	}
}
int lca(int a,int b)
{
	if(deep[a]<deep[b])swap(a,b);
	int i;
	for(i=0;(1<<i)<=deep[a];i++);
	i--;
	for(int j=i;j>=0;j--)
	{
		if(deep[a]-(1<<j)>=deep[b])
		a=p[a][j];
	}
	if(a==b)return b;
	for(int j=i;j>=0;j--)
	{
		if(p[a][j]!=-1&&p[a][j]!=p[b][j])
		{
			a=p[a][j];
			b=p[b][j];
		}
	}
	return p[a][0];
}
void build()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	build();
	memset(p,-1,sizeof(p));
	vis[1]=1;
	dfs(1);
	find_anc();
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
/*25
1 2
1 3
1 4
1 5
1 6
2 7
3 12
3 13
4 15
4 18
6 23
7 8
8 9
8 10
8 11
13 14
15 16
15 17
18 19
18 20
18 21
21 22
23 24
23 25
5
16 22
24 9
14 18
9 2
19 16*/

/*
4
1
1
2
4*/ 
