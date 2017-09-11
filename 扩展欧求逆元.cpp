#include<iostream>
using namespace std;
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
		int p=exgcd(b,a%b,x,y);
		int x1=x;
		x=y;
		y=x1-(a/b)*y;
		return p;
	}
}
int cal(int a,int m)
{
	int x,y;
	int gcd=exgcd(a,m,x,y);
	if(1%gcd!=0)return -1;
	if(m<0)m=-m;
	int ans=x%m;
	if(ans<=0)ans+=m;
	return ans;
 } 
int main()
{
	int a,b;
	while(1)
	{
		cin>>a>>b;
		int x,y;
		int c=cal(a,b);
		if(c==-1)
		{
			cout<<"no inv\n";
			continue;
		}
		else cout<<c<<endl;
	}
	return 0;
 } 
