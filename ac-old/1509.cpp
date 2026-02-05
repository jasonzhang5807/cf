#include <cstdio>
#include <algorithm>
int dp[1010];
int main(){
        int v,k;
        scanf("%d%d",&v,&k);
        for(int i=1;i<=k;i++){
                int ni;
                scanf("%d",&ni);
                int vi[ni+5],ti[ni+5];
                for(int j=0;j<ni;j++) scanf("%d%d",&vi[j],&ti[j]);
                for(int j=v;j>=0;j--){
                        for(int l=0;l<ni;l++){
                                if(j>=vi[l]) dp[j]=std::max(dp[j],dp[j-vi[l]]+ti[l]);
                        }
                }
        }
        printf("%d",dp[v]);
        return 0;
}
