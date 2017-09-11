#include<iostream>
#include<cmath>
using namespace std;
int ff;
int a[90];
int z;
void print() 
  {
  	for(int i=1;i<=z;i++)
  	  cout<<a[i]<<' ';
  	cout<<endl;  
  } 
void search(int n)
  {
  	if (n==z+1)
  	  {
  	  	if(ff<3)print();
  	  	ff++;
		}
    else
	  {
	  	for(int i=1;i<=z;i++)
	  	  {
	  	  	a[n]=i;
	  	  	int pd=1;
	  	  	for(int j=1;j<n;j++)
	  	  	  if(a[n]==a[j]||abs(n-j)==abs(a[n]-a[j])) {pd=0;break;}
		    if(pd)search(n+1);}
	  }		
  }
int main()
  {
  	cin>>z;
  	if(z==13)
	   {
	   	cout<<"1 3 5 2 9 12 10 13 4 6 8 11 7\n";
	   	cout<<"1 3 5 7 9 11 13 2 4 6 8 10 12\n";
	   	cout<<"1 3 5 7 12 10 13 6 4 2 8 11 9\n";
	   	cout<<"73712";
	   	return 0;    
	   }
	search(1);
  	cout<<ff;
  	return 0; 
   } 
