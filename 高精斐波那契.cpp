#include <iostream>
#include<cstring>
using namespace std;
int c[100000],d[100000],f[1000000];
int main()
 { 
  d[1]=1;
  f[1]=1;
  int n;
  cin>>n;
  int max=1;
  if(n<2)
    {
  	 if(n==1)cout<<'1';
  	 else cout<<'0';
  	 return 0;
    }
  for(int j=2;j<=n;j++)
  {
    for(int i=1;i<=max;i++)
      { 
	    c[i]=c[i]+d[i]+f[i];
        if (c[i]>=10)
		  {
		   c[i+1]++;
           c[i]=c[i]-10;
          }               
      }
    if(c[max+1]>0)max++;
    for(int i=1;i<=max;i++)
     {
     	d[i]=f[i];
     	f[i]=c[i];
     	if(j<n)c[i]=0;
	  } 
  }
  while(c[max]==0&&max>1)max--;  
  for(int i=max;i>=1;i--)
    cout<<c[i];
  return 0;
 } 
