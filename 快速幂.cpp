#include<iostream>
#include<cstdio>
using namespace std;
long long b,p,k;
long long doit(int x)
{
	if(x==1)return b%k;
	int ans=doit(x/2);
	ans=(ans%k)*(ans%k)%k;
	if(x%2)ans=ans*(b%k)%k;
	return ans; 
}
int main()
{
    cin>>b>>p>>k;
    int o=doit(p);
    //cout<<o<<endl;
    printf("%lld^%lld mod %lld=%lld",b,p,k,o);
    return 0;
 } 
