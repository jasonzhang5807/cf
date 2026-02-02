#include <cstdio>
int fib[31],t;
void f(int a,int b){
	t++;
	fib[t]=b;
	if(b>1346269) return;
	else f(b,a+b);
}
int main(){
	fib[0]=1;
	f(1,1);
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		printf("%d\n",fib[a]);
	}
	return 0;
}
