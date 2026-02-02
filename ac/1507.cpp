#include <cstdio>
#include <algorithm>
int dp[1010];
int main(){
        int v,n;
        scanf("%d%d",&v,&n);
        for(int i=0;i<n;i++){
                int mi,vi,ti;
                scanf("%d%d%d",&mi,&vi,&ti);
                while(mi--){
                        for(int j=v;j>=vi;j--){
                                dp[j]=std::max(dp[j],dp[j-vi]+ti);
                        }
                }
        }
        printf("%d",dp[v]);
        return 0;
}
