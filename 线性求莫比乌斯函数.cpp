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
            mu[i] = -1;  //����Ī����˹����ֵһ��Ϊ-1 
        }  
        for(int j=0; j<cnt&&i*prime[j]<N; j++)  
        {  
            vis[i*prime[j]] = 1;  
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];  //��i%prime[j]��Ϊ0��˵��i���޴������� 
            else  									//����mu[i]!=0,i*prime[j]����ż�Ըı� 
            {  
                mu[i*prime[j]] = 0;  //��i�ɱ�prime[j]������i*prime[j]�ɹ���ƽ������ 
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
