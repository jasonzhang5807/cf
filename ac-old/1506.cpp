#include <cstdio>
#include <algorithm>
int v,n,vi,ti,dp[1010];
int main(){
        scanf("%d%d",&v,&n);
        for(int j=0;j<n;j++){
                scanf("%d%d",&vi,&ti);
                for(int i=vi;i<=v;i++) dp[i]=std::max(dp[i],dp[i-vi]+ti);
        }
        int ans=0;
        for(int i=0;i<=v;i++) ans=std::max(ans,dp[i]);
        printf("%d",ans);
        return 0;
}
