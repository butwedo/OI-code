#include<stack>
#include<iostream>
#include<cstring>
//tarjan缩点
//过是过了，是不是正经缩点我就不知道了:P 
using namespace std;
int sch[1005][1005];
int dfn[1005],low[1005];
int n,sum;
int vis[1005];
int v[105];
int p[105];
int in[1005],out[1005];
int lin[1005],lout[1005];
stack<int> s;
void tarjan(int x)
{
	s.push(x);
	low[x]=dfn[x]=++sum;
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!sch[x][i])continue;
		if(!vis[i])
		{
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else if(vis[i]) low[x]=min(low[x],dfn[i]);
	}
	if(dfn[x]==low[x])
	{
		int num=0;
		while(!s.empty())
		{
			int t=s.top();
			s.pop();
	//	    cout<<t<<' ';
			vis[t]=0;
			v[t]=1;
			if(x!=t)in[t]=out[t]=-1;
			p[++num]=t;
			if(t==x)break;
		}
		int inn=0,outt=0;
		for(int i=1;i<=num;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(sch[p[i]][j]&&v[j]==0&&lout[j]==0)
				{
					//in[j]--;
					outt++;
					lout[j]=1;
				}
				if(sch[j][p[i]]&&v[j]==0&&lin[j]==0)
				{
					inn++;
				//	out[j]--;
					lin[j]=1;
				}
			}
		}
		in[x]=inn;
		out[x]=outt;
	//	cout<<endl;
		memset(lin,0,sizeof(lin));
		memset(lout,0,sizeof(lout));
		memset(v,0,sizeof(v));
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a=1;
		for(;;)
		{
			cin>>a;
			if(a==0)break;
			in[a]++;
			out[i]++;
			sch[i][a]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		if(!dfn[i])tarjan(i);
	}
	int ans=0;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)ans++;
		if(out[i]==0)sum++;
	}
	int ans2=max(sum,ans);
	//if(ans==1&&sum==1)ans2=0;
	int root = 0;
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==low[i])root++;
	}
	if(root==1)ans2=0;
	cout<<ans<<endl<<ans2;
	return 0;
}
