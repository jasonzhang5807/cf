#include <cstdio>
#include <algorithm>
#include <cstring>
int dp[17][1<<17],n,k,map[20][20];
int main(){
        memset(dp,0x3f,sizeof(dp));
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&map[i][j]);
        for(int i=0;i<n;i++)dp[i+1][1<<i]=k;
        for(int s=1;s<1<<n;s++){
                for(int i=1;i<=n;i++){
                        if(s&(1<<i-1)){
                                int t=dp[i][s];
                                for(int j=1;j<=n;j++)
                                        if((s&(1<<j-1))&&i!=j)
                                                t=std::min(t,dp[j][s^(1<<i-1)]+map[j][i]);
                                dp[i][s]=t;
                        }
                }
        }
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++)ans=std::min(ans,dp[i][(1<<n)-1]);
        printf("%d",ans);
        return 0;
}
