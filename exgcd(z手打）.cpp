//�㷨�����󷽳�x*a+y*b=gcd(a,b)��һ��� 
//����a,b����ʱ��x��a%b����Ԫ 
#include<iostream>
#include<algorithm>
using namespace std;
//�ݹ���̣�
//��Ϊgcd(a,b)=gcd(b,a%b),�� a%b=a-a div b *b
//���Լ��������Ѿ�֪������x1*b+y1*(a%b)=gcd(a,b)�� 
//��ʽ�ɻ�Ϊx1*b+a*y1-(a div b *b)y1=gcd(a,b) 
// ��ʽ����ɵ�y1*a+(x1-y1*a div b )*b=gcd(a,b)
//x=y1,y= (x1-y1*a div b )
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)//��a==0ʱ��gcd(a,b)=b; x=0,y=1
	{		//
		x=1;
		y=0;
		return a;
	}
	else
	{
		int y1=y;
		int x1=x;
		int gcd=exgcd(b,a%b,x,y);//�Ѿ�֪������x1*b+y1*(a%b)=gcd(a,b)
		x1=x;
		x=y;//x=y1
		y=x1-(a/b)*y;//y= (x1-y1*a div b )
		return gcd;
	}
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int gcd=exgcd(a,b,x,y);
	cout<<gcd<<' '<<x<<' '<<y;
	return 0;
}
