#include<iostream>
using namespace std;
int p[10000073],m[10000007],num;
int main()
{
	int t,n;
	cin>>n>>t;
	m[1]=1; 
	for(int i=2;i<=n;i++)
	{
		if(!m[i])
		{
			p[num++]=i;
		}
		for(int j=0,k;j<num&&(k=i*p[j])<=n;j++)
		{
			m[k]=p[j];
			if(m[i]==p[j])break;
		}
	}
	for(int i=1;i<=t;i++)
	{
		int a;
		cin>>a;
		if(m[a])cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}

