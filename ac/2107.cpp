#include <bits/stdc++.h>
using namespace std;
bool f[25010];
int t,n,a[25010];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
        scanf("%d",&t);
        while(t--){
                memset(f,0,sizeof(f));
                memset(a,0,sizeof(a));
                scanf("%d",&n);
                for(int i=0;i<n;++i)scanf("%d",&a[i]);
                sort(a,a+n);
                int ans=0;
                f[0]=1;
                for(int i=0;i<n;++i){
                        if(!f[a[i]]){
                                ++ans;
                                for(int j=0;j<=a[n-1]-a[i];++j)if(f[j])f[a[i]+j]=1;
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}
