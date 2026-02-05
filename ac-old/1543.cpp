#include <cstdio>
#include <algorithm>
int l1,l2,s1[1010],s2[1010],dp[1010][1010];
int main(){
        scanf("%d%d",&l1,&l2);
        for(int i=1;i<=l1;i++)scanf("%d",&s1[i]);
        for(int i=1;i<=l2;i++)scanf("%d",&s2[i]);
        for(int i=1;i<=l1;i++){
                for(int j=1;j<=l2;j++){
                        if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
                        else dp[i][j]=std::max(std::max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
                }
        }
        int ans=-1;
        for(int i=0;i<=l1;i++){
                for(int j=0;j<=l2;j++){
                        //printf("%d\t",dp[i][j]);
                        ans=std::max(ans,dp[i][j]);
                }
                //putchar('\n');
        }
        printf("%d",ans);
        return 0;
}
