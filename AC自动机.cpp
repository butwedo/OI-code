#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
//为什么不会出现多个匹配：其父亲的fail指针所指向的点所连出的边中只会有一个与当前点相同
//http://www.bilibili.com/video/av6295004/   AC自动机视频讲解网址 
//hdu2222
struct trie
{
	int nxt[30];
	int nd;
	int fail;
};
trie ac[500005];
char p[1000005];
char ch[60];
int tot;
inline void add(char* ch)
{
	int len=strlen(ch);
	int r=0;
	for(int i=0;i<len;i++)
	{
		int k=ch[i]-'a';
		if(ac[r].nxt[k]==0)
			ac[r].nxt[k]=++tot;
		r=ac[r].nxt[k];
	}
	ac[r].nd++;
}
inline void find_fail()
{
	queue<int>q;
	int r=0;
	for(int i=0;i<26;i++)
	{
		if(ac[r].nxt[i])q.push(ac[r].nxt[i]);
		ac[ac[r].nxt[i]].fail=0;
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(ac[t].nxt[i])
			{
				ac[ac[t].nxt[i]].fail=ac[ac[t].fail].nxt[i];
				q.push(ac[t].nxt[i]);
			}
			else
				ac[t].nxt[i]=ac[ac[t].fail].nxt[i];
		}
	}
}
inline int askp(char* p)
{
	int len=strlen(p);
	int r=0;
	int ans=0;
	for(int i=0;i<len;i++)
	{
		int k=p[i]-'a';
		while(r&&ac[r].nxt[k]==0)r=ac[r].fail;
		r=ac[r].nxt[k];
		int x=r;
		while(x&&ac[x].nd!=-1)
		{
			ans+=ac[x].nd;
			ac[x].nd=-1;
			x=ac[x].fail;
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		tot=0;
		memset(ac,0,sizeof(ac));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch);
			add(ch);
		}	
		find_fail();
		scanf("%s",p);
		printf("%d\n",askp(p));
	}	
	return 0;
} 
