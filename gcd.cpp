#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	if(b>a) swap(a,b);
	int d=gcd(a,b);
	cout<<d;
 } 
