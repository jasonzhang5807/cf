#include <cstdio>
#include <algorithm>
long long dp[1010];
int main(){
        long long v,m,ti,vi,mi;
        scanf("%lld%lld",&v,&m);
        while(m--){
                scanf("%lld%lld%lld",&mi,&vi,&ti);
                if(mi==0) for(long long j=v;j>=vi;--j) dp[j]=std::max(dp[j],dp[j-vi]+ti);
                else for(long long j=vi;j<=v;j++) dp[j]=std::max(dp[j],dp[j-vi]+ti);
        }
        printf("%lld",dp[v]);
        return 0;
}
