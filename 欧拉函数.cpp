#include<iostream>
using namespace std;
int p[30000000];//�洢���� 
int m[30000000];//m[i]��ʾ i����С������ 
int phi[30000000];//�洢ŷ������ 
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
			phi[i]=i-1;//������ŷ������Ϊp-1 
			p[num++]=i;
		}
		for(int j=0,k;j<num&&(k=i*p[j])<=n;j++)
		{
			m[k]=p[j];
			if(m[i]==p[j])
			{
				phi[k]=phi[i]*p[j];//��k|p ��k=phi[k/p]*p ֤������ 
				break;
			}
			else phi[k]=phi[i]*(p[j]-1);//�������Ժ������ʣ���i��p���� phi[i*p]=phi[i]*phi[p]
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

/*phi[k]=phi[i]*p[j];//��k|p ��k=phi[k/p]*p ֤��:
����֤��:
��p������ ����  phi[P^k]=p^k-p^(k-1)=(p-1)*p^(k-1)---------
1~p^k-1����p^k-1�������У�1*p,2*p,3*p,4*p....)��p^(k-1)-1��������p���ʡ�
�� phi[p^(k-1)]=(p-1)*p^(k-2);phi[p^k]=phi[p^(k-1)]*p



�� phi[k]=phi[i]*p[j]��k=p1^a1*p2^a2.......*pn^an
��p=p1,i=p1^(a1-1)*p2^a2.......*pn^an
�������֪phi[p1^a1]=phi[p1^(a1-1)]*p1
���׵ã�p1^a1��p2^a2*p3^a3......*pn^an����
����phi[k]=phi[p1^a1]*phi[p2^a2*p3^a3......*pn^an]=p1*phi[p1^(a1-1)]*phi[p2^a2*p3^a3......*pn^an]
												  =p1*phi[p1^(a1-1)*p2^a2*p3^a3......*pn^an]=p1*phi[i]*/
