#include <cstdio>
long long fact(long long n){
	if(n==1) return 1;
	else return n*fact(n-1);
}
int main(){
	long long ipt;
	scanf("%lld",&ipt);
	printf("%lld",fact(ipt)%1007);
	return 0;
}
