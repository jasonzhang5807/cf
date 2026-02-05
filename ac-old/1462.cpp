#include <cstdio>
int f(int n){
	if(n==1||n==2) return 1;
	else return f(n-1)+f(n-2);
}
int main(){
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		printf("%d\n",f(a));
	}
	return 0;
}
