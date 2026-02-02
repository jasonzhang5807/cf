#include <bits/stdc++.h>
#define maxn 1010
#define local
#undef local
using namespace std;
int a,b,n,gn,l2[maxn],f[maxn][maxn][11],f2[maxn][maxn][11];
int main(){
	memset(f2,0x3f,sizeof(f2));
	#ifdef local
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	#endif
	cin>>a>>b>>gn;
	n=max(a,b);
	for(int i=2;i<=n;++i)l2[i]=l2[i>>1]+1;
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			scanf("%d",&f[i][j][0]),f2[i][j][0]=f[i][j][0];
	for(int k=1;k<=l2[n];++k)
		for(int i=1;i+(1<<k)-1<=a;++i)
			for(int j=1;j+(1<<k)-1<=b;++j){
				f[i][j][k]=max({f[i][j][k-1],
					f[i+(1<<k-1)][j][k-1],
					f[i][j+(1<<k-1)][k-1],
					f[i+(1<<k-1)][j+(1<<k-1)][k-1]
				});
				f2[i][j][k]=min({
					f2[i][j][k-1],
					f2[i+(1<<k-1)][j][k-1],
					f2[i][j+(1<<k-1)][k-1],
					f2[i+(1<<k-1)][j+(1<<k-1)][k-1]
				});
			}
	int ans=0x7fffffff;
	for(int x=1;x+gn<=a+1;x++){
		for(int y=1;y+gn<=b+1;y++){
			int k=l2[gn];
			int ansmin=min({
				f2[x][y][k],
				f2[x+gn-(1<<k)][y][k],
				f2[x][y+gn-(1<<k)][k],
				f2[x+gn-(1<<k)][y+gn-(1<<k)][k]
			});
			int ansmax=max({
				f[x][y][k],
				f[x+gn-(1<<k)][y][k],
				f[x][y+gn-(1<<k)][k],
				f[x+gn-(1<<k)][y+gn-(1<<k)][k]
			});
			ans=min(ans,ansmax-ansmin);
		}
	}
	cout<<ans<<endl;
	return 0;
}
