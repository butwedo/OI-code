#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[100000];
void cc(int x,int x1,int y)
  {
  	int ab=(y-a[x])-(a[x1]-y);
  	if(ab>0)cout<<a[x1]<<endl;
  	else cout<<a[x]<<endl;
  }
void found(int x,int l,int r)
  {
  	int mid=(l+r)/2;
  	if(a[mid]<x&&a[mid+1]<x) found(x,mid,r);
  	  else if(a[mid]<=x&&a[mid+1]>=x) 
		{
		  cc(mid,mid+1,x);
		  return;
		}
  	if(a[mid]>x&&a[mid-1]>x) found(x,l,mid);
  	  else if(a[mid]>=x&&a[mid-1]<=x) 
		     {
		      cc(mid-1,mid,x);
		      return;
			 }
  }
int main()
  { 
    //freopen("i.in","r",stdin);
  	int n;
  	cin>>n;
  	for(int i=1;i<=n;i++)
  	  cin>>a[i];
  	int m;
  	cin>>m;
  	int f;
    for(int i=1;i<=m;i++)
      {
      	cin>>f;
      	if(f>=a[n]) 
		  {
		   cout<<a[n]<<endl;
		   continue;	
		  }
      	if(f<=a[1]) 
		  {
		  	cout<<a[1]<<endl;
			continue;
		  }
      	found(f,1,n);
	  }
    return 0; 
  }

