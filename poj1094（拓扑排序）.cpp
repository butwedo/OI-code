#include<iostream>
#include<cstring>
#include<queue> 
#include<cstdio>
#include<cstdlib>
using namespace std;
int vis[30];
int v[30];
int in[30];
int temp[30];
int n,m;
int p[30][30];
int ans[30];
int tot;
int top() //拓扑排序
{
    int c=0,loc,m,flag=1,i,j;  ////flag=1:有序 flag=-1:不确定
    for(i=0;i<n;i++)
        temp[i]=in[i];
    for(i=0;i<n;i++)
    {
        m=0;
        for(j=0;j<n;j++)
            if(temp[j]==0) { m++; loc=j; }  //查找入度为零的顶点个数
        if(m==0) return 0;  //有环
        if(m>1) flag=-1;  // 无序
        ans[++c]=loc;   //入度为零的点入队
        temp[loc]=-1;
        for(j=0;j<n;j++)
            if(p[loc][j]==1) temp[j]--;
    }
    return flag;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>n>>m;
	while(n)
	{
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		memset(temp,0,sizeof(temp));
		int num=0;
		int toop,sign=0; 
		for(int i=1;i<=m;i++)
		{
		//	if(i==46)system("pause");
			char A,s,B;
			cin>>A>>s>>B;
			if(sign)continue;
			int a=A-'A';
			int b=B-'A';
			in[b]++;
			p[a][b]=1;
		//	if(i<=46)continue;
			toop=top();
			if(toop==1)
			{
				printf("Sorted sequence determined after %d relations: ",i);
				for(int i=1;i<=n;i++)
				printf("%c",ans[i]+'A');
				printf(".\n");
				sign =1 ;
				memset(ans,0,sizeof(ans));
			//	break;
			}
			if(toop==0)
			{
				printf("Inconsistency found after %d relations.\n",i);
				sign=1;
				memset(ans,0,sizeof(ans));
			//	break;
			}
			
		}
		if(toop==-1) 
			{
				printf("Sorted sequence cannot be determined.\n");
				memset(ans,0,sizeof(ans));
			}
		cin>>n>>m;
	//	cout<<n<<' '<<m<<endl;
	}
	return 0;
} 
