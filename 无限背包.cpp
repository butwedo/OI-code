#include<iostream>
#include<cstdio>
using namespace std;
int f[10000000],a[10000000],t[10000000];
int main()
  {
  	//freopen("ioio.out","w",stdout);
  	int h,m;
  	cin>>h>>m;
  	for(int i=1;i<=m;i++)
  	  cin>>t[i]>>a[i];
  	for(int i=1;i<=m;i++)
	  {
	  for(int j=t[i];j<=h;j++)
	    
     		if(f[j]<f[j-t[i]]+a[i])f[j]=f[j-t[i]]+a[i];
     		else f[j]=max(f[j-1],f[j]);
     		/*for(int k=1;k<=h;k++)
     		  cout<<f[k]<<' ';
     		cout<<endl;*/
	    }
    cout<<f[h];
	return 0;
			   
  }

