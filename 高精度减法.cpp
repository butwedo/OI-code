#include <iostream>
#include<cstring>
using namespace std;
string a,b;
bool cc()
{
	if(a.length()<b.length())
	{
		string s=a;
		a=b;
		b=s;
		return true;
	}
	else if(a.length()==b.length()&&a<b)
	{
		string s=a;
		a=b;
		b=s;
		return true;
	}  
	return false;  		   
}
using namespace std;
int main()
{ 
	cin>>a;
	cin>>b;
	bool pd=cc();
	int l1=a.size(),l2=b.size(),c[200000],d[200000];
	int l=l1,r=l2;
	for(int i=1;i<=l1;i++)
		c[i]=int(a[--l])-48;
	for(int i=1;i<=l2;i++)
		d[i]=int(b[--r])-48;
	for(int i=1;i<=l1;i++)
	{ 
		c[i]-=d[i];
		if (c[i]<0)
		{
			c[i+1]--;
			c[i]=10+c[i];
		}             
	}
	l1+=100000;  
	while(c[l1]==0&&l1>1)
		l1--;
	if(pd)cout<<'-';
	for(int i=l1;i>=1;i--)
		cout<<c[i];
	return 0;
} 
