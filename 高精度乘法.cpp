#include<iostream>
#include<cstring>
using namespace std;
int c[10000000];
char a[1000000],b[100000];
int main()
  {
  	const int jw=10;
  	cin>>a>>b;
  	int la=strlen(a)-1;
  	int lb=strlen(b)-1;
  	int k;
  	for(int i=lb;i>=0;i--)
  	{ k=lb-i+1;;
  	  for(int j=la;j>=0;j--)
  	    {
  	      int x=a[j]-'0';
  	      int y=b[i]-'0';
  	      c[k]=c[k]+x*y;
  	      if(c[k]>=jw)
  	        {
    		  c[k+1]=c[k+1]+c[k]/jw;
    		  c[k]=c[k]%jw;
	        }
	      k++;  
	    }}
	while(!c[k]&&k>1)k--;    
	for(int i=k;i>=1;i--)
	  cout<<c[i];
	return 0;      
  }
