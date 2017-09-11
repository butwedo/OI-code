#include<iostream>
#include<cstdio>
using namespace std;
int a[5000][5000];
int f[5000][5000];
int main()
{
	freopen("i.in","r",stdin);
	int n,m;
	int q,p;
	int maxn=-98;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			int f; 
			cin>>f;
			a[i][j]=f;
			if(a[i][j]>maxn) 
			{
				maxn=a[i][j];
				q=i;
				p=j;
			}
		}
	for(int i=1;i<=q;i++)
		for(int j=1;j<=p;j++)
			f[i][j]=a[i][j]+max(f[i-1][j],f[i][j-1]);
	cout<<f[q][p];
	return 0;			  
} 
