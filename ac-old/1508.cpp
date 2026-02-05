#include <cstdio>
#include <algorithm>
long long dp[10010];
int main(){
        long long v,m,ti,vi,mi;
        scanf("%lld%lld",&v,&m);
        while(m--){
                scanf("%lld%lld%lld",&mi,&vi,&ti);
                if(mi==1) for(long long j=v;j>=vi;--j) dp[j]=std::max(dp[j],dp[j-vi]+ti);
                else if(mi*vi>v) for(long long j=vi;j<=v;j++) dp[j]=std::max(dp[j],dp[j-vi]+ti);
                else{
                        long long k=1;
                        while(k<mi){
                                for(long long j=v;j>=k*vi;--j) dp[j]=std::max(dp[j],dp[j-k*vi]+k*ti);
                                mi-=k;k*=2;
                        }
                        for(long long j=v;j>=mi*vi;--j) dp[j]=std::max(dp[j],dp[j-mi*vi]+mi*ti);
                }
        }
        printf("%lld",dp[v]);
        return 0;
}
