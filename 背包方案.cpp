#include<iostream>
using namespace std;
int a[100000],f[1000000];
int main()
  {
  	int n,m;
  	cin>>m>>n;
  	for(int i=1;i<=m;i++)
  	  cin>>a[i];
  	  f[0]=1;
    for(int i=1;i<=m;i++)
	  for(int j=n;j>=a[i];j--)
		f[j]=f[j]+f[j-a[i]];
    cout<<f[n];
	return 0;		   
  }
