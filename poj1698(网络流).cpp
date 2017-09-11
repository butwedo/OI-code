#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int big=400;
int can[big+10][10];
const int maxint=100000000;
int flow[big+10][big+10];
int dis[big+10];
int bfs()
{
	int k;
	queue<int> q;
	memset(dis,-1,sizeof(dis));
	dis[big]=0;

	q.push(big);
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		for(int i=0; i<=big; i++)
		{
			if(dis[i]==-1 && flow[i][k])
			{
				dis[i]=dis[k]+1;
				q.push(i);
			}
		}
		if(k==0) return 1;
	}
	return 0;
}

int dfs(int cur,int cp)
{
	if(cur==big)	return cp;

	int tmp=cp,t;
	for(int i=0; i<=big && tmp; i++)
	{
		if(dis[i]+1==dis[cur] && flow[cur][i])
		{
			t=dfs(i,min(flow[cur][i],tmp));
			flow[cur][i]-=t;
			flow[i][cur]+=t;
			tmp-=t;
		}
	}
	return cp-tmp;
}
void build(int n)
{
	int i,j,k;
	for(i=1; i<=n; i++)
	{
		flow[0][i+350]=can[i][8];

		for(j=1; j<=7; j++)
		{
			if(can[i][j])
			{
				for(k=0; k<can[i][9]; k++)
					flow[i+350][j+k*7]=1;
			}
		}
	}

	for(i=1; i<=350; i++)	flow[i][big]=1;
}

void solve()
{
	int n;
	cin>>n;
	int day=0;
//	memset(can,0,sizeof(can));
	memset(flow,0,sizeof(flow));
	for(int i=1; i<=n; i++)
	{
		for(int j=1;j<=9; j++)
		{
			cin>>can[i][j];
		}
		day+=can[i][8];
	}
	build(n);
	int days=0;
	while(bfs())
	{
		days+=dfs(0,maxint);
	//	cout<<days<<endl;
	}
	if(days==day)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main()
{
///	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
		solve();
	return 0;
}
