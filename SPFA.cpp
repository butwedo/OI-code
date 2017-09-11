#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
const long long maxn = 500100;
long long tot,head[maxn],nex[maxn],point[maxn],val[maxn],d[maxn];
bool qu[500100];
void add(long long x,long long y,long long z)
{
	tot++;
	point[tot]=y;
	val[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
long long n,m;
#define big 2147483647
void spfa(long long be)
{
	d[be]=0;
	queue<long long>que;
	qu[be]=1;
    que.push(be);
    while(!que.empty())
    {
    	long long x=que.front();
    	qu[x]=0;
    	que.pop();
    	for(long long i=head[x];i;i=nex[i])
    	{
    		long long u=point[i];
    		if(d[x]+val[i]<d[u])
    		{
    			d[u]=d[x]+val[i];
    			if(!qu[u])
    			{
				    qu[u]=1;
				    que.push(u);
				}
			}
		}
	}
	for(long long i=1;i<=n;i++)
		printf("%lld ",d[i]);
}
int main()
{
	memset(qu,0,sizeof(qu));
	cin>>n>>m;
	long long be;
	cin>>be;
	for(long long i=1;i<=maxn;i++)
	  d[i]=big;
	for(long long i=1;i<=m;i++)
	{
        long long x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
	}
	spfa(be);
	return 0;
} 
