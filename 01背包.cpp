#include<iostream>
#include<cstdio>
using namespace std;
#define MN 1000000
int f[MN],w[MN],v[MN];
int main()
  {
  	freopen("cinn.in","r",stdin);
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
      {
      	int c;
      	cin>>w[i]>>c;
      	v[i]=w[i]*c;
	  }
	for(int i=1;i<=n;i++)
	  for(int j=m;j>=w[i];j--)
	    f[j]=max(f[j-w[i]]+v[i],f[j]);
	for(int i=1;i<=m;i++)
	  cout<<f[i]<<' ';
	  cout<<f[m];
	return 0;	  
  }
