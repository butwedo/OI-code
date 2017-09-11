//算法用来求方程x*a+y*b=gcd(a,b)的一组解 
//另：当a,b互质时，x是a%b的逆元 
#include<iostream>
#include<algorithm>
using namespace std;
//递归过程：
//因为gcd(a,b)=gcd(b,a%b),且 a%b=a-a div b *b
//所以假设我们已经知道方程x1*b+y1*(a%b)=gcd(a,b)① 
//①式可化为x1*b+a*y1-(a div b *b)y1=gcd(a,b) 
// 上式整理可得y1*a+(x1-y1*a div b )*b=gcd(a,b)
//x=y1,y= (x1-y1*a div b )
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)//当a==0时，gcd(a,b)=b; x=0,y=1
	{		//
		x=1;
		y=0;
		return a;
	}
	else
	{
		int y1=y;
		int x1=x;
		int gcd=exgcd(b,a%b,x,y);//已经知道方程x1*b+y1*(a%b)=gcd(a,b)
		x1=x;
		x=y;//x=y1
		y=x1-(a/b)*y;//y= (x1-y1*a div b )
		return gcd;
	}
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int gcd=exgcd(a,b,x,y);
	cout<<gcd<<' '<<x<<' '<<y;
	return 0;
}
