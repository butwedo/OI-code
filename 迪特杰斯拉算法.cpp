#include<iostream>
using namespace std;
int point[500002],head[500002],nxt[500002],val[500005],tot;
int len[500002];
bool  vis[500002];
const int big=2147483647;
void add(int x,int y,int v)
{
	tot++; 
	point[tot]=y;
	val[tot]=v;
	nxt[tot]=head[x];
	head[x]=tot;
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	  {
	  	int a,b,c;
	  	cin>>a>>b>>c;
	  	add(a,b,c);
	  }
	for(int i=1;i<=n;i++)
	  len[i]=big;
	len[s]=0;
	for(int i=1;i<=n;i++)
	{
		int minn=big,k=i;
		for(int j=1;j<=n;j++)
		{
			if(len[j]>=minn)continue;
			if(!vis[j])
			{
				k=j;
				minn=len[j];
			}
		    vis[k]=1;
		    for(int j=head[k];j;j=nxt[j])
		    {
		    	if(!vis[point[j]]&&len[point[j]]>len[k]+val[j])
		    	len[point[j]]=len[k]+val[j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	  cout<<len[i]<<' ';
	return 0;
}
