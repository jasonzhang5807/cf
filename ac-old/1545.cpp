#include <cstdio>
#include <algorithm>
#include <cstring>
int dp[1010][1010];
char s1[1010],s2[1010];
int main(){
        scanf("%s",s1+1);
        s1[0]='?',s2[0]='%';
        for(int i=1;i<strlen(s1);i++)s2[i]=s1[strlen(s1)-i];
        for(int i=1;i<strlen(s1);i++){
                for(int j=1;j<strlen(s2);j++){
                        if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
                        else dp[i][j]=std::max(std::max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
                }
        }
        int ans=-1;
        for(int i=0;i<strlen(s1);i++){
                for(int j=0;j<strlen(s2);j++){
                        //printf("%d\t",dp[i][j]);
                        ans=std::max(ans,dp[i][j]);
                }
                //putchar('\n');
        }
        printf("%ld",strlen(s1)-1-ans);
        return 0;
}
