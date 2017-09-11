#include<iostream> 
#include<cstdio> 
using namespace std;
int a[10000000];
void ss(int l,int r)
{
    int m=a[(l+r)/2];
	int i=l,j=r;
	while(i<=j)
	{
	

	while(a[i]<m)i++;
	while(a[j]>m)j--;   
	if(i<=j) 
	{
		int t=a[i];
		a[i]=a[j];
		a[j]=t;
		j--;i++;
	}
	if(j>l)ss(l,j);if(i<r)ss(i,r);
}
	
  }
int main()
  {
  	
  	int n;
  	scanf("%d",&n);
	  //cin>>n;
  	for(int i=1;i<=n;i++)
  	  scanf("%d",&a[i]);
		//cin>>a[i];
  	ss(1,n);
  
  	for(int i=1;i<=n;i++)
  	  printf("%d ",a[i]);
		//cout<<a[i]<<' ';
  	return 0;
   } 
