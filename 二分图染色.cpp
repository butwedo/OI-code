#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int point[3000],nxt[3000],had[1000];
int vis[1000];
int tot;
void add(int a,int b)
{
	tot++;
	point[tot]=b;
	nxt[tot]=had[a];
	had[a]=tot;
}
inline bool bfs()
{
	queue<int> q;
	q.push(0);
	vis[0]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=had[x];i;i=nxt[i])
		{
			int y=point[i];
			if(vis[y]==0)
			{
				vis[y]=-vis[x];
				q.push(y);
			}
			else 
			{
				if(vis[y]!=-vis[x])return false;	
			}	
		} 
	}
	return true;
}
int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		memset(had,0,sizeof(had));
		memset(nxt,0,sizeof(nxt));
		memset(point,0,sizeof(point));
		memset(vis,0,sizeof(vis));
		tot=0;
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		if(bfs())cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	return 0;
 } 
