#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int big=100000;
int vis[big];
int prime[big];
int mu[big];
int cnt;
int main()  
{  
    memset(vis,0,sizeof(vis));  
    mu[1] = 1;  
    cnt = 0;  
    int N;
    cin>>N;
    for(int i=2; i<N; i++)  
    {  
        if(!vis[i])  
        {  
            prime[cnt++] = i;  
            mu[i] = -1;  //素数莫比乌斯函数值一定为-1 
        }  
        for(int j=0; j<cnt&&i*prime[j]<N; j++)  
        {  
            vis[i*prime[j]] = 1;  
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];  //若i%prime[j]不为0即说明i中无此素因子 
            else  									//则若mu[i]!=0,i*prime[j]后奇偶性改变 
            {  
                mu[i*prime[j]] = 0;  //若i可被prime[j]整除则i*prime[j]可构成平方因子 
                break;  
            }  
        }  
    }  
    for(int i=1;i<N;i++)
    {
    	cout<<mu[i]<<' ';
	}
	return 0;
}  
