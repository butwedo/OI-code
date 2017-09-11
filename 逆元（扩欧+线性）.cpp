#include<iostream>//Çó1~nµÄÄæÔª 
using namespace std;
int n;
int inv[4000];
int m[4000],p[4000],nup;
void shai(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!m[i])
		{
			p[nup++]=i;
			m[i]=i;
		}
		for(int j=0,k;j<nup&&(k=i*p[j])<=n;j++)
		{
			m[k]=p[j];
			if(i%p[j]==0)break;
		}
	}	
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		int gcd=exgcd(b,a%b,x,y);
		int x1=x;
		x=y;
		y=x1-a/b*y;
		return gcd;
	}
}
int cal(int a,int b)
{
	int x,y;
	int gcd=exgcd(a,b,x,y);
	if(gcd!=1)return -1;
	if(b<0)b=-b;
	int ans=x%b;
	if(ans<0)ans+=b;
	return ans;	
}
int main()
{
	cin>>n;
	shai(n);
	int p;
	cin>>p; 
	inv[1]=1;
	for(int i=2;i<p;i++)
	{
		inv[i]=inv[p%i]*(-p/i);
		while(inv[i]<0)inv[i]+=p;
	}
	for(int i=p+1;i<=n;i++)
	{
		if(i%p==0)
		{
			inv[i]=0;
			continue;
		}
		if(m[i]!=i)
		inv[i]=inv[m[i]]*inv[i/m[i]];
		else inv[i]=cal(i,p);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<' '<<inv[i]<<endl; 
	}
	return 0;
} 
