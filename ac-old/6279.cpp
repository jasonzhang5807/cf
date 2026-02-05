#include <cstdio>
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	unsigned long long pow=1;
	scanf("%d %d",&a,&b);
	if(b==0||a==1){
		printf("1");
		return 0;
	}
	if(a>31622&&b>1){
		printf("-1");
		return 0;
	}
	for(int i=0;i<b;i++){
		pow*=a;
		if(pow>10e9){
			printf("-1");
			return 0;
		}
	}
	printf("%d",int(pow));
	return 0;
}
