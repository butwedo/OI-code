#include<iostream>
#include<algorithm>
using namespace std;
void exgcd(int a,int b,int &d,int &x,int &y)
{
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
		cout<<x<<' '<<a<<' '<<y<<' '<<b<<endl; 
	}
}
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,d;
	if(a<b)swap(a,b);
	d=gcd(a,b);
	cin>>a>>b;
	int x,y;
	exgcd(a,b,d,x,y);
	cout<<x<<' '<<y;
	return 0;
} 
