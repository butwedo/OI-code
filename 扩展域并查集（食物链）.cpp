#include<iostream>
using namespace std;
int n,k;
int fa[150004];//1~n:self   n+1~2*n:hunter   2*n+1~3*n:food
int ans;
inline int getfa(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=getfa(fa[x]);
}
inline void sam(int x,int y)
{
	int fx=getfa(x);
	int fy=getfa(y);
	fa[fx]=fy;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=3*n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		int a,x,y;
		cin>>a>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(a==1)
		{
			if(getfa(x+n)==getfa(y)||getfa(x+2*n)==getfa(y))
			{
				ans++;
				continue;
			}
			else
			{
				sam(x,y);
				sam(x+n,y+n);
				sam(x+2*n,y+2*n);
			}
		}
		if(a==2)
		{
			if(getfa(x)==getfa(y)||getfa(x+n)==getfa(y))
			{
				ans++;
				continue;
			}
			else
			{
				sam(x,y+n);
				sam(x+n,y+2*n);
				sam(x+2*n,y);
			}
		}
	}
	cout<<ans;
	return 0;
}
