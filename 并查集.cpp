#include<iostream>
using namespace std;
int a[100000];
int find(int x)
  {
  	if(a[x]==x)return x;
  	return find(a[x]);
  }
int main()
  {
  	int n,m;
  	cin>>n>>m;
  	for(int i=1;i<=n;i++)
  	  a[i]=i;
  	for(int i=1;i<=m;i++)
  	  {
  	     int x,y,z;
  	     cin>>x>>y>>z;
  	     if(x==1) a[y]=a[find(a[y])]=a[z]=a[find(a[z])]=find(a[max(x,y)]);
  	     if(x==2)
  	        if(find(a[y])==find(a[z])) cout<<'Y'<<endl;
  	        else cout<<'N'<<endl;
	  }
	//for(int i=1;i<=n;i++)
	//  cout<<a[i]<<' ';
	return 0;
   } 
