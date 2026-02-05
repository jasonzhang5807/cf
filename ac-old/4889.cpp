#include <cstdio>
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	int tmp=l-l%n+n-1;
	if(tmp>r){
		tmp=r;
	}
	int ans=tmp%n;
	printf("%d",ans);
	return 0;
}
