#include<iostream>
using namespace std;
struct line
  {
  	line* l;
  	line* r;
  	int num;
  };
line* node[2000100];
int main()
  {
  	freopen("i.in","r",stdin); 
  	int n;
  	line* head;
  	cin>>n;
  	node[0]=new line;
  	for(int i=1;i<=n;i++)
  	  {
  	  	int a;
  	  	cin>>a;
  	  	node[i]=new line;
  	  	node[i]->num=a;
  	  	node[i]->l=node[i-1];
  	  	node[i-1]->r=node[i];
	  }
	line* p;
	node[n+1]=new line;
	node[n]->r=node[n+1];
	node[n+1]->l=node[n];
	head=node[0];
	p=head;
	int m;
	cin>>m;
	while(p!=node[n+1])
	  {
	  	if(p->num==m) 
		  {
		    p->l->r=p->r;
		    p->r->l=p->l;
	      }
	  	p=p->r;
	  }
	p=head;
	while(p!=node[n+1])
	  {
	  	if(p!=head)cout<<p->num<<' ';
	  	p=p->r;
	  }
	return 0;
  }
