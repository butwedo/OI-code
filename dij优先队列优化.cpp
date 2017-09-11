#include<iostream>
#include<queue>
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
struct mine{
	int num;
	int dis;
};
priority_queue<mine> q;
bool operator < (mine a,mine b)  
{  
	if(a.dis == b.dis) 
		return a.num>b.num;  
	return a.dis>b.dis;              //ÏÈ³öÐ¡   
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
	mine p;
	p.num=s;
	p.dis=0;
	q.push(p);
	while(!q.empty())
	{
		mine t=q.top();
		q.pop();
		for(int i=head[t.num];i;i=nxt[i])
		{
			if(len[point[i]]>len[t.num]+val[i])
			{
				len[point[i]]=len[t.num]+val[i];
				mine p;
				p.num=point[i];
				p.dis=len[p.num];
				q.push(p);
			}
		}
	}
	for(int i=1;i<=n;i++)
	  cout<<len[i]<<' ';
	return 0;
}
