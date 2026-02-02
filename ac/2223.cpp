#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int n,m,a[maxn],l2[maxn],f[maxn][20];
int main(){
	#ifdef local
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=2;i<=n;++i)l2[i]=l2[i>>1]+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[i][0]=a[i];
	for(int j=1;j<=l2[n];++j)for(int i=1;i+(1<<j)-1<=n;++i)f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for(int i=1,x,y,k;i<=m;++i){
		scanf("%d%d",&x,&y);
		k=l2[y-x+1];
		printf("%d\n",max(f[x][k],f[y-(1<<k)+1][k]));
	}
	return 0;
}
