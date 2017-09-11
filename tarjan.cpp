#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int point[4000],had[4000],nxt[4000];
int tot,sum;
int dns[4000],low[4000];
bool vis[4000];
stack<int>s;
void add(int a,int b)
{
	tot++;
	point[tot]=b;
	nxt[tot]=had[a];
	had[a]=tot;
} 
void tarjine(int x)
{
	s.push(x);
	vis[x]=1;
	dns[x]=low[x]=++sum;
 	for(int i=had[x];i;i=nxt[i])
 	{
		int to=point[i];
		if(!dns[to])
		{
			tarjine(to);
			low[x]=min(low[x],low[to]);
		}
		else
		{
			if(vis[to])low[x]=min(low[x],dns[to]);
		}
	}
		if(dns[x]==low[x])
		{
			while(!s.empty())
			{
				int y=s.top();
				cout<<y<<' ';
				vis[y]=0;
				s.pop();
				if(y==x)break; 
			}
			cout<<endl;
		}
	
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);	
	}	
	for(int i=1;i<=n;i++)
	{
		sum=0;
		if(!dns[i])tarjine(i);
	 } 
	return 0;
} 
