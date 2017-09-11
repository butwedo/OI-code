#include <iostream>
#include<cstring>
using namespace std;
int main()
 { string a,b;
  cin>>a;
  //getline(cin,a );
  cin>>b;
   //getline(cin,b);
   int l1=a.size(),l2=b.size(),c[20000],d[20000];
   int l=l1,r=l2,max;
   if(l>r) max=l;
   else max=r;
  for(int i=1;i<=l1;i++)
    c[i]=int(a[--l])-48;
  for(int i=1;i<=l2;i++)
    d[i]=int(b[--r])-48;
  for(int i=1;i<=max;i++)
    { c[i]+=d[i];
      if (c[i]>=10) {c[i+1]++;
                   c[i]=c[i]-10;
                  }             
    }
    max++;
  while(c[max]==0&&max>1)max--;  
  for(int i=max;i>=1;i--)
    cout<<c[i];
   
  return 0;
  
  
 } 
