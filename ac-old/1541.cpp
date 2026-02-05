#include <cstdio>
#include <algorithm>
#include <cstring>
int dp[100110],l,s,t,n;
bool sz[100010];
int main(){
        //memset(dp,0x3f,sizeof(dp));
        scanf("%d%d%d%d",&l,&s,&t,&n);
        while(n--){
                int tmp;
                scanf("%d",&tmp);
                sz[tmp]=true;
        }
        //for(int i=l;i<l+t;i++)dp[i]=0;
        for(int i=l;i>=0;i--){
                int tmp=0x3f3f3f3f;
                for(int j=i+s;j<=i+t;j++)tmp=std::min(tmp,dp[j]);
                dp[i]=tmp+(sz[i]?1:0);
        }
        printf("%d",dp[0]);
        return 0;
}
