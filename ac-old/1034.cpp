#include <cstdio>
using namespace std;
bool divid(int a,int b){
	return a%b==0;
}
int main(){
	freopen("pencil.in","r",stdin);
	freopen("pencil.out","w",stdout);
	int n,p1,p2,p3,n1,n2,n3,m2,m3;
	scanf("%d",&n);
	scanf("%d %d",&n1,&p1);
	scanf("%d %d",&n2,&p2);
	scanf("%d %d",&n3,&p3);
	int money=(n/n1+1)*p1;
	if(divid(n,n1)){
		money=n/n1*p1;
	}
	m2=(n/n2+1)*p2;
	if(divid(n,n2)){
		m2=n/n2*p2;
	}
	if(m2<money){
		money=m2;
	}
	m3=(n/n3+1)*p3;
	if(divid(n,n3)){
		m3=n/n3*p3;
	}
	if(m3<money){
		money=m3;
	}
	printf("%d",money);
	return 0;
}
