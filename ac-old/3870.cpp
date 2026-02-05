#include <cstdio>
int n,ans[24];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2==1){
		printf("-1");
		return 0;
	}
	for(int i=0;i<24;i++) ans[i]=(n>>i)%2;
	for(int i=23;i>=0;i--){
		if(ans[i]==1) printf("%d ",1<<i);
	}
	return 0;
}
