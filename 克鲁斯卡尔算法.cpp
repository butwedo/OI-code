#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int fa[5002];
int tot; 
struct line{
	int be;
	int en;
	int val;
}l[2000065];
bool cmp(line a,line b)
{
	return a.val<b.val;
}
int get(int x)
{
	if(fa[x]==x)return x;
	fa[x]=get(fa[x]);
	return fa[x];
}
void add(int x,int y,int v)
{
	tot++;
	l[tot].be=x;
	l[tot].en=y;
	l[tot].val=v;
}
int main()
{
	//freopen("out.txt","r",stdin);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	sort(l+1,l+tot+1,cmp);
//	for(int i=1;i<=tot;i++)
//	cout<<l[i].val<<' ';
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		int a=get(l[i].be);
		int b=get(l[i].en);
		if(a!=b){
			ans+=l[i].val;
			if(a>b)fa[a]=b;
			else fa[b]=a;
		//	cout<<ans<<' ';
		}
		else continue;
	}
	int bj=fa[1];
	for(int i=2;i<=n;i++)
	  if(fa[i]!=bj)
	  {
	  	bj=-1;
	  	break;
	  }
	if(bj!=-1)cout<<ans;
	else cout<<"orz";
	return 0;
 } 
