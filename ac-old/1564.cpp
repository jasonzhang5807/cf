#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
int main(){
        int n;
        scanf("%d",&n);
        int map[n+5][n+5],dp[n+5][(1<<n)+5],ans=INT_MAX;
        memset(dp,0x7f,sizeof(dp));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&map[i][j]);
        dp[1][0]=0;
        for(int s=0;s<1<<n;s++)
                for(int i=0;i<n;i++)
                        if(s&1<<n-1-i)
                                for(int j=0;j<n;j++)dp[i][s]=std::min(dp[i][s],dp[j][s^(1<<n-1-i)]+map[j][i]);
        //for(int i=0;i<=n;i++){
        //      for(int j=0;j<(1<<n);j++) printf("%3d\t",dp[i][j]==0x7f7f7f7f?-1:dp[i][j]);
        //      putchar('\n');
        //}
        for(int i=0;i<n;i++)ans=std::min(ans,dp[i][(1<<n)-1]+map[i][1]);
        printf("%d",ans);
        return 0;
}
