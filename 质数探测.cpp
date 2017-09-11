#include<iostream>
using namespace std;
#define in long long

in pri[]={2,3,5,7,13,17,19,23,29,31};
in cas=10;
in mul(in a,in b,in c)
{
	a%=c;
	b%=c;
	in ans=0;
	while(b)
	{
		if(b&1)ans=(ans+a)%c;
		a=(a+a)%c;
		b>>=1;
	}
	return ans;
}
in doul(in a,in b,in c)
{
	a%=c;
	in ans=1;
	while(b)
	{
		if(b&1)ans=mul(ans,a,c);
		a=mul(a,a,c);
		b>>=1;
	}
	return ans;
}
bool millerr(in a)
{
	for(in i=0;i<cas;i++)
	{
		if(pri[i]==a)return true;
		in b=a-1;
		while(~b&1)b>>=1;
		in rr=doul(pri[i],b,a);
		in kk;
		if(rr==1)continue;
		if(b==a-1)return false;
		for(;;)
		{
			kk=rr;
			rr=doul(rr,rr,a);
			if(rr==a-1)break;
			if(rr==1)
			{
				if(kk!=a-1)return false;
				break;
			}
			b<<=1;
			if(b==a-1)return false;
		}
	}
	return true;
}
int main()
{
	in n;
	cin>>n;
	while(n)
	{
		if(millerr(n))cout<<"true"<<endl;
		else cout<<"false"<<endl;
		cin>>n;
	}
 } 
