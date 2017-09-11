#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int point[6000],had[1000],nxt[1000],val[6000],dis[1000];
int in[1000],vis[1000];
int tot;
int n,m,s;
void add(int u,int vv,int v)  
{  
    point[++tot]=vv;
	nxt[tot]=had[u];
	had[u]=tot;
	val[tot]=v;  
}  
inline bool spfa(int s)  
{  
    for(int i=1;i<=n;i++) dis[i]=999999999;  
    queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	in[s]=1;  
    while(!q.empty())  
    {  
        int k=q.front();
		q.pop();
		vis[k]=0;  
        if(in[k]>n)  
        {  
            return 1;  
        }  
        for(int j=had[k];j;j=nxt[j])  
          if(dis[point[j]]>val[j]+dis[k])  
          {  
            dis[point[j]]=val[j]+dis[k];  
            if(!vis[point[j]])  
            {  
                q.push(point[j]);vis[point[j]]=1;in[point[j]]++;  
            }  
          }  
    }  
    return 0;
}
int main()
{
	int T;
	scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d%d%d",&n,&m,&s);  
        memset(had,0,sizeof(had));  
        memset(in,0,sizeof(in));  
        memset(vis,0,sizeof(vis));tot=0;  
        for(int i=1;i<=m;i++)  
        {  
    		int s,e,t;
            scanf("%d%d%d",&s,&e,&t);  
            add(s,e,t);add(e,s,t);  
        }  
        for(int i=1;i<=s;i++)  
        {  
        	int s,e,t;
            scanf("%d%d%d",&s,&e,&t);  
            add(s,e,-t);  
        }  
        if(spfa(1))printf("YES\n");
		else printf("NO\n");  
    }  
    return 0;  
}
