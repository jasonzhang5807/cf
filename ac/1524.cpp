#include <cstdio>
#include <algorithm>
int dp[1010];
int main(){
        int t,m,ti,vi;
        scanf("%d%d",&t,&m);
        while(m--){
                scanf("%d%d",&ti,&vi);
                for(int j=t;j>=ti;--j) dp[j]=std::max(dp[j],dp[j-ti]+vi);
        }
        printf("%d",dp[t]);
        return 0;
}
