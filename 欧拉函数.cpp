#include<iostream>
using namespace std;
int p[30000000];//存储素数 
int m[30000000];//m[i]表示 i的最小质因子 
int phi[30000000];//存储欧拉函数 
int n=3000;
int num; 
int main()
{
	phi[1]=1;
	cin>>n;
	for(int i=2;i<n;i++)
	{
		if(!m[i])
		{
			phi[i]=i-1;//素数的欧拉函数为p-1 
			p[num++]=i;
		}
		for(int j=0,k;j<num&&(k=i*p[j])<=n;j++)
		{
			m[k]=p[j];
			if(m[i]==p[j])
			{
				phi[k]=phi[i]*p[j];//若k|p 则k=phi[k/p]*p 证明见下 
				break;
			}
			else phi[k]=phi[i]*(p[j]-1);//数论奇性函数性质：若i与p互质 phi[i*p]=phi[i]*phi[p]
		}
	}
	int e;
	cin>>e;
	for(int i=1;i<=e;i++)
	{
		int a;
		cin>>a;
		if(m[a])cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
//	for(int i=1;i<=n;i++)
//	cout<<phi[i]<<' '<<p[i]<<endl;
	return 0;
} 

/*phi[k]=phi[i]*p[j];//若k|p 则k=phi[k/p]*p 证明:
首先证明:
若p是素数 则有  phi[P^k]=p^k-p^(k-1)=(p-1)*p^(k-1)---------
1~p^k-1共有p^k-1个，其中（1*p,2*p,3*p,4*p....)共p^(k-1)-1个数不与p互质。
则 phi[p^(k-1)]=(p-1)*p^(k-2);phi[p^k]=phi[p^(k-1)]*p



令 phi[k]=phi[i]*p[j]中k=p1^a1*p2^a2.......*pn^an
则p=p1,i=p1^(a1-1)*p2^a2.......*pn^an
由上面可知phi[p1^a1]=phi[p1^(a1-1)]*p1
又易得：p1^a1与p2^a2*p3^a3......*pn^an互质
所以phi[k]=phi[p1^a1]*phi[p2^a2*p3^a3......*pn^an]=p1*phi[p1^(a1-1)]*phi[p2^a2*p3^a3......*pn^an]
												  =p1*phi[p1^(a1-1)*p2^a2*p3^a3......*pn^an]=p1*phi[i]*/
