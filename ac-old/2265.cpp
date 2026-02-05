#include <cstdio>
int n,v[1010],f[1010],k,x,y;
bool g(int x,int y){
	if(y==0) return 0;
	if(f[y]==x) return 1;
	return g(x,f[y]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&v[i],&f[i]);
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&x,&y);
		if(g(x,y)) printf("%d",x);
		else{
			if(g(y,x)) printf("%d",y);
			else{
				if(g(y,x)) printf("%d",y);
				else printf("-1");
			}
		}
		printf("\n");
	}
	return 0;
}
