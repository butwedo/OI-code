#include<iostream>//��������1~p-1�Ĺ���p����Ԫ 
using namespace std;
int n;
int inv[4000];
int main()
{
	cin>>n;
	int p;
	p=n;
	inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=inv[p%i]*(-p/i);
		while(inv[i]<0)inv[i]+=p;
	}
	for(int i=1;i<=n;i++)
		cout<<i<<' '<<inv[i]<<endl;
	return 0;
} 
