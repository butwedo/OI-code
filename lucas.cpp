#include <iostream>
#include <cstdio>
//hdu 3037
//�Դ���ȡģ��Lucas����C(n,m)%p=C(n%p,m%p)*C(n/p,m/p)%p      pΪ����
//���� C(n/p,m/p)�ɵݹ������ȥ 
typedef long long lld;
lld N,M,P;
//�ɷ���С����ɵ� a^(p-1)=1(mod p)     pΪ����
//��� a����p����ԪΪ a^(p-2)���ÿ�������� 
int Pow(lld a,lld n,lld p)
{
	lld x=a;
	lld res=1;
	while(n)
	{
		if(n&1)
			res=((lld)res*(lld)x)%p;
		n>>=1;
		x=((lld)x*(lld)x)%p;
	}
	return res;
}
//C(n,m)=n!/(m!*(n-m)��)=n*(n-1)*...*(m+1)/m! 
int Cm(lld n,lld m,lld p)
{
	lld a=1,b=1;
	if(m>n) return 0;
	while(m)
	{
		a=(a*n)%p;
		b=(b*m)%p;
		m--;
		n--;
	}
	return ((lld)a*(lld)Pow(b,p-2,p))%p;
}
int Lucas(lld n,lld m,lld p)
{
	if(m==0)
		return 1;
	return((lld)Cm(n%p,m%p,p)*(lld)Lucas(n/p,m/p,p))%p;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&N,&M,&P);
		printf("%d\n",Lucas(N+M,M,P));
	}
	return 0;
}

